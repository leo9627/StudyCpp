#include<iostream>
#include"bitset.h"
#include"bloomfilter.h"
using namespace std;

void test_bloomfilter()
{
	leo::BloomFilter<10> bf;
	bf.set("baidu");
	bf.set("tencent");
	bf.set("huawei");
	bf.set("alibaba");
	cout << bf.test("baidr");
}

int main()
{
	test_bloomfilter();
	/*leo::bitset<100> bit;
	bit.set(5);
	bit.set(94);
	bit.set(95);
	bit.set(96);
	bit.set(97);
	bit.set(66);
	bit.reset(5);
	for (int i = 0; i < 100; i++)
	{
		printf("[%d]:%d\n", i, bit.test(i));
	}*/
	return 0;
}