#pragma once
#include<iostream>
using namespace std;

//template<class K,class V>
//struct BSTNode
//{
//	BSTNode<K,V>* _left;
//	BSTNode<K,V>* _right;
//	K _key;
//	V _value;
//	BSTNode(const K& x,const V& y)
//		:_key(x)
//		,_value(y)
//		,_left(nullptr)
//		,_right(nullptr)
//	{}
//};
//template<class K,class V>
//class BSTree
//{
//	typedef BSTNode<K,V> Node;
//public:
//	bool Insert(const K& key,const V& value)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key,value);
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key >key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		if (parent->_key < key)
//		{
//			parent->_right = new Node(key,value);
//		}
//		else
//		{
//			parent->_left = new Node(key,value);
//		}
//		return true;
//	}
//	Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//				cur = cur->_right;
//			else if (cur->_key > key)
//				cur = cur->_left;
//			else
//				return cur;
//		}
//		return nullptr;
//	}
//
//	bool Erase(const K& key)
//	{
//		Node* cur = _root;
//		Node* parent - nullptr;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur=cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			if (cur->_key == key)
//			{
//				if (cur->_left == nullptr)
//				{
//					if (_root == cur)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_right;
//						else
//							parent->_right = cur->_right;
//					}
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (_root == cur)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_left;
//						else
//							parent->_right = cur->_left;
//					}
//					delete cur;
//				}
//				else
//				{
//					Node* rightmin = cur->_right;
//					parent = cur;
//					while (rightmin->_left)
//					{
//						rightmin = rightmin->_left;
//					}
//					swap(cur->_value, rightmin->_value);
//					if (parent == cur)
//					{
//						parent->_right = cur->_right;
//					}
//					else
//					{
//						parent->_left = cur->_right;
//					}
//					delete cur;
//				}
//
//
//				return true;
//			}
//
//		}
//		return false;
//	}
//	/*bool Erase(const K& key)
//	{
//		if (_root == nullptr)
//			return false;
//		if (_root->_key == key&&(_root->_left==nullptr||_root->_right==nullptr))
//		{
//			if (_root->_left == nullptr)
//			{
//				Node* temp = _root->_right;
//				delete _root;
//				_root = temp;
//			}
//			else
//			{
//				Node* temp = _root->_left;
//				delete _root;
//				_root = temp;
//			}
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				if (cur->_left == nullptr)
//				{
//					if (parent->_left == cur)
//						parent->_left = cur->_right;
//					else
//						parent->_right = cur->_right;
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (parent->_left == cur)
//						parent->_left = cur->_left;
//					else
//						parent->_right = cur->_left;
//					delete cur;
//				}
//				else
//				{
//
//					Node* submin = cur->_right;
//					parent = nullptr;
//
//					if (submin->_left == nullptr)
//					{
//						cur->_key = submin->_key;
//						cur->_right = submin->_right;
//					}
//					else
//					{
//						while (submin->_left)
//						{
//							parent = submin;
//							submin = submin->_left;
//						}
//						cur->_key = submin->_key;
//						parent->_left = submin->_right;
//					}
//					delete submin;
//				}
//				return true;
//			}
//		}
//		return false;
//	}*/
//	void InOrder()
//	{
//		_InOreder(_root);
//		cout << endl;
//	}
//private:
//	void _InOreder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		_InOreder(root->_left);
//		cout << root->_key << " "<<root->_value<<endl;
//		_InOreder(root->_right);
//	}
//private:
//	Node* _root = nullptr;
//};
template<class K>
struct BSTNode
{
	BSTNode<K>* _left;
	BSTNode<K>* _right;
	K _key;
	BSTNode(const K& x)
		:_key(x)
		, _left(nullptr)
		, _right(nullptr)
	{}
};
template<class K>
//typedef int K;
class BSTree
{
	typedef BSTNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		else
		{
			parent->_left = new Node(key);
		}
		return true;
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return true;
		}
		return false;
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (_root == cur)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (_root == cur)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				else
				{
					Node* rightmin = cur->_right;
					parent = cur;
					while (rightmin->_left)
					{
						parent = rightmin;
						rightmin = rightmin->_left;
					}
					swap(cur->_key, rightmin->_key);
					if (parent == cur)
					{
						parent->_right = rightmin->_right;
					}
					else
					{
						parent->_left = rightmin->_right;
					}
					delete rightmin;
				}


				return true;
			}

		}
		return false;
	}
	void InOrder()
	{
		_InOreder(_root);
		cout << endl;
	}
private:
	void _InOreder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOreder(root->_left);
		cout << root->_key << " " ;
		_InOreder(root->_right);
	}
private:
	Node* _root = nullptr;
};