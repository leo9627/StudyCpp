#include"AVLTree.h"
#include"RBTree.h"
#include<vector>
#include<ctime>
#include"My_Set.h"
#include"My_Map.h"
#include<map>


int main()
{
	leo::map<string, int> count;
	string arr[] = { "苹果","香蕉", "西瓜", "苹果" ,"香蕉" ,"西瓜", "西瓜", "苹果", "苹果" };
	for (auto& e : arr)
	{
		count[e]++;
	}
	for (auto& e : count)
	{
		cout << e.first << ":" << e.second << endl;
	}
	return 0;
}
//int main()
//{
//	leo::set<int> st;
//	leo::map<int, int> mp;
//	for (size_t i = 0; i < 100; i++)
//	{
//		int t = rand() % 1000;
//		st.Insert(t);
//		mp[t] = t;
//		//mp.Insert(make_pair(t, t));
//	}
//	for (auto e : st)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : mp)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	return 0;
//}












//void Test()
//{
//	const long long n = 1000000000;
//	vector<int> v;
//	v.reserve(n);
//	srand(time(0));
//	AVLTree<int, int> avlt;
//	RBTree<int, int> rbt;
//	for (size_t i = 0; i < n; i++)
//	{
//		v.push_back(rand());
//	}
//
//	int begin1 = clock();
//	for (auto& e : v)
//	{
//		avlt.Insert(make_pair(e, e));
//	}
//	for (auto& e : v)
//	{
//		avlt.Find(e);
//	}
//	int end1 = clock();
//
//	int begin2 = clock();
//	for (auto& e : v)
//	{
//		rbt.Insert(make_pair(e, e));
//	}
//	for (auto& e : v)
//	{
//		rbt.Find(e);
//	}
//	int end2 = clock();
//	cout << end1 - begin1 << endl << end2 - begin2;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//int main()
//{
//
//	//int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	//int arr[] = {9,8,7,6,5,4,3,2,1};
//	int arr[] = {1,2,3,4,5};
//	RBTree<int, int> t;
//	for (auto& e : arr)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	for (int i = 0; i < 1000; i++)
//	{
//		int a = rand();
//		t.Insert(make_pair(a, a));
//	}
//	t.InOrder();
//	cout << t.IsBalance();
//	return 0;
//}