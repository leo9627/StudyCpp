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
typedef long long LL;
using namespace std;

int main()
{
	size_t n, m;
	cin >> n >> m;
	if (m == 0) std::cout << 1;

	set<size_t> ust;
	ust.insert(n);
	vector<pair<size_t, size_t>> v(m);
	for (size_t i = 0; i < m; ++i)
	{
		size_t x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}
	sort(v.begin(), v.end(), [](pair<size_t, size_t> x, pair<size_t, size_t> y) {return x.first < x.second; });
	vector<size_t> sep;
	sep.push_back(0);
	size_t t = v[0].first;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i].first != t)
		{
			t = v[i].first;
			sep.push_back(i);
		}
	}
	sep.push_back(v.size());
	std::unordered_set<int> tmp;
	for (size_t i = 0; i + 1 < sep.size(); ++i)
	{
		for (size_t j = sep[i]; j < sep[i + 1]; ++j)
		{
			size_t x = v[j].first;
			size_t y = v[j].second;
			if (ust.count(y - 1) == 1 || ust.count(y + 1) == 1)
			{
				ust.insert(y);
				tmp.insert(y);
			}
		}
		for (size_t j = sep[i]; j < sep[i + 1]; ++j)
		{
			size_t y = v[j].second;
			if (tmp.count(y) == 0)
				ust.erase(y);
		}
		tmp.clear();
	}
	std::cout << ust.size();
	return 0;
}










//size_t	C[61][61];
//int main()
//{
//	size_t a, b, k;
//	cin >> a >> b >> k;
//	size_t sum = a + b;
//	C[0][0] = 1;
//	for (size_t i = 1; i <=sum; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			if (j == 0) C[i][j] = 1;
//			else
//			{
//				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
//			}
//		}
//	}
//	for (size_t i = 0; i < sum; ++i)
//	{
//		if (a == 0)
//		{
//			cout << 'b';
//			continue;
//		}
//		if (b == 0)
//		{
//			cout << 'a';
//			continue;
//		}
//		if (k > C[sum - i - 1][a - 1])
//		{
//			cout << 'b';
//			b--;
//			k -= C[sum - i - 1][a - 1];
//		}
//		else
//		{
//			cout << 'a';
//			a--;
//		}
//	}
//	return 0;
//}


//int KMP(const string& s,const string t)
//{
//	vector<int> next(t.size(),-1);
//	int i = 0, j = -1;
//	while (i < t.size()-1)
//	{
//		if (j == -1 || t[i] == t[j])
//		{
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else j = next[j];
//	}
//
//	i = 0,j = 0;
//	while (i < s.size())
//	{
//		if (j==-1||s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//
//		if (j == t.size())
//		{
//			return i - j;
//		}
//	}
//	if (j != t.size()) return -1;
//}
//double myPow(double x, int n)
//{
//	if (n == 0) return 1.0;
//	if (n == 1) return x;
//	return myPow(x, (n + 1) / 2) * myPow(x, n / 2);
//}
//int main()
//{
//	string s = "ababefabcabababababababef";
//	string t = "ababef";
//	//cout << KMP(s, t);
//	cout << myPow(2.0, 2);
//	return 0;
//}









//vector<int> a = {2,1,0};
//vector<int> b;
//vector<int> c;
//void _hanota(int n, vector<int>& A, vector<int>& B, vector<int>& C)
//{
//    if (n == 0) return;
//    _hanota(n - 1, A, C, B);
//    C.push_back(A.back());
//    A.pop_back();
//    _hanota(n - 1, B, A, C);
//}
//void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
//{
//    //B.resize(A.size());
//    //C.resize(A.size());
//    _hanota(A.size(), A, B, C);
//}
//int main()
//{
//    hanota( a, b, c);
//	return 0;
//}



//int main()
//{
//	string s;
//	cin >> s;
//	LL len = s.size();
//	vector<int> dp(len + 1);
//	dp[0] = 0;
//	for (LL i = 1; i <= len; ++i)
//		dp[i] = dp[i - 1] + (s[i - 1] - '0');
//	for (LL i = len; i >= 1; --i)
//	{
//		dp[i - 1] += dp[i] / 10;
//		dp[i] %= 10;
//	}
//	for (LL i = dp[0] ? 0 : 1; i <= len; ++i)
//		cout << dp[i];
//}





//LL arr[200008];
//int main()
//{
//	LL n, k;
//	cin >> n >> k;
//	for (LL i = 0; i < n; ++i) cin >> arr[i];
//	LL sum = 0;
//	unordered_map<LL,int> hash;
//	hash[sum] = 1;
//	LL ans = 0;
//	for (LL i = 0; i < n; ++i)
//	{
//		sum += arr[i];
//		if(hash.count(sum-k))
//			ans += hash[sum - k];
//		hash[sum]++;
//	}
//	cout << ans;
//	return 0;
//}





