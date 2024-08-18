#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<thread>
#include<Windows.h>

using namespace std;

//final 和 override 的使用
//class Bassic
//{
//public:
//	int _x;
//	virtual void f1()//final
//	{
//		cout << "Bassic f1\n";
//	}
//	virtual void f2()
//	{
//		cout << "Bassic f2\n";
//	}
//};
//
//class Inher:public Bassic
//{
//public:
//	void f1()//override
//	{
//		cout << "f1\n";
//	}
//	void f2()//override
//	{
//		cout << "f2\n";
//	}
//};
//int main()
//{
//
//	int c = 10;
//	const int& a = 10;
//	int&& b = move(c);
//	b = 20;
//	return 0;
//}


//decltype特性
//template<class T1,class T2>
//auto add(T1 x, T2 y)->decltype(x+y)
//{
//	return (double)x+y;
//}
//
//int main()
//{
//	auto ret= add(2, 3);
//	int x = 10;
//	int y = 20;
//	auto c = x + y;
//	string s;
//	decltype(s) d;
//	//d是变量，不是类型
//	d = "hahah";
//	cout << typeid(d).name() << endl;
//	decltype((x)) z=x;  //这里的z是左值引用的变量
//	cout << x << endl;
//	z = 99;
//	cout << x << endl;
//	return 0;
//}


//自定义类型的默认成员函数控制 default和delete
//class A
//{
//public:
//	int _x;
//public:
//	A() = default;//使用默认的构造函数
//	A(int x) :_x(x)
//	{
//		cout << "A(int x)\n";
//	}
//	A& operator=(const A& x)=delete;
//};
//int main()
//{
//	A b;//使用默认的构造函数
//	A a(2);
//	b._x = 6;
//	cout << b._x << endl;
//	b = a;  //赋值函数被删除
//	cout << b._x;
//	return 0;
//}


//列表初始化
//struct A
//{
//private:
//	int _x;
//	int _y;
//public:
//	A(int x)
//	{
//
//	}
//	A(initializer_list<int> l)
//	{
//		auto it = l.begin();
//		_x = *it;
//		++it;
//		_y = *it;
//	}
//	void Show()
//	{
//		cout << this->_x << " " << this->_y << endl;
//	}
//};
//int main()
//{
//	A a = { 2,4 };
//	int b { 2 };
//	b = { 3 };
//	string s = { "hello world" };
//	cout << b<<endl;
//	cout << s << endl;
//	a.Show();
//	vector<int> v = { 1,2,3 };
//	for (auto& e : v)
//		cout << e << " ";
//	cout << endl;
//	int* arr = new int[5]{ 1,2,3,4,5 };
//	A* p = (A*)malloc(sizeof(A));
//	p->Show();
//	free(p);
//	return 0;
//}


//左值引用
//template<class T>
//void f(const T& x)
//{
//	cout << "f(const T& x)\n";
//}
//
//template<class T>
//void f(const T&& x)
//{
//	cout << "f(const T&& x)\n";
//}
//
//
//int main()
//{
//	int a = 10;
//	//调用不同的函数，使用左值引用和右值引用来进行区分
//	f(a);
//	f(10);
//	return 0;
//}

//在String类中使用右值引用来提高效率
// 移动拷贝和移动赋值，STL容器里使用来提高效率
//class String
//{
//	friend ostream& operator<<(ostream& out, const String& s);
//public:
//	String(const char* str = "")
//	{
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//	{
//		cout << "拷贝构造" << endl;
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//	String(String&& s) noexcept  //移动拷贝，效率高
//		:_str(nullptr)
//	{
//		cout << "移动拷贝"<<endl;
//		swap(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this == &s)
//			return *this;
//		cout << "operator=(String s)"<<endl;
//		delete[] _str;
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//		return *this;
//	}
//	String& operator=(String&& s) noexcept  //移动赋值，效率高
//	{
//		cout << "operator=(String&& s)" << endl;
//		swap(_str, s._str);
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//			delete[] _str;
//	}
//
//private:
//	char* _str;
//};
//ostream& operator<<(ostream& out,const String& s)
//{
//	out << s._str;
//	return out;
//}
//
//
//String f(const char* str)
//{
//	int a = 0;
//	String temp(str);
//	String ret(temp);
//	srand(time(0));
//	return ret;
//	/*if (rand()%10)
//	{
//		return temp;
//	}
//	else
//	{
//		return ret;
//	}*/
//}
//void f1(int&& a)
//{
//	int b = 10;
//	int* p = new int;
//}
//String f()
//{
//	int b = 0;
//	cout << &b << endl;
//	String a;
//	cout << &a << endl;
//	String s;
//	cout << &s << endl;
//	int c = 0;
//	cout << &c << endl;
//	if (rand() % 10)
//		return a;
//	else
//		return s;
//}
//int a1 = 0;
//const char* str1 = "hello";
//int main()
//{
//	String s1("hello world");
//	String s2(f("HELLO LEO"));  //使用了右值构造函数
//	String s3;
//	s3 = f("hello leo");//使用了右值赋值函数
//	cout << s1<<endl;
//	cout << s2<<endl;
//	//cout << s3<<endl;
//	return 0;
//}
//STL里面的右值函数的应用
//int main()
//{
//	vector<pair<string, string>> v;
//	pair<string, string> data = { "water","水" };
//	v.push_back(data);						  //调用左值引用的版本
//	v.push_back(make_pair("apple", "苹果"));  //调用右值引用的版本，提高效率
//	v.push_back(pair<string, string>("left", "左边"));
//	v.emplace_back("right", "右边"); //最能体现emplace_back的地方
//	for (auto& e : v)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//}

//完美转发

