
#include<iostream>
#include<list>
#include<vector>
#include"list.h"
using namespace std;

//template<class T>
//struct Node
//{
//	Node<int>* next;
//	T data;
//};

void test1()
{
	list<int>  l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_front(4);
	l1.pop_back();
	l1.pop_front();
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test2()
{
	list<int>  l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	//l1.insert(l1.begin(), 4);
	int& a = l1.front();
	a = 100;
	for (auto e : l1)
	{
		cout << e << " ";
	}
}
void test3()
{
	list<int>  l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	list<int> l2;
	l2.push_back(9);
	l2.push_back(9);
	l2.push_back(9);
	swap(l1, l2);
	for (auto e : l1)
	{
		cout << e << " ";
	}
}
void test4()
{
	list<int>  l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	//list<int>::const_iterator it = l1.begin();
	++l1.begin();
	cout << l1.size() << endl;

	l1.resize(20);
	cout << l1.size() << endl;
	l1.clear();
	l1.push_front(3);
	l1.push_front(2);
	cout << l1.size() << endl;

	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << l1.max_size() << endl;

}
struct Date
{
	int _year = 1;
	int _day = 2;
};
void test5()
{
	Date d1;
	Date d2;
	leo::list<Date> l1;
	l1.push_back(d1);
	l1.push_back(d2);
	leo::list<Date>::iterator it = l1.begin();
	for (auto e : l1)
	{
		cout << e._day << " ";
	}
}
void test6()
{
	leo::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.insert(l1.begin(), 33);
	leo::list<int> l2;
	l2 = l1;
	l1.pop_back();

	for (auto e : l2)
	{
		cout << e<< " ";
	}
}
void f(const leo::list<int>& v)
{
	leo::list<int>::const_reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
}
void test7()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	leo::list<int> l1(v.begin(), v.end());
	f(l1);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}