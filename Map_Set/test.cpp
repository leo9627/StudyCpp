#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

void test1()
{
	set<int> st;
	st.insert(4);
	st.insert(3);
	st.insert(6);
	st.insert(2);
	st.insert(st.begin(), 1000);
	set<int>::iterator it = st.begin();
	//*it = 2;
	st.erase(++it);
	for (auto& e : st)
	{
		cout << e << " ";
	}
}

void test2()
{
	map<string, int> mp;

	string arr[] = { "西瓜","樱桃", "西瓜", "苹果", "西瓜", "西瓜", "苹果", "西瓜", "西瓜" };
	for (auto& e : arr)
	{
		map<string, int>::iterator it = mp.find(e);
		if (it == mp.end())
		{
			//mp.insert(make_pair(e, 1));
			mp.insert(pair<string,int>(e, 1));
		}
		else
		{
			it->second++;
		}
	}
	for (auto& e : mp)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
void test3()
{
	map<int, int> mp;
	mp.insert(pair<int, int>(2, 2));
	mp.insert(pair<int, int>(3, 3));
	mp.insert(pair<int, int>(4, 4));
	mp.insert(pair<int, int>(5, 5));
	mp.insert(make_pair(6, 6));
	mp.insert({8,8});
	mp.erase(600);
	map<int, int>::iterator it = mp.find(6);
	if (it == mp.end())
	{
		cout << "no find"<<endl;
	}
	else
	{
		mp.erase(it);
	}
	for (auto& e : mp)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test4()
{
	set<int> st;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);

	auto itlow = st.lower_bound(20);
	auto itup = st.upper_bound(40);
	st.erase(itlow, itup);
	for (auto& e : st)
	{
		cout << e<<" ";
	}
}

void test5()
{
	multiset<int> st;
	st.insert(20);
	st.insert(2);
	st.insert(2);
	st.insert(0);
	st.insert(18);
	st.insert(2);
	st.insert(1);
	st.insert(2);
	auto it = st.find(2);
	int nums=0;
	while (it != st.end() && *it == 2)
	{
		nums++;
		++it;
	}
		
	for (auto& e : st)
	{
		cout << e << " ";
	}
	cout << endl << nums;
}

void test6()
{
	vector<int> v = { 2,3,1,6,4,5 };
	set<int> st;
	st.insert(v.begin(), v.end());
	for (auto& e : st)
	{
		cout << e << " ";
	}
}
void test7()
{
	pair<string, int> kv = { "china",6 };
	map<string, int> mp = { {"apple",2},{"pear",5},kv};
	for (auto& e : mp)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	//test6();
	//test7();
	return 0;
}