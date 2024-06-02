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



int main()
{
	int begin = 0;
	int n, q;
	cin >> n >> q;
	char* s = new char[n];
	scanf("%s", s);
	int size = strlen(s);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 2)
		{
			cout << s[(begin+b - 1)%size] << endl;

		}
		else
		{
			begin -= b;
			if (begin < 0)
				begin += size;
			
		}
	}

	return 0;
}
//int x = 0;
//bool f(vector<int>& v,int sum,int i)
//{
//	if (i >= v.size())
//	{
//		if (sum == x)
//			return true;
//		else
//			return false;
//	}
//	bool ret=f(v, sum + v[i],i+2) || f(v, sum + v[i+1],i+2);
//	
//	return ret;
//}
//int main()
//{
//	vector<int> v;
//	int n;
//	cin >> n >> x;
//	for (int i = 0; i < n*2; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v.push_back(t);
//	}
//	bool ret=f(v,0,0);
//	if (ret)
//		cout << "Yes";
//	else
//		cout << "No";
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	int max = a;
//	int min = b;
//	if (a < b)
//	{
//		max = b;
//		min = a;
//	}
//	if ((max + 1) % 10 == min)
//	{
//		cout << "Yes";
//		return 0;
//	}
//	if (max - 1 == min)
//	{
//		cout << "Yes";
//		return 0;
//	}
//	cout << "No";
//	return 0;
//}

//int main()
//{
//	int k = 0;
//	cin >> k;
//	int hour = k / 60;
//	int hh = 21 + hour;
//	int mm = k - 60 * hour;
//	if (mm < 10)
//	{
//		cout << hh << ":0" << mm;
//	}
//	else
//		cout << hh << ":" << mm;
//
//	
//	return 0;
//}