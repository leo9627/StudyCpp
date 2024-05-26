#include<iostream>
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
int main()
{
    n = f1()+f()+n;
    cout << n << endl;
    return 0;
}