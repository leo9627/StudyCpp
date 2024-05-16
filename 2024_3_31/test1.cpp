#include<iostream>
#include<cstdio>
using namespace std;


class A
{
public:
	int a;
public:
	A(int b=772):a(b)
	{
		cout << "A(int b)" << endl;
	}
	A(const A& a)
	{
		this->a = a.a;
		cout << "A(const A& a)" << endl;
	}
	virtual void test(int x=10)
	{
		cout << "testA" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	A& operator=(const A& b)
	{
		this->a = b.a;
		cout << "operator=(const A& b)" << endl;
		return *this;
	}
	void* operator new(size_t n)
	{
		cout << "operator new"<<endl;
		return malloc(n);
	}
	void* operator new[](size_t n)
	{
		cout << "operator new[]" << endl;
		return malloc(n);
	}
	void operator delete(void* p)
	{
		cout << "operator delete" << endl;
		free(p);
	}
	void operator delete[](void* p)
	{
		cout << "operator delete[]" << endl;
		free(p);
	}
};

class B:public A
{
public:
	int a;
public:
	B(int b = 772) :a(b)
	{
		cout << "B(int B)" << endl;
	}
	B(const A& a)
	{
		this->a = a.a;
		cout << "B(const B& a)" << endl;
	}
	void test(int x=10)
	{
		cout << "testB" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};

//class C :virtual public A
//{
//private:
//	int a;
//public:
//	C(int _a = 100, int b = 20) :A(_a), a(b) {}
//	int get() { return a; }
//};
//
//class D :public B,public C
//{
//private:
//	int a=10;
//public:
//	D(int _a = 10, int b = 2){}
//	//int get() { return a; }
//};

int main()
{
	char c1[15] = "228345";
	char c2[10]="222";
	int a = 0x00000001;
	int b = 0x00100002;

	int ret = memcmp(&a, &b, sizeof(int));
	return 0;
}

















class Complex
{
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend istream& operator>>(istream& in, Complex& c);

	int _a;
	int _b;
public:
	Complex(int a=0,int b=0):_a(a),_b(b){}
	Complex operator+(const Complex& c)const
	{
		int a = _a + c._a;
		int b = _b + c._b;
		return Complex(a, b);
	}
	Complex operator-(const Complex& c)const
	{
		int a = _a - c._a;
		int b = _b - c._b;
		return Complex(a, b);
	}

	Complex operator~()const
	{
		return Complex(_a, -_b);
	}
};
ostream& operator<<(ostream& out, const Complex& c)
{
	out << c._a << "+" << c._b << "i";
	return out;
}
istream& operator>>(istream& in, Complex& c)
{
	in >> c._a >> c._b;
	return in;
}
Complex operator*(const Complex& c1,const Complex& c2)
{
	int a = c1._a * c2._a - c1._b * c2._b;
	int b = c1._b * c2._a + c1._a * c2._b;
	return Complex(a, b);
}
//int main()
//{
//	Complex c1(2, 2);
//	Complex c2(2, 3);
//	cout << c1*2;
//	return 0;
//}
//int main()
//{
//
//	A* p = new A[10];
//	delete[] p;
//	A* p1 = new A;
//	delete p1;
//	return 0;
//}
//int main()
//{
//	size_t a = -1;
//	int b = a+1;
//	cout << b;
//	return 0;
//}
//class Time
//{
//public:
//	~Time()
//	{
//		//cout << "eeee" << endl;
//	}
//	Time()
//	{
//		a = 0;
//		//cout << "qqq" << endl;
//	}
//private:
//	int a;
//};
//class Data
//{
//	int _year;
//	int _month;
//	int _day;
//	Time t1;
//public:
//	Data(int year=0, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Data(const Data& d)
//	{
//		_year = 0;
//		_day = 0;
//		_month = 1;
//	}
//	void operator=(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void operator++(int x)
//	{
//		_day = 99;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	~Data()
//	{
//		//cout << "haha" << endl;
//	}
//};
//int main()
//{
//	Data d1=12;
//	d1.Print();
//	Data d2(d1);
//	d2.Print();
//	Data d3 ;
//	d3++;
//	d3.Print();
//	return 0;
//}
//class Stu
//{
//private:
//	int a;
//	int b;
//public:
//	void print() { 
//		cout << "hahah";
//		return; 
//	}
//};
//int main()
//{
//	Stu* s1 = nullptr;
//}
//struct A
//{
//	int a;
//	char b;
//	int c;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//}
//namespace A
//{
//	int a;
//	int b;
//	struct Stu
//	{
//		int age;
//		int score;
//	};
//	class Person
//	{
//		int age=10;
//		int id=20;
//	public:
//		Person(int age=100, int id=2)
//		{
//			this->age = age;
//			this->id = id;
//		}
//		void Show()
//		{
//			cout << age << " " << id;
//		}
//		~Person()
//		{
//
//		}
//	};
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	int* arry = arr;
//	for (int& i : arr)
//	{
//		i *= 2;
//	}
//	for (int i : arr)
//	{
//		cout << i<<" ";
//	}
//
//}

//using A::Person;
//int main()
//{
//	int c = 10;
//	Person p1;
//	//p1.Init(1, 2);
//	p1.Show();
//	return 0;
//}



//using std::cout;
//namespace A
//{
//	int a;
//	int b=100;
//}
////int cout = 10;
////using namespace A;
//int a = 10;
//int main()
//{
//	//A::b = 1000;
//	int cout = 10;
//	int b = 10;
//	//float a = 2.99;
//	std::cout << a;
//	//printf("%d", cout);
//	//std::cout << "hello world" << std::endl;
//}