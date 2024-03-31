#include<iostream>
#include<cstdio>
using namespace std;

namespace A
{
	int a;
	int b;
	struct Stu
	{
		int age;
		int score;
	};
	class Person
	{
		int age=10;
		int id=20;
	public:
		Person(int age=100, int id=2)
		{
			this->age = age;
			this->id = id;
		}
		void Show()
		{
			cout << age << " " << id;
		}
		~Person()
		{

		}
	};
}

int main()
{
	int arr[] = { 1,2,3,4 };
	int* arry = arr;
	for (int& i : arr)
	{
		i *= 2;
	}
	for (int i : arr)
	{
		cout << i<<" ";
	}

}

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