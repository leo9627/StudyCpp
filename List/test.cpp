#include<iostream>
#include<list>
using namespace std;

template<class T>
struct Node
{
	Node<int>* next;
	T data;
};

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
	cout << *l1.end();
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
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	Node<int> a;
	return 0;
}