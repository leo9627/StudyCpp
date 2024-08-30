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
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<vector<int>> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		v[i].resize(m, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}
	if (n == 1&&m==1)
	{
		cout << "Yes";
	}
	else if (m == 1)
	{
		int d = v[0][0] - v[1][0];
		if (d == -7 )
		{
			for (int i = 0; i < n - 1; ++i)
			{
				if (v[i][0] - v[i + 1][0] != d)
				{
					cout << "No";
					return 0;
				}
			}
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else if(n==1)
	{
		int d = v[0][0] - v[0][1];
		if ( d == -1)
		{
			for (int i = 0; i < m - 1; ++i)
			{
				if (v[0][i] - v[0][i+1] != d)
				{
					cout << "No";
					return 0;
				}
			}
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else
	{
		int dh = v[0][0] - v[0][1];
		int dl = v[0][0] - v[1][0];
		if (dh==-1&&dl==-7)
		{
			//ÐÐ
			for (int j = 0; j < n; ++j)
			{
				for (int i = 0; i < m - 1; ++i)
				{
					if (v[j][i] - v[j][i + 1] != dh)
					{
						cout << "No";
						return 0;
					}
				}
			}
			
			//ÁÐ
			for (int j = 0; j < m; ++j)
			{
				for (int i = 0; i < n - 1; ++i)
				{
					if (v[i][j] - v[i + 1][j] != dl)
					{
						cout << "No";
						return 0;
					}
				}
			}
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	return 0;
}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v(n + 1, 0);
//	for (int i = 0; i < n-1; ++i)
//	{
//		int a = 0;
//		int b = 0;
//		cin >> a >> b;
//		v[a]++;
//		v[b]++;
//	}
//	for (auto& e : v)
//	{
//		if (e == n - 1)
//		{
//			cout << "Yes";
//			return 0;
//		}
//			
//	}
//	cout << "No";
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int i = 0;
//	for (; i < n; ++i)
//	{
//		if (i == n - 1)
//			break;
//		if (v[i] >= v[i + 1])
//			break;
//	}
//	cout << v[i];
//	return 0;
//}



//int main()
//{
//	string s;
//	cin >> s;
//	sort(s.begin(),s.end());
//	int n = 0;
//	do
//	{
//		++n;
//	} while (next_permutation(s.begin(), s.end()));
//	cout << n;
//	return 0;
//}


//int main()
//{
//	string s;
//	cin >> s;
//	int a = s[0] - '0';
//	int b = s[1] - '0';
//	int c = s[2] - '0';
//	cout << a * 100 + b * 10 + c + b * 100 + c * 10 + a + c * 100 + a * 10 + b;
//	return 0;
//}