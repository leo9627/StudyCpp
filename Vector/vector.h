#pragma once
#include<iostream>
#include<cassert>
#include<vector>


namespace leo
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector() :_start(nullptr), _finish(nullptr), _end_storage(nullptr)
		{}
	/*	vector(const vector<T>& v)
		{
			_finish=_start = new T[v.capacity()];
			_end_storage = _start + v.capacity();
			for (size_t i = 0; i < v.size(); i++)
			{
				*_finish = v._start[i];
				++_finish;
			}
		}*/
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_storage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
				push_back(e);

		}
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin() const{ return _start; }
		const_iterator end()const { return _finish; }
		void reserve(size_t n)
		{
			if (n >= size())
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start)
				{
					memcpy(temp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = temp;
				_finish = _start + sz;
				_end_storage = _start + n;
			}
		}
		void resize(size_t n, const T & x= T())
		{
			if (n <= size())
				_finish = _start + n;
			else
			{
				if (n > capacity())
					reserve(n);
				while (_finish != _start + n)
				{
					*_finish = x;
					++_finish;
				}
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _end_storage)
			{
				reserve(capacity() == 0 ? 2 : capacity() * 2);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}
		iterator erase(iterator it)
		{
			assert(it >= _start && it < _finish);
			iterator begin = it + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
				
			_finish--;
			return it;
		}
		iterator insert(iterator pos,const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_storage)
			{
				size_t d = pos - _start;
				reserve(capacity() == 0 ? 2 : capacity() * 2);
				pos = _start + d;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_storage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_storage;
	};
}
//template<class T>
//class vector
//{
//private:
//	T* _arr;
//	size_t _size;
//	size_t _capacity;
//public:
//	vector() :_arr(nullptr), _size(0), _capacity(0) {}
//	vector(size_t n);
//	void Push_Back(const T& x);
//	void Pop_Back();
//	size_t size();
//	T& operator[](size_t x);
//	~vector();
//};
//
//template<class T>
//vector<T>::vector(size_t n)
//{
//	_arr = new T[n];
//	_size = 0;
//	_capacity = n;
//}
//template<class T>
//void vector<T>::Push_Back(const T& x)
//{
//	if (_size == _capacity)
//	{
//		size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
//		T* temp = new T[newcapacity];
//		if (_size)
//		{
//			memcpy(temp, _arr, sizeof(T) * _size);
//			delete[] _arr;
//		}
//		_capacity = newcapacity;
//		_arr = temp;
//	}
//	_arr[_size++] = x;
//}
//template<class T>
//void vector<T>::Pop_Back()
//{
//	assert(_size > 0);
//	--_size;
//}
//template<class T>
//size_t vector<T>::size()
//{
//	return _size;
//}
//template<class T>
//T& vector<T>::operator[](size_t x)
//{
//	assert(x >= 0 && x < _size);
//	return _arr[x];
//}
//template<class T>
//vector<T>::~vector()
//{
//	delete[] _arr;
//	_size = 0;
//	_capacity = 0;
//}