#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	size_t a = -1;
	int b = a+1;
	cout << b;
	return 0;
}
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