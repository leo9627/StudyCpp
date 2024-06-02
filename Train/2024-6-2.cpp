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

void solve()
{
	long long a = 0;
	long long s = 0;
	cin >> a >> s;
	if (s < 2 * a)
	{
		cout << "No"<<endl;
		return;
	}
	s = s - 2*a;
	for (int i = 0; i < 61; i++)
	{
		if (((s >> i) & 1) == 1 && ((a >> i) & 1) == 1)
		{
			cout<<"No"<<endl;
			return;
		}
	}
	cout << "Yes"<<endl;
	return;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
//const int mod = 998244353;
//int main()
//{
//	long long n = 0;
//	cin >> n;
//	long long sum = 0;
//	long long r = 9;
//	while (n > 0)
//	{
//		sum += (  ((1 + min(r,n)) % mod) * (min(r,n) % mod)  /2) % mod;
//		n -= r;
//		r *= 10;
//	}
//	cout << sum%mod;
//	return 0;
//}
//int main()
//{
//	int arr[360] = { 0 };
//	int nums = 0;
//	arr[nums] = 1;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		nums += t;
//		nums = nums % 360;
//		arr[nums] = 1;
//	}
//	int left = 0;
//	int right = 0;
//	int max = 0;
//	while (right < 360)
//	{
//		if (arr[right] == 1)
//		{
//			int t = right - left;
//			if (t > max)
//				max = t;
//			left = right;
//		}
//		right++;
//	}
//	int s = 360 - left;
//	if (s > max)
//		max = s;
//	cout << max;
//
//
//	return 0;
//}
//int main()
//{
//	long long x=0;
//	cin >> x;
//	int f = 0;
//	if (x < 0)
//	{
//		f = 1;
//	}
//	x = abs(x);
//	int f1 = 0;
//	if (x % 10 != 0)
//		f1 = 1;
//	x = x / 10;
//	if (f)
//	{
//		if(f1)
//			x += 1;
//		cout << -x;
//	}
//	else
//		cout << x;
//
//
//	return 0;
//}

//int main()
//{
//	size_t h = 0;
//	cin >> h;
//	printf("%7f", sqrt(h * (12800000 + h)));
//	return 0;
//}
//int main()
//{
//	size_t n = 0;
//	cin >> n;
//	if (pow(2, n) > (n * n))
//	{
//		cout << "Yes";
//	}
//	else
//		cout << "No";
//	return 0;
//}