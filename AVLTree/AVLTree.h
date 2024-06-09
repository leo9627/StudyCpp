#pragma once
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTNode
{
	AVLTNode<K, V>* _left;
	AVLTNode<K, V>* _right;
	AVLTNode<K, V>* _parent;

	int _bf;
	pair<K,V> _data;
	AVLTNode(const pair<K,V>& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		,_data(data)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& data)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_data.first < data.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data.first > data.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		Node* newNode = new Node(data);
		if (parent == nullptr)
			_root = newNode;
		else
		{
			if (parent->_data.first < data.first)
			{
				parent->_right = newNode;
				newNode->_parent = parent;
			}
			else
			{
				parent->_left = newNode;
				newNode->_parent = parent;
			}
		}
		//处理平衡因子
		cur = newNode;
		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;


			if (parent == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else  //parent的平衡因子变成2
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if(cur->_bf==-1)
					{
						RotateRL(parent);
					}
				}
				else if(parent->_bf==-2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				break;
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
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
		int left = Height(root->_left);
		int right = Height(root->_right);
		return abs(left - right) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		subR->_left = parent;
		if (subRL)
			subRL->_parent = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		if (subLR)
			subLR->_parent = parent;
		parent->_left = subLR;
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
			
		else
		{

			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;

		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
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
	Node* _root=nullptr;
};