//void Func(int& x) { cout << "Func(int& x)\n"; };
//void Func(const int& x) { cout << "Func(const int& x)\n"; };
//void Func(int&& x) { cout << "Func(int&& x)\n"; };
//void Func(const int&& x) { cout << "Func(const int&& x)\n"; };
//
//template<class T>
//void P(T&& x)
//{
//	//Func(x);  //右值引用在这里会退化成左值引用
//	Func(forward<T>(x));
//}
//
//
//int main()
//{
//	P(10);
//	int a = 10;
//	P(a);
//	P(move(a));
//	const int b = 10;
//	P(b);
//	P(move(b));
//	return 0;
//}

/*//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}
//// 展开函数
//template <class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " ";
//	ShowList(args...);
//}
// int main()
// {
//	 ShowList(1);
//	 ShowList(1, 'A');
//	 ShowList(1, 'A', std::string("sort"));
//	 return 0;
// }


template <class T>
int PrintArg(T t)
{
	cout << t << " ";
	return 0;
}
//展开函数
template <class ...Args>
void ShowList(Args... args)
{
	1.2, 3;
	//((PrintArg(args))...);
	//(PrintArg(args), 0)...;
	////(PrintArg(1), PrintArg(2), PrintArg(3),);
	////int arr[] = { ((PrintArg(args), 0),1)... };
	int arr[] = { PrintArg(args)... };
	//(PrintArg(1), 0), (PrintArg('A'), 0), (PrintArg(std::string("sort")), 0);
	//int arr[] = { (PrintArg(1), 0), (PrintArg('A'), 0), (PrintArg(std::string("sort")), 0) };
	//int arr[] = { 1,2, };
	//cout<<sizeof...(args);
	cout << endl;
}
 int main()
 {
	 ShowList(1);
	 ShowList(1, 'A');
	 ShowList(1, 'A', std::string("sort"));
	 return 0;
 }*/




//int main()
//{
//	auto f1 = [](int x, int y)->int {return x + y; };
//	cout << typeid(f1).name()<<endl<<f1(2, 3)<<endl;
//	int a = 1;
//	int b = 2;
//	auto f2 = [&a, &b] {int x = a; a = b; b = x; };
//	f2();
//	a;
//	cout << a << " " << b;
//	return 0;
//}

//struct Goods
//{
//	string _name;
//	double _price;
//	int _nums;
//};
//struct Compare
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._name < g2._name;
//	}
//};
//int main()
//{
//	Goods arr[] = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//	sort(arr,
//		arr + sizeof(arr) / sizeof(arr[0]), 
//		[](const Goods& g1, const Goods& g2)->bool {
//			return g1._price < g2._price;
//		});
//	auto f1 = [](const Goods& g1, const Goods& g2)->bool {
//		return g1._nums < g2._nums;
//		};
//	sort(arr, arr + sizeof(arr) / sizeof(arr[0]), f1);
//	return 0;
//}


//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	cout << typeid(f).name() << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//int main()
//{
//	struct Functor
//	{
//		double operator()(double d)
//		{
//			return d / 3;
//		}
//	};
//		// 函数名
//	function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	// 函数对象
//	function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	// lamber表达式
//	function<double(double)> func3 = [](double d)->double { return d /4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}


//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int main()
//{
//	//function<int(int,int,int)> f1 = 
//	function<int(int, int, int)> f=	bind(sub, placeholders::_2,  placeholders::_1);
//	cout<<typeid(f).name();
//	//cout << f1(2,1,5);
//	return 0;
//}

//template<class T>
//int PrintArg(T&& x)
//{
//	cout << x << endl;
//	return 0;
//}


//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
// 
//
//
//// 编译推演生成下面的函数
////void ShowList(int x, char y, std::string z)
////{
////	int arr[] = { PrintArg(x),PrintArg(y),PrintArg(z) };
////	cout << endl;
////}
//
//int main()
//{
//	//ShowList(1);
//	//ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}


class A
{
public:
	static void f1(int a, int b)
	{
		cout << "f1" << endl;
	}
	void f2(int a, int b)
	{
		cout << "f2" << endl;
	}
};
#include<functional>
#include<map>

//int main()
//{
//	function<void(int, int)> f1 = &A::f1;
//	f1(1, 2);
//	function<void(A,int, int)> f2 = &A::f2;  //非静态成员函数
//	function<void(A&&, int, int)> f3 = &A::f2;
//	function<void(A*, int, int)> f4 = &A::f2;
//	f2(A(),1, 2);
//	f3(A(),1, 2);
//	A a;
//	f4(&a,1, 2);
//
//	return 0;
//}


int Div(int a, int b)
{
	return a / b;
}
class Sub
{
public:
	Sub(int&& x)
		:_x(x)
	{}
	int operator()(int a, int b)
	{
		return (a - b) * _x;
	}
private:
	int _x;
};


int x5()
{
	function<int(int)> Half = bind(Div, placeholders::_1, 2);
	cout << Half(4)<<endl;

	cout << Sub(10)(4, 2);

	map<string, function<int(int, int)>> mp{
		{"+",[](int a,int b)->int {return a + b; }},
		{"/",[](int a,int b)->int {return a / b; }},
		{"*",[](int a,int b)->int {return a * b; }},
		{"-",bind(Sub(1),placeholders::_1,placeholders::_2) }
	};
	while (true)
	{
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;
		cout << mp[s](a, b);
	}
	
	return 0;
}



int main()
{
	int a = 10;
	thread t1 = thread([&] {

		a += 20;
	});
	thread t2 = thread([&] {

		a += 30;
	});
	Sleep(1);

	cout << a<<endl;
	Sleep(100);
	cout << a << endl;
	t1.join();
	t2.join();
	return 0;
}