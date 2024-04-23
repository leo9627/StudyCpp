//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<string>
//#include<set>
//#include<vector>
//using namespace std;


//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; i < n; i++)
//		{
//
//		}
//	}
//
//}
//bool f(string s1,string s2)
//{
//	int start = s1.size() + s2.size();
//	set<char> s;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		s.insert(s1[i]);
//	}
//	for (int i = 0; i < s2.size(); i++)
//	{
//		s.insert(s2[i]);
//	}
//	if (start != s.size())
//		return true;
//	return false;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int num=0;
//	int k = 0;
//	cin >> k;
//	string* arr = new string[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (f(arr[i], arr[j]))
//				num++;
//		}
//	}
//	cout << num;
//}
//int main()
//{
//	unsigned long long int a = 0;
//	unsigned long long int b = 0;
//	unsigned long long int k = 0;
//	cin >> a >> b >> k;
//	unsigned long long int n = 0;
//	while (a < b)
//	{
//		a *= k;
//		n++;
//	}
//	cout << n;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	set<char> t;
//	int a = 0;
//	int b = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] >= 65 && s[i] <= 90)
//		{
//			a = 1;
//			t.insert(s[i]);
//		}
//		else
//		{
//			b = 1;
//			t.insert(s[i]);
//		}
//			
//	}
//	if (s.size() != t.size())
//	{
//		cout << "No";
//		return 0;
//	}
//	if (a && b)
//	{
//		cout << "Yes";
//	}
//	else
//	{
//		cout << "No";
//	}
//
//	return 0;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	int n = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		n += (s[i] - 48);
//	}
//	cout << 45 - n;
//}
//int main()
//{
//	unsigned long long int a = 0;
//	unsigned long long int b = 0;
//	unsigned long long int c = 0;
//	unsigned long long int d = 0;
//	unsigned long long int e = 0;
//	unsigned long long int f = 0;
//	unsigned long long int x = 0;
//	cin >> a >> b >> c >> d >> e >> f >> x;
//	unsigned long long int na = (x / (a + c))*a ;
//	unsigned long long int nb = (x / (d + f))*d ;
//	if ((x % (a + c)) >= a)
//	{
//		na += a;
//	}
//	else
//	{
//		na += x % (a + c);
//	}
//	if ((x % (d + f)) >= d)
//	{
//		nb += d;
//	}
//	else
//	{
//		nb += x % (d + f);
//
//	}
//
//
//	unsigned long long int da = na * b;
//	unsigned long long int db = nb * e;
//	if (da > db)
//	{
//		cout << "Takahashi";
//	}
//	else if (da < db)
//	{
//		cout << "Aoki";
//	}
//	else
//	{
//		cout << "Draw";
//	}
//	return 0;
//}