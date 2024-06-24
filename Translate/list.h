#pragma once
#include<string>

struct Node
{
	std::string _data;
	Node* _next;
	Node(std::string s="")
	{
		_data = s;
		_next = nullptr;
	}
};
class iterator
{
private:
	Node* _p;
public:
	iterator(Node* x)
		:_p(x)
	{}
	iterator operator++()
	{
		_p = _p->_next;
		return *this;
	}
	std::string& operator*()
	{
		return _p->_data;
	}
	bool operator!=(iterator& it)
	{
		return _p != it._p;
	}
};
class list
{
private:
	Node* _head;
	Node* _ptail;
public:

	list()
	{
		_ptail=_head = new Node;
		
	}
	void push_back(std::string s)
	{
		Node* _newnode = new Node(s);
		_ptail->_next = _newnode;
		_ptail = _newnode;
	}
	::iterator begin()
	{
		return ::iterator(_head->_next);
	}
	::iterator end()
	{
		return ::iterator(nullptr);
	}
	~list()
	{
		while (_head)
		{
			Node* temp = _head->_next;
			delete _head;
			_head = temp;
		}
		_ptail = nullptr;
	}
};