#pragma once
#include<vector>

namespace leo
{

	enum STATUS
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class T>
	struct HashNode
	{
		T _data;
		STATUS _status;
		HashNode(const T& data)
			:_data(data)
			,_status(EXITS)
		{}
	};
	template<class K,class T,class KOFT>
	class Hash
	{
		typedef HashNode<T> HashNode;
	public:
		bool Insert(const T& data)
		{
			//负载因子设为0.7
			if (_nums * 10 / _tables.size() >= 7)
			{
				//增容
			}
			KOFT koft;

			size_t index = koft(data) % _tables.size();
			if (_tables[index]._status ==EXITS)
			{
				if (_tables[index]._data == data)
				{
					return false;
				}
				else
				{
					while (_tables[index]._status == EXITS)
					{
						++index;
						if (index == _tables.size())
							index = 0;
					}
					_tables[index] = HashNode(data);
				}
			}
			else
			{

				_tables[index] = HashNode(data);
			}
		}
		HashNode* Find(const K& key)
		{
			KOFT koft;
			size_t index = key % _tables.size();
			while (_tables[index]._status != EMPTY)
			{
				if (_tables[index]._status == EXITS && koft(_tables[index]._data) == key)
				{
					return &_tables[index];
				}
				else
					++index;
			}
			return nullptr;
		}
		bool erase(const K& key)
		{
			HashNode* ret = Find(key);
			if (ret)
			{
				ret->_status = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		std::vector<HashNode> _tables;
		size_t _nums=0;
	};
}