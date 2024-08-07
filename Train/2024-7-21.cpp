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
using namespace std;
const size_t mod = 998244353;


long long gcd(long long a, long long b)
{
	if (b > a)
		swap(a, b);
	size_t c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}
int main()
{
	size_t t;
	size_t n, d, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> d >> k;
		cout << ((k - 1) * d) % n + ((k - 1) * d) / lcm(n, d) << endl;
	}
	return 0;
}


//int main()
//{
//	auto l = { 1,1 };
//	int nums = 0;
//	cin >> nums;
//	while (nums--)
//	{
//		int n, m;
//		int f = 1;
//		cin >> n >> m;
//		string s1, s2;
//		cin >> s1 >> s2;
//		int count = 0;
//		if (s1.find(s2.c_str())!=string::npos)
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		while (s1.size() <= s2.size()*3||s1.size()==n)
//		{
//			count++;
//			string t = s1;
//			s1 += t;
//			if (s1.find(s2) != string::npos)
//			{
//				cout << count << endl;
//				f = 0;
//				break;
//			}
//		}
//		if(f)
//			cout << "-1\n";
//		
//	}
//	return 0;
//}

//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	set<int> st;
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		st.insert(t);
//	}
//	set<int>::iterator it = st.begin();
//	int ans = 0;
//	while (it != st.end())
//	{
//		if (ans != *it)
//			break;
//		ans++;
//		if (ans == k)
//			break;
//		it++;
//	}
//	cout << ans;
//
//	return 0;
//}


//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	for (auto& e : s)
//	{
//		if (e == 'o' && k != 0)
//		{
//			cout << e;
//			k--;
//		}
//		else
//		{
//			cout << 'x';
//		}
//	}
//	return 0;
//}


//int main()
//{
//	string s;
//	cin >> s;
//	int len = s.size();
//	if (len == 8&&s[0] >= 'A' && s[0] <= 'Z' && s[len - 1] >= 'A' && s[len - 1] <= 'Z'&&s[1]>='1')
//	{
//		string sub = s.substr(1, len - 2);
//		for (auto& e : sub)
//		{
//			if (e >= '0' && e <= '9')
//			{
//
//			}
//			else
//			{
//				cout << "No";
//				return 0;
//			}	
//		}
//		cout << "Yes";
//
//	}
//	else
//	{
//		cout << "No";
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = n; i >= 0; i--)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> v1;
//	v1.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin>>v1[i];
//	}
//	int sum = 0;
//	while (m--)
//	{
//		int t = 0;
//		cin >> t;
//		sum += v1[t - 1];
//	}
//	cout << sum;
//	return 0;
//}