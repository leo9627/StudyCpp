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
	int n, x, y;
	cin >> n >> x >> y;
	unordered_map<int, vector<int>> um;
	for (int i = 1; i < n; ++i)
	{
		um[i].push_back(i + 1);
		um[i + 1].push_back(i);
	}
	um[x].push_back(y);
	um[y].push_back(x);
	vector<int> vis;
	vector<int> dis;
	vector<int> ret;
	ret.resize(n);
	for (int i = 1; i <= n; i++)
	{
		vis.clear();
		vis.resize(n + 1, 0);
		dis.clear();
		dis.resize(n + 1, 0);
		queue<int> qe;
		qe.push(i);
		vis[i] = 1;
		while (!qe.empty())
		{
			int t = qe.front();
			qe.pop();
			for (auto& e : um[t])
			{
				if (vis[e])
					continue;
				dis[e] = dis[t] + 1;
				vis[e] = 1;
				qe.push(e);
			}
		}
		for (int j = 1; j <= n; ++j)
		{
			++ret[dis[j]];
		}

	}
	for (int i = 1; i <n; ++i)
	{
		cout << ret[i] / 2 << endl;
	}
	return 0;
}


//int main()
//{
//	int k = 0;
//	int n = 0;
//	cin >> k >> n;
//	vector<int> v;
//	v.resize(n);
//	int max = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//		if (i == 0)
//		{
//
//		}
//		else
//		{
//			if (v[i] - v[i - 1] > max)
//				max = v[i] - v[i - 1];
//		}
//	}
//	if (k - v[n - 1] + v[0] > max)
//		max = k - v[n - 1] + v[0];
//	cout << k - max;
//	return 0;
//}
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	vector<int> v;
//	v.reserve(n);
//	size_t sum = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int t = 0;
//		cin >> t;
//		v.push_back(t);
//		sum += t;
//	}
//	sort(v.begin(), v.end());
//	int i = 0;
//	for (; i < n; ++i)
//	{
//		if (v[i]*4*m > sum)
//			break;
//	}
//	int num = n - i;
//	if (num > m)
//		cout << "Yes";
//	else
//		cout << "No";
//	return 0;
//}


//int main()
//{
//	size_t x = 0;
//	cin >> x;
//	size_t sum = x / 500 * 1000;
//	sum += (x % 500) / 5 * 5;
//	cout << sum;
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	printf("%d %d %d", c, a, b);
//}

//int main()
//{
//	string s;
//	cin >> s;
//	if (s[2] == s[3] && s[4] == s[5])
//	{
//		cout << "Yes";
//	}
//	else
//		cout << "No";
//	return 0;
//}