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

int main()
{
    ofstream out("1.txt");
    //out << nounitbuf;
    for (int i = 0; i < 1000; i++)
    {
        out << i << "hello word\n";
        out << flush;
    }
    abort();
    out.close();
    return 0;
}