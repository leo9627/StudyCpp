#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include <iomanip>
#include<algorithm>
using namespace std;



int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		double t = sqrt(i);
		for (double j = 1; j < t; j++)
		{
			if (i % (int)j == 0)
				v[i] += 2;
		}
		if ((int)t *(int) t == i)
			v[i]++;
	}
	int ans = 0;
	for (int ab = 1; ab < n; ab++)
	{
		ans = ans + v[ab] * v[n - ab];
	}
	cout << ans;
	return 0;
}
//int main()
//{
//	int k = 0;
//	cin >> k;
//	set<int> s;
//	vector<int> v;
//	for (int i = 1; i <= k; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v.push_back(t);
//	}
//	for (int i = 1; i <= k; i++)
//	{
//		if (s.find(i)!=s.end())
//		{
//
//		}
//		else
//		{
//			s.insert(v[i - 1]);
//		}
//	}
//	vector<int> ret;
//	for (int i = 1; i <= k; i++)
//	{
//		if (s.find(i) == s.end())
//		{
//			ret.push_back(i);
//		}
//	}
//	cout << ret.size() << endl;
//	for (auto& e : ret)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}
//struct Node
//{
//	int yellow=0;
//	int red=0;
//};
//int main()
//{
//	int n, q;
//	map<int, Node> mp;
//	cin >> n >> q;
//	while (q--)
//	{
//		int a = 0;
//		int b = 0;
//		cin >> a >> b;
//		if (a == 1)
//		{
//			mp[b].yellow++;
//		}
//		else if (a == 2)
//		{
//			mp[b].red++;
//		}
//		else
//		{
//			if (mp[b].red == 1 || mp[b].yellow == 2)
//				cout << "Yes" << endl;
//			else
//				cout << "No" << endl;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	for (int i = 1; i <= s.size()/2; i++)
//	{
//		swap(s[2*i-2], s[2* i-1 ]);
//	}
//	cout << s;
//	return 0;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++)
//	{
//		cout << char(s[i]-32);
//	}
//	return 0;
//}