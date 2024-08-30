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

int main()
{
	size_t n = 0;
	cin >> n;
	vector<size_t> v;
	v.resize(n+1);
	for (size_t i = 1; i < n + 1; ++i)
	{
		cin >> v[i];
	}
	size_t q = 0;
	cin >> q;
	vector<size_t> tim(n + 1, 0);
	size_t p = 0;
	size_t ptim = 0;
	while (q--)
	{
		size_t a = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> p;
			++ptim;
		}
		else if (a == 2)
		{
			size_t a, b;
			cin >> a >> b;
			if (tim[a] < ptim)
			{
				tim[a] = ptim;
				v[a] = p;
			}
			v[a] += b;
		}
		else
		{
			size_t a = 0;
			cin >> a;
			if (tim[a] < ptim)
			{
				tim[a] = ptim;
				v[a] = p;
			}
			cout << v[a]<<endl;
		}
	}
	return 0;
}

//int main()
//{
//	size_t n, q;
//	cin >> n >> q;
//	//vector<unordered_set<size_t>> v;
//	map<int,unordered_set<size_t>> v;
//	//v.resize(n+1);
//	for (size_t i = 0; i < q; ++i)
//	{
//		size_t t, a, b;
//		cin >> t >> a >> b;
//		if (t == 1)
//		{
//			v[a].insert(b);
//		}
//		else if (t == 2)
//		{
//			v[a].erase(b);
//		}
//		else
//		{
//			if (v[a].count(b) && v[b].count(a))
//				cout << "Yes\n";
//			else
//				cout << "No\n";
//		}
//
//	}
//
//	return 0;
//}

//bool check(string h, string m)
//{
//	if (h.size() == 1)
//		h = '0' + h;
//	if (m.size() == 1)
//		m = '0' + m;
//	swap(h[1], m[0]);
//	int h1 = stoi(h);
//	int m1 = stoi(m);
//	if (h1 < 24)
//	{
//		if (m1 < 59)
//			return false;
//		else
//			return true;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//int main()
//{
//	int h, m;
//	cin >> h >> m;
//	while (check(to_string(h), to_string(m)))
//	{
//		++m;
//		if (m == 60)
//		{
//			m = 0;
//			h++;
//		}
//		if (h == 24)
//			h = 0;
//	}
//	cout << h << " " << m;
//
//	return 0;
//}

//int main()
//{
//	string s;
//	string t;
//	cin >> s >> t;
//	size_t pos=s.find(t);
//	if (pos == string::npos)
//		cout << "No";
//	else
//		cout << "Yes";
//	return 0;
//}

//int main()
//{
//	string s;
//	cin >> s;
//	int ans = 0;
//	for (auto& e : s)
//	{
//		if (e == 'w')
//			ans += 2;
//		else
//			++ans;
//	}
//	cout << ans;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int k = 0;
//	cin >> n >> k;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int t = 0;
//	for (int i = k; i < n; ++i)
//	{
//		++t;
//		cout << v[i] << " ";
//	}
//	for (int i = 0; i < n - t; ++i)
//	{
//		cout << 0 << " ";
//	}
//
//	return 0;
//}