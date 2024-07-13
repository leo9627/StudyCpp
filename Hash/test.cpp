#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<vector>
#include"hashtable.h"
using namespace std;
//using namespace leo;


//void test_hash()
//{
//	unordered_set<int> us;
//	us.insert(4);
//	us.insert(2);
//	us.insert(1);
//	us.insert(5);
//	us.insert(2);
//	us.insert(2);
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << "  ";
//		++it;
//	}
//	cout << endl;
//	unordered_map<string, string> um;
//	um["sort"] = "ÅÅÐò";
//	um.insert(make_pair("left", "×ó±ß"));
//	um.insert(pair<string, string>("string", "×Ö·û´®"));
//	for (auto& e : um)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//}
//
//void test_op()
//{
//	unordered_set<int> us;
//	set<int> s;
//	vector<int> v;
//	const int num = 1000000;
//	v.reserve(num);
//	srand(time(0));
//	for (int i = 0; i < num; i++)
//	{
//		v.push_back(rand());
//	}
//
//	size_t begin = clock();
//	for (auto& e : v)
//	{
//		us.insert(e);
//	}
//	size_t end = clock();
//	cout << "unordered_set_insert:" << end - begin << endl;
//
//	begin = clock();
//	for (auto& e : v)
//	{
//		s.insert(e);
//	}
//	end = clock();
//	cout << "set_insert:" << end - begin << endl;
//
//	begin = clock();
//	for (auto& e : v)
//	{
//		us.find(e);
//	}
//	end = clock();
//	cout << "unordered_set_find:" << end - begin << endl;
//
//	begin = clock();
//	for (auto& e : v)
//	{
//		s.find(e);
//	}
//	end = clock();
//	cout << "set_find:" << end - begin << endl;
//
//
//	begin = clock();
//	for (auto& e : v)
//	{
//		us.erase(e);
//	}
//	end = clock();
//	cout << "unordered_set_erase:" << end - begin << endl;
//
//	begin = clock();
//	for (auto& e : v)
//	{
//		s.erase(e);
//	}
//	end = clock();
//	cout << "set_erase:" << end - begin << endl;
//}
//
//
//template<class K,class T>
//struct KOFT
//{
//	const K& operator()(const T& d)const
//	{
//		return d;
//	}
//};
//template<class K, class T>
//struct KOFT1
//{
//	const K& operator()(const T& d)const
//	{
//		return d.first;
//	}
//};
//void test_3()
//{
//	Hash<string, pair<string, string>, KOFT1<string, pair<string,string>>> h;
//	h.Insert(make_pair("string", "×Ö·û´®"));
//}
//void test_leo()
//{
//	Hash<int, int, KOFT<int,int>> h1;
//	set<int> s;
//	srand(time(0));
//	int m = 10000000;
//	vector<int> v;
//	v.reserve(m);
//	while (m--)
//	{
//		v.push_back(rand());
//	}
//	size_t begin1 = clock();
//	for (auto& e : v)
//	{
//		h1.Insert(e);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (auto& e : v)
//	{
//		s.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "hash_insert:" << end1 - begin1 << endl;
//	cout << "rbtree_insert:" << end2 - begin2 << endl;
//
//	size_t begin3=clock();
//	for (auto& e : v)
//	{
//		HashNode<int>* p = h1.Find(e);
//		if (p == nullptr||  p->_data!=e)
//		{
//
//			cout << "FALSE";
//			return;
//		}
//	}
//	cout << "GOOD"<<endl;
//	size_t end3 = clock();
//	cout << "hash_find:" << end3 - begin3 << endl;
//
//	size_t begin4 = clock();
//	for (auto& e : v)
//	{
//		s.find(e);
//	}
//	size_t end4 = clock();
//	cout << "rbtree_find:" << end4 - begin4 << endl;
//	return;
//}
//void test()
//{
//	Hash<int, int, KOFT<int,int>> h;
//	h.Insert(5);
//	h.Insert(15);
//	h.Insert(16);
//	h.Insert(17);
//	h.Insert(18);
//	h.Insert(19);
//	h.Insert(3);
//	h.Insert(2);
//	h.Insert(1);
//	h.Insert(12);
//	h.Insert(13);
//}

#include"My_unordered_set.h"
#include"My_unordered_map.h"
void test_set()
{
	leo::unordered_set<int> us;
	us.insert(1);
	us.insert(3);
	us.insert(4);
	us.insert(8);
	for (auto& e : us)
	{
		cout << e << " ";
	}
	cout << endl;
	leo::unordered_map<string, string> um;
	um.insert(make_pair("string", "×Ö·û´®"));
	um.insert(make_pair("left", "×ó±ß"));
	um.insert(make_pair("right", "ÓÒ±ß"));
	for (auto& e : um)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
void test_myset_op()
{
	std::unordered_set<string> us;
	leo::unordered_set<string> muss;
	vector<string> v;
	const int num = 100000;
	v.reserve(num);
	srand(time(0));
	for (int i = 0; i < num; i++)
	{
		string s;
		for (size_t i = 0; i < rand(); i++)
		{

			s += char(rand() % 26+65);
		}
		v.push_back(s);
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
		muss.insert(e);
	}
	end = clock();
	cout << "my_ordered_set_insert:" << end - begin << endl;

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
		auto it=muss.find(e);
		if (*it != e)
		{
			cout << "BAD" << endl;
			return;
		}
	}
	end = clock();
	cout << "my_ordered_set_find:" << end - begin << endl;

}
void test_mymap_op()
{
	leo::unordered_map<string, string> mmp;
	std::unordered_map<string, string> ump;
	const int num = 100;
	srand(time(0));
	size_t begin = clock();
	for (int i = 0; i < num-1; i++)
	{
		string key;
		for (size_t i = 0; i < rand(); i++)
		{

			key += char(rand() % 26 + 65);
		}
		string value;
		for (size_t i = 0; i < rand(); i++)
		{

			value += char(rand() % 26 + 65);
		}
		cout << key << endl<<endl<< value << endl<<endl;
		ump.insert(make_pair(key, value));
	}
	ump["ÂÀÌÎÌÎ"] = "´óË§¸ç";
	size_t end = clock();
	cout << "unordered_map_insert:" << end - begin << endl;
	begin = clock();
	for (auto& e : ump)
	{
		//auto it = mmp.insert(e);
		mmp[e.first] = e.second;
	}
	end = clock();
	cout << "my_unordered_map_insert:" << end - begin << endl;


	begin = clock();
	for (auto& e : ump)
	{
		ump.find(e.first);
	}
	end = clock();
	cout << "unordered_map_find:" << end - begin << endl;


	begin = clock();
	for (auto& e : ump)
	{
		auto it=mmp.find(e.first);
		if (it->first != e.first || it->second != e.second)
		{
			cout << "BAD";
			return;
		}
	}
	end = clock();
	cout << "my_unordered_map_find:" << end - begin << endl;
}
int main()
{
	//test_hash();
	//test_op();
	//test_leo();
	//test();
	//test_3();
	//test_set();
	test_mymap_op();
	return 0;
}