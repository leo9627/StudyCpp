#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include"hashtable.h"
using namespace std;
using namespace leo;


void test_hash()
{
	unordered_set<int> us;
	us.insert(4);
	us.insert(2);
	us.insert(1);
	us.insert(5);
	us.insert(2);
	us.insert(2);
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << "  ";
		++it;
	}
	cout << endl;
	unordered_map<string, string> um;
	um["sort"] = "ÅÅĞò";
	um.insert(make_pair("left", "×ó±ß"));
	um.insert(pair<string, string>("string", "×Ö·û´®"));
	for (auto& e : um)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_op()
{
	unordered_set<int> us;
	set<int> s;
	vector<int> v;
	const int num = 1000000;
	v.reserve(num);
	srand(time(0));
	for (int i = 0; i < num; i++)
	{
		v.push_back(rand());
	}

	size_t begin = clock();
	for (auto& e : v)
	{
		us.insert(e);
	}
	size_t end = clock();
	cout << "unordered_set_insert:" << end - begin << endl;

	begin = clock();
	for (auto& e : v)
	{
		s.insert(e);
	}
	end = clock();
	cout << "set_insert:" << end - begin << endl;

	begin = clock();
	for (auto& e : v)
	{
		us.find(e);
	}
	end = clock();
	cout << "unordered_set_find:" << end - begin << endl;

	begin = clock();
	for (auto& e : v)
	{
		s.find(e);
	}
	end = clock();
	cout << "set_find:" << end - begin << endl;


	begin = clock();
	for (auto& e : v)
	{
		us.erase(e);
	}
	end = clock();
	cout << "unordered_set_erase:" << end - begin << endl;

	begin = clock();
	for (auto& e : v)
	{
		s.erase(e);
	}
	end = clock();
	cout << "set_erase:" << end - begin << endl;
}
int main()
{
	//test_hash();
	test_op();
	return 0;
}