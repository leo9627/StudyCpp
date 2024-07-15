#pragma once
#include<vector>


namespace leo
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N/32+1);
		}
		bool set(size_t n)
		{
			if (n >= N)
			{
				return false;
			}
			size_t index = n / 32;
			size_t pos = n % 32;
			_bits[index] |= (1 << pos);
			--_nums;
			return true;
		}
		bool reset(size_t n)
		{
			if (n >= N)
				return false;
			size_t index = n / 32;
			size_t pos = n % 32;
			_bits[index] &= ~(1 << pos);
			--_nums;
			return true;
		}
		bool test(size_t n)
		{
			if (n >= N)
				return false;
			size_t index = n / 32;
			size_t pos = n % 32;
			return _bits[index] & (1 << pos);
		}
	private:
		std::vector<int> _bits;
		size_t _nums = 0;
	};
}