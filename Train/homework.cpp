#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<bitset>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include <iomanip>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
const size_t mod = 998244353;

string a, b;
int main()
{
	cin >> a >> b;
	int l = a.size(), s = 0, i;
	for (i = 0; i < l; i++)
	if (a[i] != b[i])
	{
		a[i] = a[i] == 'o' ? '*' : 'o';
		a[i + 1] = a[i + 1] == 'o' ? '*' : 'o';
		s++;
	}
	printf("%d\n", s);
	return 0;
}
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	int ans = 0;
//	for (int i = 0; i < s1.length()-1; ++i)
//	{
//		if (s1[i] != s2[i])
//		{
//			ans++;
//			if (s1[i] == 'o')
//				s1[i] = '*';
//			if (s1[i] == '*')
//				s1[i] = 'o';
//			if (s1[i+1] == 'o')
//				s1[i+1] = '*';
//			if (s1[i+1] == '*')
//				s1[i+1] = 'o';
//		}
//	}
//	cout << ans;
//	return 0;
//}


//struct Edge
//{
//	int dist;
//	int w;
//};
//
//void DFS(int cur, int father, int distance,int* dist, vector<Edge>* v)
//{
//	dist[cur] = distance;
//	for (auto& e : v[cur])
//	{
//		if (e.dist != father)
//		{
//			DFS(e.dist, cur, distance + e.w, dist, v);
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<Edge> v[100001];
//	int dist[100001];
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a].push_back({ b,c });
//		v[b].push_back({ a,c });
//	}
//	DFS(1, -1, 0, dist, v);
//	int maxindex = 1;
//	for (int i = 2; i < n + 1; ++i)
//	{
//		if (dist[i] > dist[maxindex])
//			maxindex = i;
//	}
//	DFS(maxindex, -1, 0,dist, v);
//	maxindex = 1;
//	for (int i = 2; i < n + 1; ++i)
//	{
//		if (dist[i] > dist[maxindex])
//			maxindex = i;
//	}
//	size_t ans = dist[maxindex];
//	cout << (21+ans)*ans/2;
//	return 0;
//}



//int main()
//{
//	int N = 0;
//	cin >> N;
//	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
//	int ans = 0;
//	do
//	{
//		for (int i = 0; i < 7; ++i)
//		{
//			int a = 0;
//			int n = 1;
//			for (int k = i; k >= 0; --k)
//			{
//				a += v[k] * n;
//				n *= 10;
//			}
//			for (int j = i + (9 - i) / 2 + 1; j < 9; ++j)
//			{
//				int b = 0;
//				n = 1;
//				for (int k = j-1; k >= i+1; --k)
//				{
//					b += v[k] * n;
//					n *= 10;
//				}
//				int c = 0;
//				n = 1;
//				for (int k = 8; k >= j; --k)
//				{
//					c += v[k] * n;
//					n *= 10;
//				}
//				if (b%c==0 && a + b / c == N)
//					++ans;
//			}
//		}
//	} while (next_permutation(v.begin(), v.end()));
//	cout << ans;
//	return 0;
//}


//int main()
//{
//	size_t t = 0;
//	cin >> t;
//	vector<size_t> v(100005,0);
//	size_t min = 100000;
//	size_t max = 0;
//	cin.get();
//	while (t--)
//	{
//		string s;
//		getline(cin, s);
//		stringstream sin(s);
//		size_t a = 0;
//		while (sin >> a)
//		{
//			++v[a];
//			if (a < min)
//				min = a;
//			if (a > max)
//				max = a;
//		}
//	}
//	size_t m = 0;
//	size_t n = 0;
//	for (size_t i = min; i <= max; ++i)
//	{
//		if (v[i] == 0)
//			m = i;
//		if (v[i] == 2)
//			n = i;
//	}
//	cout << m << " " << n;
//	return 0;
//}


//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		int n = 0;
//		int m = 0;
//		cin >> n >> m;
//		if (n == 1)
//			cout << 0 << endl;
//		else if (n == 2)
//			cout << m << endl;
//		else
//			cout << 2 * m << endl;
//	}
//	return 0;
//}





//void solve()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	unordered_map<int,int> ust;
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		cin >> t;
//		v[i]=t;
//		ust[t]++;
//	}
//	int ans = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		int sum = v[i];
//		for (int j = i + 1; j < n; j++)
//		{
//			sum += v[j];
//			if (ust.find(sum) != ust.end())
//			{
//				ans += ust[sum];
//				ust[sum] = 0;
//			}
//		}
//	}
//	cout << ans << endl;
//
//}
//
//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//		solve();
//	return 0;
//}



//void solve()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int left = 0;
//	int right = n - 1;
//
//	int leftsum = 0;
//	int rightsum = 0;
//	int t = 0;
//	int round = 0;
//	while (left <= right)
//	{
//		int sum = 0;
//		for (; left <= right;)
//		{
//			sum += v[left++];
//			if (sum > t)
//				break;
//		}
//		if (sum)
//		{
//			leftsum += t = sum;
//			++round;
//		}
//
//		sum = 0;
//		for (; right >= left; )
//		{
//			sum += v[right--];
//			if (sum > t)
//				break;
//		}
//		if (sum)
//		{
//			rightsum += t = sum;
//			++round;
//		}
//	}
//	cout << round << " " << leftsum << " " << rightsum << endl;
//}
//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//		solve();
//	
//	return 0;
//}


