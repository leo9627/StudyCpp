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
	size_t n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		int t = 0;
		cin >> t;
		v.push_back(t);
	}
	vector<vector<int>> p(n);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		p[i].push_back(x);
		p[i].push_back(y);
	}
	long double max = 0;
	for (int i = 0; i < k; i++)
	{
		long double x1 = p[v[i] - 1][0];
		long double y1 = p[v[i] - 1][1];
		for (int j = 0; j < n; j++)
		{
			long double x2 = p[j][0];
			long double y2 = p[j][1];
			long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			if (d > max)
				max = d;
		}
	}
	//long double ret = sqrt(max);
	cout.precision(18);
	cout  << max;
	return 0;
}
//int main()
//{
//	size_t n, k, q;
//	cin >> n >> k >> q;
//	vector<int> v(n,0);
//	for (size_t i = 0; i < k; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v[t - 1] = 1;
//	}
//	for (size_t i = 0; i < q; i++)
//	{
//		size_t l = 0;
//		cin >> l;
//		size_t index = 0;
//		for (; index < n; index++)
//		{
//			if (v[index] && l)
//				l--;
//			if (l == 0)
//				break;
//		}
//		if (index < n - 1 && v[index + 1]==0)
//		{
//			v[index] = 0;
//			v[index + 1] = 1;
//		}
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		if (v[i])
//		{
//			cout << i + 1 << " ";
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << (int)pow(2, n);
//	return 0;
//}
//int main()
//{
//	size_t arr[2][2] = { 0 };
//	int r, c;
//	cin >> r >> c;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	cout << arr[r - 1][c - 1];
//	return 0;
//}