//string countAndSay(int n)
//{
//    string ret = "1";
//    int index = 0;
//    n--;
//    while (n--)
//    {
//        string s;
//        char c = ret[0];
//        cout << c << endl;
//        int number = 0;
//        for (auto& e : ret)
//        {
//            if (e == c)
//                number++;
//            else
//            {
//                char a = '0' + number;
//                s += a;
//                s += c;
//                number = 1;
//                c = e;
//            }
//        }
//        char a = '0' + number;
//        s += a;
//        s += c;
//        ret = s;
//    }
//    return ret;
//}
//
//int main()
//{
//    countAndSay(4);
//    return 0;
//}




//int ufs[200005];
//int FindRoot(int x)
//{
//	while (ufs[x] > 0)
//	{
//		x = ufs[x];
//	}
//	return x;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int m = 0;
//	cin >> m;
//	for (int i = 0; i <= n; ++i)
//	{
//		ufs[i] = -1;
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		int u = 0, v = 0;
//		cin >> u >> v;
//		u = FindRoot(u);
//		v = FindRoot(v);
//		if (abs(v) < abs(u))
//			swap(u, v);
//		if (u != v)
//		{
//			ufs[u] += ufs[v];
//			ufs[v] = u;
//		}
//	}
//	int k = 0;
//	cin >> k;
//	set<pair<int, int>> ump;
//	for (int i = 0; i < k; ++i)
//	{
//		int u, v;
//		cin >> u >> v;
//		u = FindRoot(u);
//		v = FindRoot(v);
//		if (u < v)
//			swap(u, v);
//		ump.insert({ u,v });
//	}
//	int q = 0;
//	cin >> q;
//	while (q--)
//	{
//		int u, v;
//		cin >> u >> v;
//		u = FindRoot(u);
//		v = FindRoot(v);
//		if (u < v)
//			swap(u, v);
//		if (ump.count(make_pair(u, v)))
//			cout << "No\n";
//		else
//			cout << "Yes\n";
//	}
//
//	return 0;
//}






//pair<size_t, size_t> cake[200000];
//int main()
//{
//	size_t w, h;
//	cin >> w >> h;
//	size_t n = 0;
//	cin >> n;
//	for (size_t i = 0; i < n; ++i)
//	{
//		int p, q;
//		cin >> p >> q;
//		cake[i] = { p,q };
//	}
//	size_t a = 0;
//	cin >> a;
//	vector<size_t> x(a+1);
//	for (size_t i = 0; i < a; i++)
//		cin >> x[i];
//	x[a] = w;
//	size_t b = 0;
//	cin >> b;
//	vector<size_t> y(b + 1);
//	for (size_t i = 0; i < b; ++i)
//		cin >> y[i];
//	y[b] = h;
//	unordered_map<size_t, size_t> ump;
//	for (size_t i=0;i<n;i++)
//	{
//		auto& ca = cake[i];
//		size_t x1 = upper_bound(x.begin(), x.end()-1, ca.first)-x.begin();
//		int y1 = upper_bound(y.begin(), y.end()-1, ca.second)-y.begin();
//		size_t index = x1 + y1 * (a + 1);
//		ump[index]++;
//	}
//	size_t min = n;
//	size_t max = 0;
//	for (auto& e : ump)
//	{
//		if (e.second > max)
//			max = e.second;
//		if (e.second < min)
//			min = e.second;
//	}
//	if (ump.size() < (a + 1) * (b + 1))
//		min = 0;
//	cout << min << " " << max;
//	return 0;
//}





//const size_t mod = 1000000007; // 假设模数为1e9+7
//vector<pair<long long, long long>> edge[100001]; // 假设最多有100000个节点
//bool visited[100001]; //= { 0 }; // 访问标记数组
////long long a[100001]; // 节点的权重数组
//long long dist[100001]; // 从根节点到各节点的距离


