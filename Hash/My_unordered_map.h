#pragma once

#include"hashtable.h"
namespace leo
{
	template<class K,class V,class _HASH=MyHash<K>>
	class unordered_map
	{
	public:
		struct KOFT;
		typedef typename Hash<K, std::pair<const K, V>, KOFT, _HASH>::iterator iterator;
		pair<iterator, bool> insert(const std::pair<const K, V>& data)
		{
			return _HashTables.Insert(data);
		}
		V& operator[](const K& key)
		{
			return (insert(make_pair(key, V())).first)->second;
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
			const K& operator()(const pair<const K, V>& data)
			{
				return data.first;
			}
		};
		Hash<K, std::pair<const K, V>, KOFT, _HASH> _HashTables;
	};
}