#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;

struct Node
{
	long long degree;
	vector<long long> Nv;
};
vector<Node*> v(1000001, nullptr);
vector<Node*> v1(1000001, nullptr);
vector<long long> v2;
long long ms, ns, bs;
queue<long long> qe;

void mydelete(long long k)
{
	while (!qe.empty())
	{
		long long inode = qe.front();
		if (v1[inode]->degree==0 || v1[inode]->degree > k)
		{
			qe.pop();
			continue;
		}

		for (auto e : v1[inode]->Nv)
		{
			if (v1[e]->degree!=0)
			{
				v1[e]->degree--;
				ns--;
				qe.push(e);
			}
		}
		v1[inode]->degree = 0;
		v1[inode]->Nv.clear();
		qe.pop();
	}
}
bool cmp(long long x, long long y)
{
	return v1[x]->degree > v1[y]->degree;
}
int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long M, N, B;
	scanf("%lld %lld %lld", &M, &N, &B);
	for (long long i = 0; i < m; i++)
	{
		long long a, b;
		cin >> a >> b;
		if (v[a] == nullptr)
		{
			v[a] = new Node;
			v[a]->degree = 1;
			v[a]->Nv.push_back(b);
			v1[a] = new Node;
			v1[a]->degree = 1;
			v1[a]->Nv.push_back(b);
		}
		else
		{
			v[a]->degree++;
			v[a]->Nv.push_back(b);
			v1[a]->degree++;
			v1[a]->Nv.push_back(b);
		}
		if (v[b] == nullptr)
		{
			v[b] = new Node;
			v[b]->degree = 1;
			v[b]->Nv.push_back(a);
			v1[b] = new Node;
			v1[b]->degree = 1;
			v1[b]->Nv.push_back(a);
		}
		else
		{
			v[b]->degree++;
			v[b]->Nv.push_back(a);
			v1[b]->degree++;
			v1[b]->Nv.push_back(a);
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		if (v[i])
		{
			v2.push_back(i);
		}
			
	}
	
	map<long long, long long> _map;
	ns = m;
	bs = 0;
	long long maxscore = 0;
	int f = 1;
	while (!v2.empty())
	{
		sort(v2.begin(), v2.end(), cmp);
		long long k = 0;
		if (v1[v2[0]]->degree ==0)
			break;
		for (long long i = v2.size() - 1; i >= 0; i--)
		{
			if (v1[v2[i]]->degree != 0)
			{
				k = v1[v2[i]]->degree;
				v2.resize(i + 1);
				break;
			}
		}

		ms = v2.size();
		bs = 0;
		for (auto e : v2)
		{
			for (auto j : v[e]->Nv)
			{
				if (v1[j] ->degree==0)
					bs++;
			}
		}
		//计算分数
		long long score = M * ns - N * ms + B * bs;
		if (f)
		{
			maxscore = score;
			f--;
		}
		_map[score] = k;
		if (score > maxscore)
			maxscore = score;

		//删除点
		if (v1[v2[0]]->degree == v1[v2[v2.size() - 1]]->degree)
			break;



		for (long long i = v2.size() - 1; i >= 0; i--)
		{
			if (v1[v2[i]]->degree == k)
			{

				qe.push(v2[i]);
				v2.pop_back();
			}
			else
				break;
		}
		mydelete(k);

	}
	printf("%lld %lld", _map[maxscore], maxscore);
	return 0;
}