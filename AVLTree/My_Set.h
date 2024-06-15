#pragma once
#include"RBTree.h"

namespace leo
{
	template<class K>
	class set
	{
	public:
		struct Keyoft
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename RBTree<K, K, Keyoft>::iterator iterator;
	public:
		pair<iterator,bool> Insert(const K& key)
		{
			return _tree.Insert(key);
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
		RBTree<K, K, Keyoft> _tree;
	};
}