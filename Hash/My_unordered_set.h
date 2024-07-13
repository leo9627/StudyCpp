#pragma once


#include"hashtable.h"


namespace leo
{
	template<class K,class _HASH=MyHash<K>>
	class unordered_set
	{
	public:
		struct KOFT;
		typedef typename Hash<K, K, KOFT, _HASH>::iterator iterator;
		pair<iterator, bool> insert(const K& data)
		{
			return _HashTables.Insert(data);
		}
		iterator begin()
		{
			return _HashTables.begin();
		}
		iterator end()
		{
			return _HashTables.end();
		}
		iterator find(const K& key)
		{
			return _HashTables.Find(key);
		}
	private:
		struct KOFT
		{
			const K& operator()(const K& data)
			{
				return data;
			}
		};
		Hash<K, K, KOFT, _HASH> _HashTables;
	};
}
