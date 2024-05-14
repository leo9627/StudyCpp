#pragma once

namespace leo
{
	template<class T>
	struct __list_Node
	{
		T _data;
		__list_Node* _next;
		__list_Node* _prev;
		__list_Node(const T& t = T())
			:_data(t)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};
	template<class T,class Ref,class Ptr>
	class _list_iterator
	{
		typedef __list_Node<T> Node;
	public:
		Node* _p;
		_list_iterator(__list_Node<T>* p):_p(p){}
		_list_iterator(const _list_iterator& t1) 
		{
			_p = t1._p;
		};
		_list_iterator& operator++()
		{
			_p = _p->_next;
			return *this;
		}
		_list_iterator operator++(int)
		{
			__list_Node<T>* temp = _p;
			_p = _p->_next;
			return temp;
		}
		_list_iterator& operator--()
		{
			_p = _p->_prev;
			return *this;
		}
		_list_iterator operator--(int)
		{
			Node* temp = _p;
			_p = _p->_prev;
			return temp;
		}
		bool operator==(const _list_iterator& it)const
		{
			return _p == it._p;
		}
		bool operator!=(const _list_iterator& it) const
		{
			return _p != it._p;
		}
		Ptr operator->()
		{
			return &(_p->_data);
		}
		Ref operator*()
		{
			return _p->_data;
		}
		~_list_iterator() {

		}
	};

	template<class T,class Ref,class Ptr>
	class reverse_iterator_leo
	{
		typedef __list_Node<T> Node;
		typedef reverse_iterator_leo<T, Ref ,Ptr> Self;
	public:
		Node* _p;
		reverse_iterator_leo<T, Ref, Ptr>(Node* p):_p(p)
		{}
		Self& operator++()
		{
			_p = _p->_prev;
			return *this;
		}
		Self operator++(int)
		{
			Self temp = *this;
			++*this;
			return temp;
		}
		Self& operator--()
		{
			_p = _p->_next;
			return *this;
		}
		Self operator--(int)
		{
			Self temp = *this;
			++*this;
			return temp;
		}
		Ref operator*()
		{
			return _p->_data;
		}
		Ptr operator->()
		{
			return &(_p->_data);
		}
		bool operator!=(const Self& s)const
		{
			return _p != s._p;
		}

	};
	template<class T>
	class list
	{
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		typedef reverse_iterator_leo<T, T&, T*> reverse_iterator;
		typedef reverse_iterator_leo<T, const T&, const T*>  const_reverse_iterator;
		typedef __list_Node<T> Node;
		
	private:
		Node* _head;
	public:
		//typedef reverse_iterator<T, const T&, const T*>  const_reverse_iterator;
		



		list<T>() :_head(nullptr)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		template<class InputIterator>
		list<T>(InputIterator first, InputIterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list<T>(const list& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (auto& e : l)
			{
				push_back(e);
			}
		}
		list<T>& operator=(list<T> lt)
		{
			::swap(_head, lt._head);
			return *this;
		}
		iterator begin()
		{
			iterator it = iterator(_head->_next);
			return it;
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		iterator end()
		{
			return iterator(_head);
		}
		reverse_iterator rbegin()
		{
			reverse_iterator it = reverse_iterator(_head->_prev);
			return it;
		}
		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(_head->_prev);
		}
		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(_head);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(_head);
		}

		void push_back(const T& t )
		{
			Node* ptail = _head->_prev;
			Node* newnode = new Node(t);
			newnode->_next = _head;
			newnode->_prev = ptail;
			ptail->_next = newnode;
			_head->_prev = newnode;
		}
		/*void pop_back()
		{
			if (_head == _head->_next)
				return;
			Node* ptail = _head->_prev->_prev;
			delete _head->_prev;
			ptail->_next = _head;
			_head->_prev = ptail;
		}*/
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(const iterator& pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._p;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(const iterator& pos)
		{
			if (pos == end())
				return pos;
			Node* cur = pos._p;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(next);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);  //µü´úÆ÷Ê§Ð§
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	};
}