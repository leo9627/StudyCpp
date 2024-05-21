#pragma once


namespace leo
{

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T,class Container=vector<T>,class Compare=less<typename Container::value_type>>
	class priority_queue
	{
	private:
		Container _con;
		Compare com;
	public:
		void AdjustUp(int chil)
		{
			int parent = (chil - 1) / 2;
			while (chil > 0)
			{
				//if (_con[chil] > _con[parent])
				if(com(_con[parent],_con[chil]))
				{
					swap(_con[chil], _con[parent]);
					chil = parent;
					parent = (chil - 1) / 2;
				}
				else
					break;
			}
		}
		void AdjustDown(int root)
		{
			int parent = root;
			int chil = parent * 2 + 1;
			while (chil < size())
			{
				if (chil + 1 < size() && com(_con[chil] , _con[chil+1]))//less  <
					++chil;
				//if (_con[chil] > _con[parent])
				if(com(_con[parent],_con[chil]))
				{
					swap(_con[chil], _con[parent]);
					parent = chil;
					chil = parent * 2 + 1;
				}	
				else
					break;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(size() - 1);
		}
		void pop()
		{
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		T top()
		{
			return _con.front();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	};
}