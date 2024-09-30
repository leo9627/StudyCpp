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



struct SkiplistNode
{
    int _data;
    vector<SkiplistNode*> _nextarray;
    SkiplistNode(int data, int n)
        :_data(data)
    {
        _nextarray.resize(n, nullptr);
    }
};
class Skiplist {
    typedef SkiplistNode Node;
public:
    Skiplist() {
        //srand(time(nullptr));
        _head = new Node(-1, 1);
    }

    bool search(int target)
    {
        Node* cur = _head;
        int level = cur->_nextarray.size() - 1;
        while (level >= 0)
        {
            if (cur->_nextarray[level] == nullptr || cur->_nextarray[level]->_data > target)
            {
                //向下走
                --level;
            }
            else if (cur->_nextarray[level]->_data < target)
            {
                //向右走
                cur = cur->_nextarray[level];
            }
            else
                return true;
        }
        return false;
    }

    void add(int num)
    {
        Node* cur = _head;
        int level = cur->_nextarray.size() - 1;
        vector<Node*> v(level + 1, nullptr);
        bool f = false;
        while (level >= 0)
        {
            if (cur->_nextarray[level] == nullptr || cur->_nextarray[level]->_data > num)
            {
                v[level] = cur;
                //向下走
                --level;
            }
            else if (cur->_nextarray[level]->_data < num)
            {
                //向右走
                cur = cur->_nextarray[level];
            }
            else
            {
                v[level] = cur;
                f = true;
                break;
            }
        }
        Node* newNode;
        if(f)
            newNode = new Node(num, level+1);
        else
            newNode = new Node(num, random());
        if(newNode->_nextarray.size()> _head->_nextarray.size())
            _head->_nextarray.resize(newNode->_nextarray.size(), nullptr);
        v.resize(newNode->_nextarray.size(), nullptr);
        for (int i = 0; i < newNode->_nextarray.size(); ++i)
        {
            if (v[i])
            {
                newNode->_nextarray[i] = v[i]->_nextarray[i];
                v[i]->_nextarray[i] = newNode;
            }
            else
            {
                _head->_nextarray[i] = newNode;
            }
        }

    }

    bool erase(int num)
    {
        Node* cur = _head;
        int level = cur->_nextarray.size() - 1;
        vector<Node*> v(level + 1, nullptr);
        while (level >= 0)
        {
            if (cur->_nextarray[level] == nullptr || cur->_nextarray[level]->_data > num)
            {
                //向下走
                --level;
            }
            else if (cur->_nextarray[level]->_data < num)
            {
                //向右走
                cur = cur->_nextarray[level];
            }
            else
            {
                //Node* deletenode = cur->_nextarray[level];
                while (level >= 0)
                {
                    if (cur->_nextarray[level]->_data == num)
                    {
                        v[level] = cur;
                        --level;
                    }
                    else
                    {
                        cur = cur->_nextarray[level];
                    }
                }
                Node* deletenode = v[0]->_nextarray[0];
                for (int i = 0; i < deletenode->_nextarray.size(); ++i)
                {
                    v[i]->_nextarray[i]=deletenode->_nextarray[i];
                }
                delete deletenode;
                return true;
            }
        }
        return false;
    }
    int random()
    {
        int level = 1;
        while (rand() < RAND_MAX * p && level < _maxlevel)
            ++level;
        return level;
    }
private:
    Node* _head;
    int _maxlevel = 32;
    double p = 0.25;
};


int main()
{

    vector<int> v1;
    v1.resize(10,2);
    v1.resize(5,1);


    Skiplist sklt;
    //sklt.erase(9);
    //sklt.add(9);
    //sklt.add(8);
    //sklt.add(8);
    //sklt.erase(8);
    ////sklt.add(9);
    //cout<<sklt.search(9);
    ////cout<<sklt.erase(3);

    /*sklt.add(1);
    sklt.add(2);
    sklt.add(3);
    cout<<sklt.search(0);
    sklt.add(4);
    cout << sklt.search(1);
    cout << sklt.erase(0);
    cout << sklt.erase(1);
    cout << sklt.search(1);
    sklt.add(5);
    sklt.add(6);
    sklt.add(7);
    sklt.add(8);
    sklt.add(9);
    sklt.add(10);
    for(int i=0)
    cout << sklt.search(6);*/
    set<int> v;

    for (int i = 0; i < 1000; ++i)
    {
        int r = rand();
        v.insert(r);
        sklt.add(r);
    }
    for (auto& e : v)
    {
        if (sklt.search(e) == false)
            cout << "No";
    }
    //for (int i = 0; i < 10; ++i)
    {
        for (auto& e : v)
        {
            if (sklt.erase(e) == false)
                cout << "No";
        }
        
    }
    //for (int i = 0; i < 10; ++i)
    {
        for (auto& e : v)
        {
            if (sklt.search(e) == true)
                cout << "No";
        }
    }
    return 0;
}

