#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	BLACK,
	RED,
};

template<class T>
struct RBTNode
{
	RBTNode<T>* _left;
	RBTNode<T>* _right;
	RBTNode<T>* _parent;

	Colour _colour;
	T _data;
	RBTNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
	{}
};

template<class T,class Ref,class Ptr>
class RBTree_iterator
{
	typedef RBTNode<T> Node;
	//typedef RBTree_iterator Self;
	typedef RBTree_iterator<T, T&, T*> Self;
public:
	RBTree_iterator(Node* root)
		:_root(root)
	{}
	Self& operator++()
	{
		if (_root->_right)
		{
			_root = _root->_right;
			while (_root->_left)
				_root = _root->_left;
		}
		else
		{
			Node* cur = _root;
			Node* parent = _root->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_root = parent;
		}
		return *this;
	}
	Self& operator--()
	{

		return *this;
	}
	bool operator!=(Self& p)
	{
		return _root != p._root;
	}
	Ref operator*()
	{
		return _root->_data;
	}
	Ptr operator->()
	{
		return &_root->_data;
	}

private:
	Node* _root;
};
template<class K,class T,class KEYOFT>
class RBTree
{
public:
	typedef RBTNode<T> Node;
	typedef RBTree_iterator<T, T&, T*> iterator;
public:
	pair<iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_colour = BLACK;
			return make_pair(iterator(_root),true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		KEYOFT keyoft;
		while (cur)
		{
			if (keyoft(cur->_data) < keyoft(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (keyoft(cur->_data) > keyoft(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur),false);
			}
		}
		cur = new Node(data);
		if (keyoft(parent->_data) < keyoft(data))
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_parent = parent;
		cur->_colour = RED;
		iterator ret = iterator(cur);

		while (parent && parent->_colour == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle&&uncle->_colour == RED)
				{
					parent->_colour = BLACK;
					uncle->_colour = BLACK;
					grandfather->_colour = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					
					if (cur == parent->_right)  //×óÐý
					{
						RotateL(parent);
						swap(parent, cur);
					}
					RotateR(grandfather);
					//±äÉ«
					parent->_colour = BLACK;
					grandfather->_colour = RED;
					break;
				}

			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle&&uncle->_colour == RED)
				{
					uncle->_colour = BLACK;
					parent->_colour = BLACK;
					grandfather->_colour = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);
					grandfather->_colour = RED;
					cur->_colour = RED;
					parent->_colour = BLACK;
					break;
				}
			}
		}
		_root->_colour = BLACK;
		return make_pair(ret,true);
	}
	iterator begin()
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_data.first > key)
				cur = cur->_left;
			else
				return true;
		}
		return false;
	}
private:
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int min = MinHeight(root);
		int max = MaxHeight(root);
		if (max <= min * 2)
			return true;
		else
			return false;
	}
	int MinHeight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = MinHeight(root->_left);
		int right = MinHeight(root->_right);
		return left < right ? left + 1 : right + 1;
	}
	int MaxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = MaxHeight(root->_left);
		int right = MaxHeight(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppNode = parent->_parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;
		subL->_parent = ppNode;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
		}
		
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppNode = parent->_parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;
		subR->_parent = ppNode;
		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_data.first << ":" << root->_data.second << endl;
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};