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



int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	vector<int> cnt;
	cnt.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		int mov =  (n+v[i]-i)%n;
		cnt[mov]++;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int t = cnt[i] + cnt[(i + 1) % n] + cnt[(n + i - 1) % n];
		if (max < t)
			max = t;
		if (max == n)
			break;
	}
	cout << max;
	return 0;
}




//vector<string> vs;
//unordered_set<string> ust;
//
//int n = 0;
//int m = 0;
//string ans;
//bool dfs(int i,int len,string& t1)
//{
//	if (i == n - 1)
//	{
//		if (t1.size() >= 3 && t1.size() <= 16 && ust.count(t1) == 0)
//		{
//			ans = t1;
//			return true;
//		}
//		else
//			return false;
//	}
//	else
//	{
//		int max = len / (n - i - 1) + 1;
//		for (int k = 1; k <=max; k++)
//		{
//			string add = string(k, '_') + vs[i + 1];
//			t1 = t1 + add;
//			if (dfs(i + 1, len - k, t1))
//				return true;
//			t1.erase(t1.size() - add.size());
//		}
//		return false;
//	}
//
//}
//
//int main()
//{
//	cin >> n >> m;
//	int len = 0;
//	vs.resize(n);
//	ans = "-1";
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vs[i];
//		len += vs[i].length();
//	}
//	ust.reserve(m);
//	for (int i = 0; i < m; i++)
//	{
//		string t;
//		cin >> t;
//		ust.insert(t);
//	}
//	sort(vs.begin(), vs.end());
//	do
//	{
//		string tmp = vs.front();
//		if (dfs(0,16-len,tmp))
//		{
//			break;
//		}
//	} while (next_permutation(vs.begin(),vs.end()));
//	cout << ans;
//	return 0;
//}









//int mode(int a, int b)
//{
//	int ret = a % b;
//	while (ret < 0)
//		ret += b;
//	return ret;
//
//}
//int main()
//{
//
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.reserve(n);
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v.push_back(t);
//	}
//	int max = 0;
//	int sum = 0;
//	for (int i = n-1; i >=0 ; i--)
//	{
//		sum = 0;
//		int j = i;
//		int people = 0;
//		for (int k = 0; k < n; k++)
//		{
//			if (j == n)
//				j = 0;
//			if (mode(v[j]-1,n) == k || v[j] == k || (v[j] + 1) % n == k)
//			{
//				sum++;
//			}
//			j++;
//		}
//		if (sum > max)
//			max = sum;
//		if (max == n)
//			break;
//	}
//	cout << max;
//	return 0;
//}



//int main()
//{
//	vector<string> v;
//	v.reserve(10);
//	for (int i = 0; i < 10; i++)
//	{
//		string t;
//		cin >> t;
//		v.push_back(t);
//	}
//	int a = 0;
//	int c = 0;
//	int f = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (v[i][j] == '#')
//			{
//				a = i;
//				c = j;
//				f = 1;
//				break;
//			}
//		}
//		if (f)
//			break;
//	}
//	int d = c;
//	for (; d < 10; d++)
//	{
//		if (v[a][d] == '.')
//			break;
//	}
//	int b = a;
//	for (; b < 10; b++)
//	{
//		if (v[b][c] == '.')
//			break;
//	}
//	a++;
//	c++;
//	cout << a <<" "<<b << endl;
//	cout << c <<" "<<d << endl;
//	return 0;
//}


//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	if (s1.size() > s2.size())
//	{
//		cout << "No";
//		return 0;
//	}
//
//	for (int i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] != s2[i])
//		{
//			cout << "No";
//			return 0;
//		}
//	}
//	cout << "Yes";
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	cin >> a >> b >> c >> d;
//	cout << (a + b) * (c - d) << endl;
//	cout << "Takahashi";
//	return 0;
//}
//int main()
//{
//	int arr[101] = {0};
//	for (int i = 0; i < 5; i++)
//	{
//		int t = 0;
//		cin >> t;
//		arr[t]=1;
//	}
//	int sum=0;
//	for (int i = 0; i < 101; i++)
//	{
//		if (arr[i])
//			sum++;
//	}
//	cout << sum;
//	return 0;
//}