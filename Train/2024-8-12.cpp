#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include <iomanip>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
const size_t mod = 998244353;




//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	vector<bool> vis;
//	v.resize(n+1,0);
//	vis.resize(1000003,false);
//
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end()-1);
//	int ans = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (!vis[v[i]])
//		{
//			if (v[i] != v[i + 1])
//				++ans;
//			int x = v[i];
//			while (x <= 1000000)
//			{
//				vis[x] = true;
//				x += v[i];
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	int n = 0;
//	cin >> x >> n;
//	unordered_set<int> st;
//	for (int i = 0; i < n; ++i)
//	{
//		int t = 0;
//		cin >> t;
//		st.insert(t);
//	}
//	int left=x;
//	for (;; --left)
//	{
//		if (st.find(left) == st.end())
//			break;
//	}
//	if ((x - left) <= 1)
//	{
//		cout << left;
//		return 0;
//	}
//	int right = x;
//	for (;; ++right)
//	{
//		if (st.find(right) == st.end())
//			break;
//	}
//	int d1 = x - left;
//	int d2 = right - x;
//	if (d1 < d2)
//		cout << left;
//	else if (d1 > d2)
//		cout << right;
//	else
//		cout << left;
//		
//
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	int k = 0;
//	cin >> k;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	int sum = 0;
//	for (int i = 0; i < k; ++i)
//		sum += v[i];
//	cout << sum;
//	return 0;
//}

//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	int t = y - 2 * x;
//	if (t < 0)
//	{
//		cout << "No";
//	}
//	else
//	{
//		if (t % 2 != 0)
//		{
//			cout << "No";
//		}
//		else
//		{
//			int ans = t / 2;
//			if (ans <= x)
//				cout << "Yes";
//			else
//				cout << "No";
//
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	char c;
//	cin >> c;
//	if (c >= 'A' && c <= 'Z')
//		cout << "A";
//	else
//		cout << "a";
//	return 0;
//}

//int main()
//{
//	int ans = 0;
//	for (int i = 0; i < 5; ++i)
//	{
//		int t = 0;
//		cin >> t;
//		if (t == 0)
//			ans = i;
//	}
//	cout << ans + 1;
//	return 0;
//}