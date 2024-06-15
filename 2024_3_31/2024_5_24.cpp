#include<iostream>
#include<fstream>
using namespace std;
int n = 5;

int f()
{
    n = n * 2;
    return n;
}
int f1()
{
    n = n - 2;
    return n;
}


struct A
{
    int a;
    A(int x)
    {
        a = x;
    }
    int operator+(const A& x)const
    {
        return a + x.a;
    }
};
//int main()
//{
//    n = f1()+f()+n;
//    cout << n << endl;
//    return 0;
//}

//int main()
//{
//    ofstream out("1.txt");
//    //out << nounitbuf;
//    for (int i = 0; i < 1000; i++)
//    {
//        out << i << "hello word\n";
//        out << flush;
//    }
//    abort();
//    out.close();
//    return 0;
//}

#include<iostream>
#include<queue>
using namespace std;

const size_t mod = 1e9 + 7;
int gcd(int x, int y)
{
    int max = x;
    int min = y;
    if (y > x)
    {
        max = y;
        min = x;
    }
    while (min)
    {
        int temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}
struct cmp
{
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return x.first > y.first;
    }
};

int main()
{
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> cnt;
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        cnt.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        val.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(val[i], cnt[i]));
    }
    size_t sum = 0;
    while (k--)
    {
        int _cnt = pq.top().second;
        int _val = pq.top().first;
        pq.pop();
        if (_cnt == 0)
        {
            k++;
            continue;
        }
        sum += (_val%mod);
        _cnt--;
        _val = _val + x + (gcd(_val, y));
        pq.push(make_pair(_val, _cnt));
    }
    cout << sum%mod;
    return 0;
}