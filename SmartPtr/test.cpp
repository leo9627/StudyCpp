#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<Windows.h>
#include<functional>
#include"SmartPtr.h"
using namespace std;

//void f2()
//{
//	throw 1;
//}
//void f1()
//{
//	int* p = new int;
//	SmartPtr<int> s1(new int);
//	try
//	{
//		f2();
//	}
//	catch (...)
//	{
//		delete p;
//		throw;
//	}
//
//	delete p;
//}
//
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int a)
//	{
//		;
//	}
//
//	return 0;
//}



//int main()
//{
//
//	int n = 10;
//	thread t1=thread([&]()mutable {
//		Sleep(1000);
//		cout << " leo\n";
//		n += 10;
//	});
//	int s = 5;
//	thread t2 = thread([&]()mutable {
//		cout << "hello";
//		s += 100;
//	});
//
//	t1.join();
//	t2.join();
//	cout << n + s;
//
//	return 0;
//}



template<class T>
struct DelArray
{

	void operator()(T* p)
	{
		cout << "operator()\n";
		delete[] p;
	}
};


void DelFile(FILE* fl)
{
	cout << "DelFile\n";
	fclose(fl);
}

struct FileDel
{
	void operator()(FILE* fe)
	{
		cout << "DelFile\n";
		fclose(fe);
	}
};

struct ListNode
{
	int _a = 0;
	leo::weak_ptr<ListNode> _prev;
	leo::weak_ptr<ListNode> _next;
};
int x1()
{
	/*SmartPtr<int> sp(new int);
	(*sp) = 2;
	cout << *sp<<endl;
	SmartPtr<int> sp1(sp);*/
	//leo::auto_ptr<int> ap1(new int);
	//(*ap1) = 2;
	//cout << *ap1<<endl;
	//leo::auto_ptr<int> ap2(ap1);
	//leo::auto_ptr<int> ap3(new int);
	//ap3 = ap2;

	////*ap1 = 10;  //非法操作

	//leo::unique_ptr<int> up1(new int);
	//(*up1) = 2;
	//cout << *up1 << endl;
	////leo::unique_ptr<int> up2(ap1);   //非法操作
	//leo::unique_ptr<int> up3(new int);
	////up3 = up2;   //非法操作

	//leo::shared_ptr<int> sp1(new int);
	//leo::shared_ptr<int> sp2(new int);
	//leo::shared_ptr<int> sp3(sp1);
	//leo::shared_ptr<int> sp4;
	//sp4 = sp2;


	////shared_ptr的线程安全问题，要加锁
	//int n = 10000000;
	//thread t1 = thread([&] {
	//	for (int i = 0; i < n; ++i)
	//	{
	//		leo::shared_ptr<int> sp(sp1);
	//	}
	//	});
	//thread t2 = thread([&] {
	//	for (int i = 0; i < n; ++i)
	//	{
	//		leo::shared_ptr<int> sp(sp1);
	//	}
	//	});
	//t1.join();
	//t2.join();
	//std::shared_ptr<int> sp99(new int[10],A());


	//循环引用问题
	/*leo::shared_ptr<ListNode> spl1(new ListNode);
	leo::shared_ptr<ListNode> spl2(new ListNode);
	spl1->_next = spl2;
	spl2->_next = spl1;*/

	//定制删除器

	leo::shared_ptr<int> sp1(new int[10],DelArray<int>());
	leo::shared_ptr<int> sp2((int*)malloc(sizeof(int)), [](int* p) { free(p); });
	leo::shared_ptr<FILE> sp3(fopen("1.txt","w"),DelFile);

	unique_ptr<int[]> up(new int[10]);
	unique_ptr<FILE, FileDel> up2(fopen("1.txt", "w"));
	return 0;
}

int x2()
{
	shared_ptr<ListNode> sp1;
	weak_ptr<ListNode> wp1;
	{
		shared_ptr<ListNode> n1(new ListNode);
		wp1 = n1;
		cout << wp1.expired() << endl;
		sp1 = wp1.lock();
	}
	cout << wp1.expired() << endl;
	return 0;
}






void f1()
{
	mutex _lock;
	leo::lock_guard<mutex> lg(_lock);
}

int main()
{
	f1();
	return 0;
}