//set<size_t> arr[200003];
//int col[200003] ;  //全是false
//bool visited[200003] ;  //全是false
//
//
//int main()
//{
//	size_t n = 0;
//	cin >> n;
//	size_t m = 0;
//	cin >> m;
//	for (size_t i = 0; i < m; ++i)
//	{
//		size_t u, v;
//		cin >> u >> v;
//		arr[u].insert(v);
//		arr[v].insert(u);
//	}
//	size_t red = 0;
//	size_t yellow = 0;
//	for (size_t i = 1; i < n + 1; ++i)
//	{
//		if (col[i] != 0)
//			continue;
//		queue<size_t> qe;
//		qe.push(i);
//		bool f = true;
//		visited[i] = true;
//		size_t level = 1;
//		while (!qe.empty())
//		{
//			for (size_t i = 0; i < level; ++i)
//			{
//
//				size_t top = qe.front();
//				if (f)
//				{
//					++red;
//					col[top] = 1;
//				}
//				else
//				{
//					++yellow;
//					col[top] = 2;
//				}
//				qe.pop();
//				for (auto& e : arr[top])
//				{
//					if (visited[e] == false)
//					{
//						qe.push(e);
//						visited[e] = true;
//					}
//				}
//			}
//			f = !f;
//			level = qe.size();
//		}
//	}
//	for (size_t i = 1; i < n + 1; ++i)
//	{
//		int c = col[i];
//		for (auto& e : arr[i])
//		{
//			if (col[e] == c)
//			{
//				cout << 0;
//				return 0;
//			}
//		}
//	}
//	size_t ans=0;
//	for (size_t i = 1; i < n+1; ++i)
//	{
//		if (col[i]==1)
//		{
//			ans += (yellow-arr[i].size());
//		}
//	}
//	cout << ans;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef long long ll;
//vector<int> gp[200005];
//int col[200005];
//vector<int> vert;
//
//// 1：白 2：黑
//bool dfs(int u, int c) {
//    col[u] = c;
//    vert.push_back(u);
//
//    for (int& v : gp[u]) {
//        if (!col[v]) {
//            if (!dfs(v, 3 - c)) return false;
//        }
//        else if (col[v] == c) return false;
//    }
//
//    return true;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        gp[u].push_back(v); // 假设这里不应该反向添加边
//        gp[v].push_back(u); // 如果需要的话取消注释
//    }
//
//    ll ans = 0, tot = 0;
//    int flag = 1;
//    for (int i = 1; i <= n && flag; ++i) {
//        if (col[i] == 0) {
//            vert.clear();
//            if (!dfs(i, 1)) {
//                flag = 0;
//                continue;
//            }
//
//            int cnt[5] = { 0 }, edge_cnt = 0;
//            for (int v : vert) {
//                cnt[col[v]]++;
//                edge_cnt += gp[v].size();
//            }
//            edge_cnt /= 2;
//            ans += (cnt[1] * cnt[2] - edge_cnt);
//            ans += (tot * vert.size());
//            tot += vert.size();
//        }
//    }
//
//    if (!flag) ans = 0;
//    cout << ans;
//    return 0;
//}



//int main()
//{
//	size_t n = 0;
//	cin >> n;
//	scanf("%s", s);
//	bool f = true;
//	for (size_t i = 0; i < n; ++i)
//	{
//		if (s[i] == '"')
//		{
//			f = !f;
//		}
//		if (s[i] == ',' && f)
//			s[i] = '.';
//	}
//	cout << s;
//	return 0;
//}


//int arr[100000];
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		int a = 0;
//		cin >> a;
//		if (a == 2)
//		{
//			int b = 0;
//			cin >> b;
//			cout << arr[b - 1] << endl;
//		}
//		else
//		{
//			int b, c;
//			cin >> b >> c;
//			arr[b - 1] = c;
//		}
//	}
//	return 0;
//}



//bool f(const string& s1, const string& s2)
//{
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		if (s1[i] == 'x' && s2[i] == 'x')
//			return false;
//	}
//	return true;
//}
//
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	string arr[30];
//	for (size_t i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	int ans = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = i+1; j < n; ++j)
//		{
//			if (f(arr[i], arr[j]))
//				++ans;
//		}
//	}
//	cout << ans;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << (size_t)pow(a, b);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	char c = 'A';
//	while (n--)
//	{
//		cout << c;
//		++c;
//	}
//	return 0;
//}