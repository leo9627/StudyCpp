#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.h"
using namespace std;
//using namespace leo;

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int> v2 = v1;
	for (auto& i : v1)
	{
		i++;
		cout << i << " ";
	}
	cout << endl;
	v2.at(20) = 100;
	for (auto i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
}
void f(const vector<int>& v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int>::const_reverse_iterator itt = v.rbegin();
	while (itt != v.rend())
	{
		cout << *itt << " ";
		itt++;
	}
	cout << endl;
}
void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (auto& i : v)
	{
		i++;
	}
	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int>::reverse_iterator itt = v.rbegin();
	while (itt != v.rend())
	{
		cout << *itt << " ";
		itt++;
	}
	cout << endl;
	f(v);
}
void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	auto i = find(v.begin(), v.end(), 55);
	if (i != v.end())
	{
		v.erase(i);
	}

	//v.erase(v.begin(),v.begin()+2);
	//int* arr = v.data();
	//arr[1] = 1000;
	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}
void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(8);
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	/*vector<int>::iterator it = v.begin();
	v.push_back(7);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it=v.insert(it,100);
			it++;
			it++;
		}
		else
			it++;
	}
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
void test6()
{
	leo::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (auto e : v)
	{
		cout << e << " ";
	}
}
void print_vector(const leo::vector<int>& v)
{
	leo::vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;
}
void test7()
{
	leo::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	leo::vector<int> v2 = v1;
	v1.insert(v1.end()-3, 100);
	print_vector(v1);
	v2.pop_back();
	v2.pop_back();
	print_vector(v2);
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
	//int a= int();
	//cout << a << endl;
	return 0;
}
