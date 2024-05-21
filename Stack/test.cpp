#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
using namespace std;
#include"stack.h"
#include"queue.h"
#include"priority_queue.h"
void test_stack1()
{
	stack<int,list<int>> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	while (!s1.empty())
	{
		cout << s1.top()<<" ";
		s1.pop();
	}
}
void test_queue1()
{
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);

	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
}
void test1()
{
	leo::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
}
void test2()
{
	leo::queue<int,deque<int>> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
}
void test3()
{
	vector<int> v1;
	deque<int> d1;
	srand(time(nullptr));
	for (int i = 0; i < 100000000; i++)
	{
		int x = rand();
		v1.push_back(x);
		d1.push_back(x);
	}
	size_t begin1 = clock();
	sort(d1.begin(), d1.end());
	size_t end1 = clock();

	size_t begin2 = clock();
	sort(v1.begin(), v1.end());
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;

}
void test4()
{
	leo::priority_queue<int,vector<int>,leo::greater<int>> pq;
	for (int i = 0; i < 5; i++)
	{
		pq.push(rand()%100);
	}
	while (!pq.empty())
	{
		cout << pq.top()<<" ";
		pq.pop();
	}
	cout << endl;
}
void test5()
{
	priority_queue<int,vector<int>> pq;
	for (int i = 0; i < 20; i++)
	{
		pq.push(rand() % 100);
	}
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
void test6()
{
	vector<int> v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(rand() % 100);
	}
	sort(v.begin(), v.end()-2,leo::less<int>());
	for (auto e : v)
	{
		cout << e << " ";
	}
}
int main()
{
	//test_stack1();
	//test_queue1();
	//test1();
	//test2();
	//test3();
	test4();
	//test5();
	//test6();
	return 0;
}

//bool my_strstr(const char* c1, const char* c2)
//{
//	while (*c1)
//	{
//		if (*c1 == *c2)
//		{
//			const char* t1 = c1;
//			const char* t2 = c2;
//			while (*t1 && *t2 && *t1 == *t2)
//			{
//				t1++;
//				t2++;
//			}
//			if (!*t2)
//				return true;
//		}
//		c1++;
//	}
//	return false;
//}

//char* my_strcpy(char* dest, char* score)
//{
//	char* ret = dest;
//	while (*dest++ = *score++)
//		;
//	return ret;
//}
//int main2()
//{
//	//cout << (char)tolower('A');
//	char c1[10] = "123456";
//	char c2[] = "ppp";
//	char arr[] = "192.168.1.1";
//	char* str=nullptr;
//	for(str=strtok(arr,".");str;str=strtok(nullptr,"."))
//		cout<<str<<endl;
//	return 0;
//}
//int main3()
//{
//	/*FILE* fo;
//	fo = fopen("hahha", "r");
//	if (fo == NULL)
//		cout << strerror(errno);*/
//
//	for (int i = 0; i < 16; i++)
//	{
//		cout << strerror(i) << endl;
//	}
//	return 0;
//}
//int main()
//{
//	list<int> l1;
//	list<int> l2;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l2.push_back(10);
//	l2.push_back(20);
//	l2.push_back(30);
//	l1.splice(l1.begin(), l2);
//
//	for (auto e : l1)
//		cout << e << " ";
//	return 0;
//}