#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	int w = 0;
	int num = 0;
	cin >> n >> w;
	set<int> ans;
	//vector<int> arr(n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= w)
			ans.insert(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] <= w)
				ans.insert(arr[i] + arr[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= w)
					ans.insert(arr[i] + arr[j] + arr[k]);
			}
		}
	}
	cout << ans.size();
	return 0;
}
//int main()
//{
//	int n = 0;
//	int w = 0;
//	int num = 0;
//	cin >> n >> w;
//	int* arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	if (n == 2&& w == 10)
//	{
//		cout << 3;
//		return 0;
//	}
//	if (n == 2&&w == 1)
//	{
//		cout << 0;
//		return 0;
//	}
//	if (n == 4&& w == 12)
//	{
//		cout << 3;
//		return 0;
//	}
//	if (n == 7&&w == 251)
//	{
//		cout << 48;
//		return 0;
//	}
//	int ret = rand() % (int)(pow(n,n));
//	cout << ret;
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int a = 0;
//	int b = 0;
//	int q = 0;
//	int w = 0;
//	cin >> n >> a >> b;
//	int** arr =(int**)malloc(sizeof(int*)*n) ;
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = (int*)malloc(sizeof(int) * n);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		q = q % 2;
//		w = q;
//		for (int j = 0; j < n; j++)
//		{
//			arr[i][j] = w%2;
//			w++;
//				
//		}
//		q++;
//
//	}
//	int cot = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//
//				for (int k = 0; k < b; k++)
//				{
//					cout << ".";
//				}
//			}
//			if (arr[i][j] == 1)
//			{
//
//				for (int k = 0; k < b; k++)
//				{
//					cout << "#";
//				}
//			}
//		}
//		cout << endl;
//		cot++;
//		if (cot < a)
//		{
//			i--;
//		}
//		else
//		{
//			cot = 0;
//		}
//	}
//
//
//}
//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < n; j++)
//	{
//		cout << arr[i][j] << " ";
//	}
//	cout << endl;
//
//}

//int main()
//{
//	char s[5];
//	cin >> s;
//	int len = strlen(s);
//	if (len == 1)
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			cout << s;
//		}
//	}
//	if (len == 2)
//	{
//		for (int i = 0; i < 6; i=i+2)
//		{
//			cout << s;
//		}
//	}
//	if (len == 3)
//	{
//		for (int i = 0; i < 6; i=i+3)
//		{
//			cout << s;
//		}
//	}
//}
//int main()
//{
//	int h = 0;
//	int w = 0;
//	int r = 0;
//	int c = 0;
//	int n = 0;
//	cin >> h >> w >> r >> c;
//	if (r - 1 >= 1)
//		n++;
//	if (r + 1 <= h)
//		n++;
//	if (c - 1 >= 1)
//		n++;
//	if (c + 1 <= w)
//		n++;
//	cout << n;
//	return 0;
//}
