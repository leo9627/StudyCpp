#pragma once

namespace leo
{
	template<class T,class Contianer=vector<T>>
	class stack
	{
	private:
		Contianer con;
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_back();
		}
		T& top()
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