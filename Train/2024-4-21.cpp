#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;


int main()
{
	map<int, int> m1;
	m1[20] = 5;
	m1[20] ++;
	m1[5] = 3;
	cout << m1[20]<<endl;
	cout << m1[5]<<endl;
}

//int main()
//{
//	int* arr = new int[1000000000];
//	unsigned long long int n = 0;
//	cin >> n;
//	unsigned long long int a = 0;
//	unsigned long long int b = 0;
//	unsigned long long int c = 0;
//	for (unsigned long long int i = 0; i < 1000000000; i++)
//	{
//		arr[i] = 0;
//	}
//	while (n)
//	{
//		cin >> a;
//		if (a == 1)
//		{
//			cin >> b;
//			arr[b]++;
//		}
//		if (a == 2)
//		{
//			cin >> b;
//			cin >> c;
//			unsigned long long int temp = c < arr[b] ? c : arr[b];
//			arr[b] -= temp;
//		}
//		if (a == 3)
//		{
//			unsigned long long int x = 0;
//			unsigned long long int y = 0;
//			for (unsigned long long int i = 0; i < 1000000000; i++)
//			{
//				if (arr[i] != 0)
//				{
//					x = i;
//					break;
//				}
//			}
//
//			for (unsigned long long int i = 1000000000 - 1; i >=0; i--)
//			{
//				if (arr[i] != 0)
//				{
//					y = i;
//					break;
//				}
//			}
//			cout << y-x;
//		}
//		n--;
//	}
//	return 0;
//}
//int main()
//{
//	int h = 0;
//	int w = 0;
//	cin >> h>>w;
//	string* arr = new string[h];
//	for (int i = 0; i < h; i++)
//	{
//		cin >> arr[i];
//	}
//	int a1 = 0;
//	int b1 = 0;
//	int a2 = 0;
//	int b2 = 0;
//	int f = 1;
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			if (arr[i][j] == 'o')
//			{
//				if (f == 1)
//				{
//					a1 = i;
//					b1 = j;
//					f--;
//				}
//				else
//				{
//					a2 = i;
//					b2 = j;
//				}
//				
//			}
//		}
//	}
//	int setp = abs(a1-a2)+abs(b1-b2);
//	cout << setp;
//	return 0;
//
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	string* arr = new string[n * 2];
//	for (int i = 0; i < n * 2; i++)
//	{
//		cin >> arr[i];
//	}
//	int i = 0;
//	while (i<n*2)
//	{
//		int f = 0;
//		for (int j=0; j < n * 2; j++)
//		{
//			if (i == j||j==i+1)
//				continue;
//			if (arr[j] == arr[i])
//			{
//				f++;
//			}
//		}
//		if(f==0)
//			i += 2;
//		else
//		{
//			i++;
//			for (int j = 0; j < n * 2; j++)
//			{
//				if (i == j||j==i-1)
//					continue;
//				if (arr[j] == arr[i])
//				{
//					cout << "No";
//					return 0;
//				}
//			}
//			i++;
//		}
//	}
//	cout << "Yes";
//	return 0;
//}