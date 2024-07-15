#pragma once
#include"bitset.h"
#include<string>

namespace leo
{
	struct MyHash1
	{
		size_t operator()(const std::string& s)
		{
			size_t ret = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				ret *= 31;
				ret += s[i];
			}
			return ret;
		}
	};
	struct MyHash2
	{
		size_t operator()(const std::string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};
	struct MyHash3
	{
		size_t operator()(const std::string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};
	template<size_t X,
		size_t N=5,
		class K=std::string,
		class Hash1=MyHash1,
		class Hash2 = MyHash2,
		class Hash3 = MyHash3>
	class BloomFilter
	{
	public:
		void set(const K& key)
		{
			size_t index1 = Hash1()(key) % len;
			size_t index2 = Hash2()(key) % len;
			size_t index3 = Hash3()(key) % len;
			_bitset.set(index1);
			_bitset.set(index2);
			_bitset.set(index3);
		}
		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % len;
			size_t index2 = Hash2()(key) % len;
			size_t index3 = Hash3()(key) % len;
			return _bitset.test(index1)&&
					_bitset.test(index2)&&
					_bitset.test(index3);
		}
	private:
		bitset<X*N> _bitset;
		size_t len = X * N;
	};
}