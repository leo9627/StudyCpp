#pragma once

namespace leo
{
	template<class T,class Container>
	class queue
	{
	private:
		Container con;
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_front();
		}
		T& front()
		{
			return con.front();
		}
		T& back()
		{
			return con.back();
		}
		size_t size()
		{
			return con.size();
		}
		bool empty()
		{
			return !con.size();
		}
	};
}