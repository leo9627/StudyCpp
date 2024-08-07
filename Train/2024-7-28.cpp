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

size_t gcd(size_t a, size_t b)
{
	if (a < b)
		swap(a, b);
	while (a % b)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return b;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	int _gcd = 0;
	for (int i = 0; i < n; ++i)
	{
		int t = 0;
		cin >> t;
		v[i] = t;
		if (i == 0)
			_gcd = t;
		else
			_gcd = gcd(_gcd, t);
	}
	int count = 0;
	for (auto& e : v)
	{
		e /= _gcd;
		while (e % 2 == 0)
		{
			e /= 2;
			++count;
		}	
		while (e % 3 == 0)
		{
			e /= 3;
			++count;
		}
		if (e != 1)
		{
			cout << "-1";
			return 0;
		}
	}
	cout << count;
	return 0;
}



//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	int left = n - 1;
//	for (; left >= 1; --left)
//	{
//		if (v[left-1] > v[left])
//			break;
//	}
//	int right = 0;
//	if (left != 0)
//	{
//
//		auto it = lower_bound(v.begin() + left, v.end(), v[left - 1]);
//		--it;
//		swap(*(v.begin() + left - 1), *it);
//		sort(v.begin() + left, v.end(), greater<int>());
//
//	}
//	for (auto& e : v)
//		cout << e << " ";
//
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	cin >> n;
//	set<string> st;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//		st.insert(s);
//	}
//	if (st.size() != n)
//	{
//		cout << "No";
//		return 0;
//	}
//	for (auto& e : st)
//	{
//		if (e[0] != 'H' && e[0] != 'D' && e[0] != 'C' && e[0] != 'S')
//		{
//			cout << "No";
//			return 0;
//		}
//		if(e[1]!='A'&&e[1] != 'T' && e[1] != 'J' && e[1] != 'Q' && e[1] != 'K'
//			&&!(e[1]>='2'&&e[1]<='9'))
//		{
//			cout << "No";
//			return 0;
//		}
//		//A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K
//	}
//	cout << "Yes";
//	return 0;
//}
//int main()
//{
//	unordered_map<int, vector<int>> mp;
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		mp[a].push_back(b);
//		mp[b].push_back(a);
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		sort(mp[i].begin(), mp[i].end());
//		cout << mp[i].size() << " ";
//		for (auto& e : mp[i])
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int n, x;
//	cin >> n >> x;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		int t = 0;
//		cin >> t;
//		if (t == x)
//			ans = i;
//	}
//	cout << ans;
//	return 0;
//}

//int main()
//{
//	string s;
//	cin >> s;
//	int i = s.size() - 1;
//	for (; i >= 0; --i)
//	{
//		if (s[i] == 'a')
//			break;
//	}
//	if (i >= 0)
//		cout << i + 1;
//	else
//		cout << -1;
//	return 0;
//}