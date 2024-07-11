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
const size_t mod = 998244353;
long long S[3001][3001] = { 0 };
int main()
{
	int n = 0;
	cin >> n;
	vector<int> A;
	vector<int> B;
	A.reserve(n);
	B.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		A.push_back(t);
	}
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		B.push_back(t);
	}
	int num = 1;
	for (int i = A[0]; i <= B[0]; i++)
	{
		S[1][i] = num++;
	}
	long long last = --num;
	for (int i = B[0] + 1; i <= 3000; i++)
	{
		S[1][i] = last;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = A[i - 1]; j <= B[i - 1]; j++)
		{
			if (j == 0)
			{
				last=S[i][j] = S[i - 1][j];
			}
			else
			{
				last=S[i][j] = (S[i][j - 1] + S[i - 1][j])%mod;
			}
		}
		for (int j = B[i - 1] + 1; j <= 3000; j++)
		{
			S[i][j] = last;
		}

	}
	cout << S[n][B[n - 1]];
	return 0;
}



















//vector<int> a;
//vector<int> b;
//size_t sum = 0;
//void f(int i,int& n,int c)
//{
//	if (i == n )
//	{
//		sum=(sum+1)%mod;
//		return;
//	}
//	for (int k = a[i]; k <= b[i]; k++)
//	{
//		if(k>=c)
//			f(i + 1, n, k);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	a.reserve(n);
//	b.reserve(n);
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		a.push_back(t);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		b.push_back(t);
//	}
//	f(0, n,0);
//	cout << sum;
//	return 0;
//}






//int main()
//{
//	string s;
//	cin >> s;
//	int len = s.size();
//	int b = len;
//	vector<string> v;
//	while (b--)
//	{
//		char t = s[len-1];
//		s.pop_back();
//		string a = t+s;
//		s = a;
//		len = s.size();
//		v.push_back(s);
//	}
//	sort(v.begin(), v.end());
//	cout << *v.begin() << endl<<*(--v.end());
//	return 0;
//}










//struct player
//{
//	int id;
//	int score = 0;
//	bool operator<(const player& pl)const
//	{
//		if (score < pl.score)
//			return true;
//		else if (score > pl.score)
//			return false;
//		else
//		{
//			if (id < pl.id)
//				return true;
//			else
//				return false;
//		}
//	}
//	bool operator>(const player& pl)const
//	{
//		if (score > pl.score)
//			return true;
//		else if (score < pl.score)
//			return false;
//		else
//		{
//			if (id < pl.id)
//				return true;
//			else
//				return false;
//		}
//	}
//};
//int main()
//{
//	int n,m;
//	cin >> n >> m;
//	vector<string> v;
//	v.reserve(n);
//	for (int i = 0; i < 2 * n; i++)
//	{
//		string s;
//		cin >> s;
//		v.push_back(s);
//	}
//	vector<player> ret;
//	ret.reserve(2*n);
//	for (int i = 0; i < 2*n; i++)
//	{
//		player t = { i + 1,0 };
//		ret.push_back(t);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < 2*n; j += 2)
//		{
//			if (v[ret[j].id - 1][i]=='G'&& v[ret[j+1].id - 1][i]=='C')
//			{
//				ret[j].score++;
//			}
//			else if (v[ret[j].id - 1][i] == 'C' && v[ret[j + 1].id - 1][i] == 'P')
//			{
//				ret[j].score++;
//			}
//			else if (v[ret[j].id - 1][i] == 'P' && v[ret[j + 1].id - 1][i] == 'G')
//			{
//				ret[j].score++;
//			}
//			else if (v[ret[j].id - 1][i] == 'C' && v[ret[j + 1].id - 1][i] == 'G')
//			{
//				ret[j+1].score++;
//			}
//			else if (v[ret[j].id - 1][i] == 'P' && v[ret[j + 1].id - 1][i] == 'C')
//			{
//				ret[j + 1].score++;
//			}
//			else if (v[ret[j].id - 1][i] == 'G' && v[ret[j + 1].id - 1][i] == 'P')
//			{
//				ret[j + 1].score++;
//			}
//		}
//
//		sort(ret.begin(), ret.end(),greater<player>());
//	}
//	for (auto& e : ret)
//	{
//		cout << e.id << endl;
//	}
//	return 0;
//}




//int main()
//{
//	int n = 0;
//	cin >> n;
//	int p = 0;
//	cin >> p;
//	int ans = 0;
//	while (n--)
//	{
//		int t = 0;
//		cin >> t;
//		if (t < p)
//			ans++;
//	}
//	cout << ans;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	if (n == 0)
//	{
//		cout << "No";
//	}
//	else
//	{
//		if (n % 100 == 0)
//			cout << "Yes";
//		else
//			cout << "No";
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	if (n >= 0 && n <= 9)
//	{
//		cout << "000" << n;
//	}
//	else if (n >= 10 && n <= 99)
//	{
//		cout << "00" << n;
//
//	}
//	else if (n >= 100 && n <= 999)
//	{
//		cout << "0" << n;
//	}
//	else
//		cout << n;
//	return 0;
//}