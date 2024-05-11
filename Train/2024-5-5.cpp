#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int D[200010];
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	for (size_t i = 0; i < n; i++)
	{
		cin >> D[i];
		D[i] = D[i] % (a + b);
	}
	sort(D, D + n);
	int j = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (D[j] != D[i])
			D[++j] = D[i];
	}
	n = j + 1;
	for (size_t i = 0; i < n; i++)
	{
		int nex = D[(i + 1) % n];
		int x = (1ll * D[i] - nex + a + b) % (a + b);
		if (x < a)
		{
			cout << "Y";
			return 0;
		}

	}
	cout << "N";
}
//int main()
//{
//	size_t n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	int nums = 0;
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = i + 1; j < n; j++)
//		{
//			double a = sqrt(v[i] * v[j]);
//			if ((int)a == a)
//				nums++;
//		}
//	}
//	cout << nums;
//	return 0;
//}
//int main()
//{
//	size_t n, a, b;
//	cin >> n >> a >> b;
//	//size_t sum = ;
//	size_t q = 0;
//	if (b == 0)
//	{
//		cout << "Yes";
//		return 0;
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> q;
//		q = q % (a + b);
//		if ( q > a)
//		{
//			cout << "No";
//			return 0;
//		}
//
//	}
//	cout << "Yes";
//	return 0;
//}
//int main()
//{
//	string s;
//	set<string> st;
//	cin >> s;
//	size_t sz = s.size();
//	for (size_t i = 0; i < sz; i++)
//	{
//		for (size_t j = 1; j <= sz-i; j++)
//		{
//			st.insert(s.substr(i, j));
//		}
//	}
//	cout << st.size();
//	return 0;
//}
//int main()
//{
//	size_t n, a, b;
//	cin >> n >> a >> b;
//	size_t sum = ;
//	size_t q = 0;
//	if (b == 0)
//	{
//		cout << "Yes";
//		return 0;
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> q;
//		q = q % (a + b);
//		if (q == 0||q>a)
//		{
//			cout << "No";
//			return 0;
//		}
//
//	}
//	cout << "Yes";
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	map<int, int> m;
//	int w = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		m[temp] = w;
//		w++;
//	}
//	size_t q = 0;
//	cin >> q;
//	int a1 = 0;
//	int b1 = 0;
//	for (size_t i = 0; i < q; i++)
//	{
//		cin >> a1 >> b1;
//		if (m[a1] < m[b1])
//			cout << a1<<endl;
//		else
//			cout << b1<<endl;
//	}
//	return 0;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	size_t index = 0;
//	size_t sz = s.size();
//	int f = 0;
//	while (index < sz-2)
//	{
//		if (s[index] != s[index + 1] && s[index] != s[index + 2])
//		{
//			f = 1;
//			break;
//		}
//		index++;
//	}
//	if (f)
//	{
//		cout << index + 1;
//	}
//	else
//	{
//		if (s[sz - 2] != s[sz - 3] && s[sz - 2] != s[sz - 1])
//			cout << sz-1;
//		else
//			cout << sz ;
//	}
//
//	return 0;
//}
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> v;
//	v.resize(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		if (v[i] % k == 0)
//			cout << v[i] / k << " ";
//	}
//	return 0;
//}