//const size_t mod = 1e9+7;
//bool visited[200005];
//long long dist[200005];
//vector<vector<pair<long long, long long>>> edge;
//void dfs(long long n)
//{
//	if (visited[n])
//		return;
//	visited[n] = true;
//	for (auto& e : edge[n])
//	{
//		//if (visited[e.first]==false)
//		{
//			dist[e.first] = dist[n] ^ e.second;
//			dfs(e.first);
//		}
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	edge.resize(n + 1);
//	for (int i = 1; i <n; ++i)
//	{
//		long long u, v, w;
//		cin >> u >> v >> w;
//		edge[u].push_back(make_pair(v, w));
//		edge[v].push_back(make_pair(u, w));
//	}
//	dfs(1);
//	long long ans = 0;
//	for (int i = 0; i < 64; ++i)
//	{
//		long long sum = 0;
//		for (int j = 1; j <= n; ++j)
//		{
//			sum += ((dist[j] >> i) & 1);
//		}
//		ans = (ans + (1ll << i)%mod * sum%mod * (n - sum)%mod) % mod;
//	}
//	cout << ans%mod;
//	return 0;
//}
//const int mod = 1000000007; // 假设模数为1e9+7
//vector<pair<long long, long long>> e[100001]; // 假设最多有100000个节点
//int vis[100001] = { 0 }; // 访问标记数组
//long long a[100001]; // 节点的权重数组
//long long dist[100001]; // 从根节点到各节点的距离
//
//void dfs(int x) {
//	if (vis[x]) return;
//	vis[x] = 1;
//	for (int i = 0; i < e[x].size(); i++) {
//		long long next = e[x][i].first;
//		long long weight = e[x][i].second;
//		a[next] = a[x] ^ weight;
//		dfs(next);
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i < n; i++) {
//		long long u, v, w;
//		cin >> u >> v >> w;
//		e[u].push_back(make_pair(v, w));
//		e[v].push_back(make_pair(u, w));
//	}
//
//	dfs(1); // 假设1是根节点
//
//	long long ans = 0;
//	for (int i = 0; i < 64; i++) {
//		long long sum = 0;
//		for (int j = 1; j <= n; j++) {
//			sum += ((a[j] >> i) & 1);
//		}
//		ans = (ans + (((1LL << i) % mod) * sum % mod * (n - sum) % mod)) % mod;
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}



//int arr[200];
//int cnt[200];
//int ct[200];
//int bitcount(int n)
//{
//	int ret = 0;
//	for (int i = 0; i < 32; ++i)
//	{
//		if (1 & (n >> i))
//			ret++;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//		arr[i] %= 200;
//		cnt[arr[i]]++;
//		if (cnt[arr[i]] == 2)
//		{
//			cout << "Yes\n";
//			for (int j = 0; j < i; j++)
//			{
//				if (arr[i] == arr[j])
//				{
//					cout << 1<<" " << i+1 << "\n1 " << j+1;
//					return 0;
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i < (1<<min(8, n)); ++i)//枚举
//	{
//		int sum = 0;
//		for (int j = 0; j < 8; ++j)
//		{
//			if (1 & (i >> j))
//				sum = (sum + arr[j]) % 200;
//		}
//		if (ct[sum])
//		{
//			cout << "Yes\n";
//			cout << bitcount(i) << " ";
//			for (int j = 0; j < 8; j++)
//			{
//				if (1 & (i >> j))
//					cout << j + 1 << " ";
//			}
//			cout << endl;
//
//			cout << bitcount(ct[sum]) << " ";
//			for (int j = 0; j < 8; j++)
//			{
//				if (1 & (ct[sum] >> j))
//					cout << j + 1 << " ";
//			}
//			return 0;
//		}
//		ct[sum] = i;
//	}
//	cout << "No";
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	cin >> n;
//	int x = 0;
//	int y = 0;
//	int a1 = 0;
//	cin >> a1;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int t = 0;
//		cin >> t;
//
//		if (abs(t) < abs(a1) && t > 0)
//		{
//			x++;
//		}
//		else if (abs(t) > abs(a1) && t < 0)
//		{
//			y++;
//		}
//	}
//	if (a1 < 0 && x == 0)
//		cout << 1;
//	else if (a1 > 0 && y == 0)
//		cout << 1;
//	else
//		cout << x + y + 1;
//	return 0;
//}




//int main()
//{
//	int w, n, m;
//	cin >> w >> m >> n;
//	int mh = m / w;
//	if (m % w != 0)
//		++mh;
//	int nh = n / w;
//	if (n % w != 0)
//		++nh;
//
//	int max = w * mh;
//	int ml = 0;
//	if (mh % 2 == 0)
//	{
//		ml = max - m+1;
//	}
//	else
//	{
//		ml = w-(max - m );
//	}
//
//	max = w * nh;
//	int nl = 0;
//	if (nh % 2 == 0)
//	{
//		nl = max - n + 1;
//	}
//	else
//	{
//		nl = w - (max - n);
//	}
//
//	cout << abs(mh - nh) + abs(ml - nl);
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ans = n;
//	while (n/3)
//	{
//		ans += n / 3;
//		n = n % 3 + n / 3;
//	}
//	cout << ans;
//	return 0;
//}









//string a, b;
//int main()
//{
//	cin >> a >> b;
//	int l = a.size(), s = 0, i;
//	for (i = 0; i < l; i++)
//	if (a[i] != b[i])
//	{
//		a[i] = a[i] == 'o' ? '*' : 'o';
//		a[i + 1] = a[i + 1] == 'o' ? '*' : 'o';
//		s++;
//	}
//	printf("%d\n", s);
//	return 0;
//}
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
//		//	//奇数
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