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
			, _prev(nullptr)
		{}
	};
	template<class T>
	class list
	{
		typedef __list_Node Node
	private:
		Node* _head;
	public:
		list() :_head(nullptr)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	};
}