//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		size_t n, k;
//		cin >> n >> k;
//		size_t tk = k;
//		size_t d = k / n;
//		while (d)
//		{
//			k += d;
//			d = tk - (k - k / n);
//		}
//		cout << k<<endl;
//	}
//	return 0;
//}

//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		long long n, k;
//		cin >> n >> k;
//		if ((n - k) >= 0 && (n - k) % 2 == 0)
//		{
//			cout << "Yes" << endl;
//			for (long long i = 0; i < k - 1; ++i)
//			{
//				cout << "1 ";
//			}
//			cout << n - (k - 1) << endl;
//		}
//		else
//		{
//			if ((n - 2 * k) >= 0 && (n - 2 * k) % 2 == 0)
//			{
//				cout << "Yes" << endl;
//				for (long long i = 0; i < k - 1; ++i)
//				{
//					cout << "2 ";
//				}
//				cout << n - (2 * (k - 1)) << endl;
//			}
//			else
//			{
//				cout << "No" << endl;
//			}
//		}
//		//if (n < k && n < 2 * k)
//		//{
//		//	cout << "No" << endl;
//		//}
//		//else
//		//{
//		//	//ÆæÊý
//		//	if ((n-k)>=0&&(n - k) % 2 == 0)
//		//	{
//		//		cout << "Yes"<<endl;
//		//		for (long long i = 0; i < k - 1; ++i)
//		//		{
//		//			cout << "1 ";
//		//		}
//		//		cout << n - (k - 1) << endl;
//		//	}
//		//	else
//		//	{
//		//		if ((n-2*k)>=0&&(n - 2 * k) % 2 == 0)
//		//		{
//		//			cout << "Yes" << endl;
//		//			for (long long i = 0; i < k - 1; ++i)
//		//			{
//		//				cout << "2 ";
//		//			}
//		//			cout << n - (2*(k - 1)) << endl;
//		//		}
//		//		else
//		//		{
//		//			cout << "No" << endl;
//		//		}
//		//	}
//		//}
//	}
//	return 0;
//}



//void solve()
//{
//	string s;
//	cin >> s;
//	vector<int> v;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != '0')
//		{
//			v.push_back((s[i] - '0') * (int)pow(10, s.size() - i - 1));
//		}
//	}
//	cout << v.size() << endl;
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//int main() 
//{
//	int n = 0;
//	cin >> n;
//	while (n--)
//		solve();
//	return 0;
//}



//void Sw(string& s, size_t a, size_t b)
//{
//	size_t len = s.size();
//	reverse(s.begin()+a-1, s.end()-(len-b));
//}
//
//
//int main()
//{
//	size_t t = 0;
//	cin >> t;
//	while (t--)
//	{
//		size_t n, k;
//		cin >> n >> k;
//		string s;
//		cin >> s;
//		vector<size_t> l;
//		vector<size_t> r;
//		l.resize(k);
//		r.resize(k);
//		for (size_t i = 0;i < k; i++)
//		{
//			cin >> l[i];
//		}
//		for (size_t i = 0; i < k; i++)
//		{
//			cin >> r[i];
//		}
//		size_t q = 0;
//		cin >> q;
//		while (q--)
//		{
//			size_t x = 0;
//			cin >> x;
//			size_t i = 0;
//			while ((l[i]>x || r[i]<x)&&i<k)
//				++i;
//			if (!(l[i]>x ||r[i]<x))
//			{
//				size_t max = x;
//				size_t min = l[i] + r[i] - x;
//				if (max == min)
//				{
//
//				}
//				else
//				{
//					if (min > max)
//						swap(max, min);
//					Sw(s, min, max);
//				}
//				
//			}
//		}
//		cout << s << endl;
//	}
//	return 0;
//}

//int main()
//{
//
//	long long t = 0;
//	cin >> t;
//	while (t--)
//	{
//		long long n, k, x;
//		cin >> n >> k >> x;
//		if (k > n)
//		{
//			cout << "No" << endl;
//		}
//		else
//		{
//			long long min = (1 + k) * k / 2;
//			long long max = (n-k+1+n) * k / 2;
//			if (x >= min && x <= max)
//				cout << "Yes\n";
//			else
//				cout << "No\n";
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int t = 0;
//	cin >> t;
//	vector<int> v;
//	v.reserve(t);
//	int max = 0;
//	while (t--)
//	{
//		int temp = 0;
//		cin >> temp;
//		if (temp > max)
//			max = temp;
//		v.push_back(temp);
//	}
//	vector<int> ret;
//	ret.resize(max);
//	ret[0] = 1;
//	ret[1] = 3;
//	for (int i = 2; i < max; i++)
//	{
//		ret[i] = ret[i - 1] + 1;
//		while (ret[i] * 3 % (ret[i - 1] + ret[i - 2])==0)
//		{
//			++ret[i];
//		}
//	}
//	for (auto& e : v)
//	{
//		for (int i = 0; i < e; i++)
//		{
//			cout << ret[i] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		int n, k;
//		cin >> n >> k;
//		int f = 1;
//		while (n--)
//		{
//			int t = 0;
//			cin >> t;
//			if (t == k)
//			{
//				f = 0;
//			}
//		}
//		if (f)
//			cout << "No" << endl;
//		else
//			cout << "Yes" << endl;
//	}
//	return 0;
//}