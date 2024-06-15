#pragma once
#include"RBTree.h"

namespace leo
{
	template<class K,class V>
	class map
	{
	public:
		struct Keyoft
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
		typedef typename RBTree<K, pair<K, V>, Keyoft>::iterator iterator;
		pair<iterator,bool> Insert(const pair<K, V>& data)
		{
			return _tree.Insert(data);
		}
		V& operator[](const K& key)
		{
			return ((Insert(make_pair(key, V())).first)->second);
		}
		iterator begin()
		{
			return _tree.begin();
		}
		iterator end()
		{
			return _tree.end();
		}
	private:
		RBTree<K, pair<K, V>, Keyoft> _tree;
	};
}