
#include<iostream>

using namespace std;
#include"test.h"
//template<class T,size_t N=3>
//class Array
//{
//private:
//	T _arr[N];
//};
//
//
//template<class T>
//bool Less(const T x,const T y)
//{
//	return x < y;
//}
//
//template<>
//bool Less(const char* x, const char* y)
//{
//	return strcmp(x,y);
//}
//
//
//template<class T1,class T2>
//void f1(T1 x, T2 y)
//{
//
//}
//
//template<class T2>
//void f1(int x, T2 y)
//{
//
//}
//
//template<class T1,class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "template<class T1,class T2>" << endl;
//	}
//};
//
//template<class T2>
//class A<int, T2>
//{
//public:
//	A()
//	{
//		cout << "template<int,class T2>" << endl;
//	}
//};
//
//template<class T1>
//class A<T1, int>
//{
//public:
//	A()
//	{
//		cout << "template<T1,int>" << endl;
//	}
//};
//template<class T1,class T2>
//class A<T1*, T2*>
//{
//public:
//	A()
//	{
//		cout << "template<T1*,T2*>" << endl;
//	}
//};
//template<class T1, class T2>
//class A<T1&, T2&>
//{
//public:
//	A()
//	{
//		cout << "template<T1&,T2&>" << endl;
//	}
//};
//template<class T1, class T2>
//class A<const T1&, const T2&>
//{
//public:
//	A()
//	{
//		cout << "template<const T1&,const T2&>" << endl;
//	}
//};
//int test1()
//{
//	/*Array<int> a;
//	Array<int, 5> a1;
//	Array<int, 10> a2;*/
//	const int a = 10;
//	const int b = 20;
//	//Less<const int&>(a,b);
//
//	/*const char* c = "hello";
//	const char* c1 = "1hello";
//	cout << Less(c, c1);*/
//	//f1<double>(1, (double)1);
//	/*A<int, double> a1;
//	A<double, int*> a2;
//	A<int&, int&> a3;
//	A<const int&, const int&> a4;*/
//	return 0;
//}
//
//template<class T>
//void f(T x);
//int main()
//{
//	/*f(2);*/
//
//	B<double> b;
//	return 0;
//}

//template<class T>
//void f(T x)
//{
//	cout << x;
//}
//class Person
//{
//protected:
//	string _name = "hello";
//	int _id = 1;
////private:
//public:
//	void f()
//	{
//
//		cout << "Person" << endl;
//	}
//};
//
//class Student:public Person
//{
//private:
//	int _No = 0;
//public:
//	void f()//ÖØ¶¨Òå
//	{
//		//Person::f();
//		cout << "Student" << endl;
//	}
//	Person::f;
//};
//
//int test2()
//{
//	Person p;
//	Student s;
//	/*Person* ptr = (Person*)& s;
//	Person& pt = (Person&)s;*/
//	//pt.f();
//	//Student* str = (Student*)&p;
//	s.f();
//	return 0;
//}

class A
{
public:

	int _a1;
	int _a2;
};


class B :virtual public A
{
public:
	int _b;
};

class C :virtual public A
{
public:
	int _c;
};
class D :public C, public B
{
public:
	int _d;
};

int test3()
{
	cout << sizeof(D) << endl;
	D d;
	d.B::_a1 = 1;
	d.B::_a2 = 1;
	d._b = 2;
	d.C::_a1 = 3;
	d.C::_a2 = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}
class Student;
class Person
{
	friend void friend_Person(Person& p, Student& s);
public:
	Person(const char* str)
	{
		_name =str;
		cout << "Person()" << endl;
	}
	Person(const Person& p)
	{
		_name = p._name;
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& s)
	{
		_name = s._name;
		cout << "Person& operator=(const Person& s)" << endl;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
	static int i;
protected:
	string _name;
};
int Person::i = 1;
class Student:public Person
{
public:
	Student():Person("mike")
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		:Person(s)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator=(const Student& s)
	{
		Person::operator=(s);
		_id = s._id;
		cout << "Student& operator=(const Student& s)" << endl;
		return *this;
	}
	~Student()
	{
		cout << i;
		cout << "~Student()" << endl;
	}
protected:
	string _id;
};
void friend_Person(Person& p,Student& s)
{
	cout << s._name<<endl;
	//cout << s._id;
}
int main()
{
	Student s;
	Person p("rose");
	friend_Person(p, s);
	return 0;
}