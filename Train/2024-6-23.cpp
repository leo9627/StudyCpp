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
using namespace std;
int a[100001] = { 0 };
int f[100001][10] = { 0 };
int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t = 0;
		cin >> t;
		a[i] = t;
	}
	f[1][a[1]] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			(f[i][(j + a[i]) % 10]+= f[i - 1][j])%= 998244353;
			(f[i][(j * a[i]) % 10] += f[i - 1][j]) %= 998244353;
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		cout << f[n][i] << endl;
	}
	return 0;
}
//int main()
//{
//	int arr[10] = { 0 };
//	vector<int> v;
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		int t = 0;
//		cin >> t;
//		v.push_back(t);
//	}
//	queue<int> ret;
//	ret.push((v[0] + v[1]) % 10);
//	ret.push((v[0] * v[1]) % 10);
//	for (int i = 2; i < v.size(); i++)
//	{
//		int t = ret.size();
//		while (t--)
//		{
//			int t1 = ret.front();
//			ret.pop();
//			ret.push((t1 + v[i]) % 10);
//			ret.push((t1 * v[i]) % 10);
//		}
//	}
//	while (!ret.empty())
//	{
//		int tp = ret.front();
//		ret.pop();
//		arr[tp] = (arr[tp] + 1) % 998244353;
//	}
//	for (auto e : arr)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}
// (f[i][(j + A[i]) % 10] =f[i][(j + A[i]) % 10]+f[i - 1][j]) = (f[i][(j + A[i]) % 10] =f[i][(j + A[i]) % 10]+f[i - 1][j])%mod;


//(f[2][9] += f[1][2
// ]) %= mod;
//int main()
//{
//	size_t sum = 0;
//	int n = 0;
//	cin >> n;
//	vector<size_t> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v[i] = t;
//		sum += t;
//	}
//	size_t x = 0;
//	cin >> x;
//	size_t ans = ((size_t)(x/sum))*n;
//	size_t t = (ans/n) * (sum);
//	int i = 0;
//	while (t <= x)
//	{
//		t += v[i];
//		i++;
//		ans++;
//	}
//	cout << ans;
//	return 0;
//}
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	size_t n = 0;
//	int a = 0;
//	int b = 0;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] != s2[i])
//		{
//			if (n == 0)
//				a = i;
//			else if (n == 1)
//				b = i;
//			n++;
//		}
//	}
//	if (n == 0)
//	{
//		cout << "Yes";
//		return 0;
//	}
//
//	if(n==2)
//	{
//		if (abs(a - b) != 1)
//		{
//			cout << "No";
//			return 0;
//		}
//		swap(s1[a], s1[b]);
//		if (s1 == s2)
//			cout << "Yes";
//		else
//			cout << "No";
//	}
//	else
//	{
//
//		cout << "No";
//	}
//	return 0;
//}
//int main()
//{
//	size_t k, a, b;
//	cin >> k >> a >> b;
//	size_t ta=0;
//	size_t tb=0;
//	int n = 0;
//	while (a)
//	{
//		ta += (a%10)*(size_t)pow(k, n);
//		a = a / 10;
//		n++;
//	}
//	n = 0;
//	while (b)
//	{
//		tb += (b % 10) * (size_t)pow(k, n);
//		b = b / 10;
//		n++;
//	}
//	cout << ta * tb;
//	return 0;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int d = abs(b - a);
//	cout << (int)pow(32, d);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	int t = c;
//	c = (a/c)*c;
//	while (c < a)
//	{
//		c += t;
//		
//	}
//	if (c <= b)
//		cout << c;
//	else
//		cout << -1;
//	
//	return 0;
//}