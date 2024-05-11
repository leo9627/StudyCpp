#include"biginteger.h"
#include<iostream>
using namespace std;
int main()
{
	string x;
	string y;
	cin >> x >> y;
	string ret = Add(x, y);
	cout << "Add:" << ret << endl;
	string ret1 = Sub(x, y);
	cout << "Sub:" << ret1 << endl;
	string ret2 = Mul(x, y);
	cout << "Mul:" << ret2 << endl;
	string ret3 = Div(x, y);
	cout << "Div:" << ret3 << endl;
	string ret4 = Mod(x, y);
	cout << "Mod:" << ret4 << endl;
	return 0;
}