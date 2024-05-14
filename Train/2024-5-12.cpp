#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

struct A
{
	char a : 2;
	char b : 3;
	char c : 4;
	//int d : 30;
};
A a1 = { -1,	0,-1 };
#include <stdio.h>
int main()
{
	char a = -128;
	unsigned int b = a;
	printf("%d\n", a);
	return 0;
}
//int main()
//{
//	double n = 0;
//	cin >> n;
//	vector<double> v;
//	v.resize(n);
//	for (double i = 0;i < n; i++)
//	{
//		cin >> v[i];
//	}
//	int num = 0;
//	for (double i = 0; i < n; i++)
//	{
//		for (double j = i+1; j < n; j++)
//		{
//			if (i == j)
//				continue;
//			double min = v[i];
//			double max = v[j];
//			if (min > max)
//			{
//				min = v[j];
//				max = v[i];
//				if (min-1 == i && max -1== j)
//					num++;
//			}
//			else
//			{
//				if (min-1 == i && max-1 == j)
//					num++;
//			}
//				
//		}
//	}
//	cout << num;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> v;
//	v.resize(n+1);
//	for (int i = 0; i < n+1; i++)
//	{
//		v[i].resize(n+1);
//	}
//	int a, b;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a >> b;
//		v[a][b] = 1;
//		v[b][a] = 1;
//	}
//	int num = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			for (int k = j + 1; k <= n; k++)
//			{
//				if ((v[i][j] || v[j][i]) && (v[i][k] || v[k][i]) && (v[j][k] || v[k][j]))
//					num++;
//			}
//		}
//	}
//	cout << num;
//	return 0;
//}
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	int len = s1.size();
//	for (int i = 0; i < len; i++)
//	{
//		s1 = s1[len - 1]+s1;
//		s1.pop_back();
//		if (s1 == s2)
//		{
//			cout << "Yes";
//			return 0;
//		}
//	}
//	cout << "No";
//
//	return 0;
//}

//int main()
//{
//	int n, m, x, t, d;
//	cin >> n >> m >> x >> t >> d;
//	if (m >= x && m < n)
//	{
//		cout << t;
//	}
//	else
//	{
//		cout << t - d * (x - m);
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	cin >> year;
//	int n = year % 4;
//	if (n == 2)
//		cout << year;
//	else if (n < 2)
//		cout << year + 2 - n;
//	else
//		cout << year + 2 + 4 - n;
//	return 0;
//}