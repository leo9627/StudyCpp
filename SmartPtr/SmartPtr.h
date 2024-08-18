#pragma once
#include<iostream>
#include<mutex>
using namespace std;



template<class T>
class SmartPtr
{
	typedef SmartPtr<T> Self;
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~SmartPtr()
	{
		if (_ptr)
		{
			cout << _ptr << endl;
			delete _ptr;
		}
			
		_ptr = nullptr;
	}
private:
	T* _ptr;
};

namespace leo
{
	template<class T>
	class auto_ptr
	{
		typedef auto_ptr<T> Self;
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		auto_ptr(Self& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		Self& operator=(Self& ap)
		{
			this->~auto_ptr();
			_ptr = ap._ptr;
			ap._ptr = nullptr;
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		~auto_ptr()
		{
			if (_ptr)
			{
				cout << _ptr << endl;
				delete _ptr;
			}

			_ptr = nullptr;
		}
	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
		typedef unique_ptr<T> Self;
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		unique_ptr(Self& up) = delete;
		Self& operator=(Self& up) = delete;
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		~unique_ptr()
		{
			if (_ptr)
			{
				cout << _ptr << endl;
				delete _ptr;
			}

			_ptr = nullptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class weak_ptr;

	template<class T>
	class shared_ptr
	{
		friend class weak_ptr<T>;
		typedef shared_ptr<T> Self;
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
		{
			_del = [](T* p) { delete p; };
		}


		template<class Func>
		shared_ptr(T* ptr=nullptr,Func Del= [](T* p) { delete p;})
			:_ptr(ptr)
			,_pcount(new int(1))
			,_pmutex(new mutex)
			,_del(Del)
		{}
		shared_ptr(Self& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			,_pmutex(sp._pmutex)
		{
			_pmutex->lock();
			++(*_pcount);
			_pmutex->unlock();
		}
		Self& operator=(Self& sp)
		{
			if (this != &sp)
			{
				_pmutex = sp._pmutex;
				this->~shared_ptr();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmutex->lock();
				++(*_pcount);
				_pmutex->unlock();
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		~shared_ptr()
		{
			_pmutex->lock();
			if (--(*_pcount) == 0)
			{
				cout << _ptr << endl;
				if (_ptr)
				{
					_del(_ptr);
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
			}
			_pmutex->unlock();
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
		function<void(T*)> _del;
	};

	template<class T>
	class weak_ptr
	{
	public:

		weak_ptr() = default;
		weak_ptr(const shared_ptr<T>& spt)
		{
			_ptr = spt._ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr=nullptr;
	};

	template<class LOCK>
	class lock_guard
	{
	public:
		explicit lock_guard(LOCK& lock)
			:_lock(lock)
		{
			_lock.lock();
		}
		~lock_guard()
		{
			cout << "½âËø" << endl;
			_lock.unlock();
		}

	private:
		LOCK& _lock;
	};
}