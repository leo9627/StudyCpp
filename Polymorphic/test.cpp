#include<iostream>
using namespace std;


//class A
//{
//public:
//	virtual void fa()
//	{
//
//	}
//	int a;
//};
//class B:public A
//{
//public:
//	//virtual void fa()
//	//{
//
//	//}
//	int b;
//};
//
//class C :virtual public A
//{
//public:
//	int c;
//	virtual void fc()
//	{
//
//	}
//};
//
//class D :public B, public C
//{
//public:
//	int d;
//	void fc()
//	{
//
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	b.a = 1;
//	b.b = 2;
//	std::cout << sizeof b << std::endl;
//	//D d;
//	//std::cout << sizeof d << std::endl;
//	////d.a = 1;
//	//d.b = 2;
//	//d.c = 3;
//	//d.d = 4;
//	//B* p = new D;
//	//p->fa();
//	return 0;
//}

//class A
//{
//public:
//	int a;
//	virtual void f()//final
//	{
//		cout << "1";
//	}
//};
//class B :public A
//{
//	virtual void f()override
//	{
//
//	}
//};
//
//int main()
//{
//	B b;
//	return 0;
//}

//class A
//{
//public:
//	virtual void fa()
//	{
//		cout << "A::fa()" << endl;
//	}
//	virtual void ff()
//	{
//		cout << "A::ff()" << endl;
//	}
//};
//
//class B 
//{
//public:
//	virtual void fa()
//	{
//		cout << "B::fa()" << endl;
//	}
//	virtual void fb()
//	{
//		cout << "B::fb()" << endl;
//	}
//};
//
//class C :public A,public B
//{
//	virtual void fa()
//	{
//		cout << "C::fa()" << endl;
//	}
//	virtual void fc()
//	{
//		cout << "C::fc()" << endl;
//	}
//};
//typedef void (*VFT)();
//
//void PrintVFT(VFT* table)
//{
//	for (int i = 0; table[i] != 0; i++)
//	{
//		printf("%d:%p->", i, table[i]);
//		table[i]();
//	}
//	cout << endl;
//}
//int main()
//{
//	//B b;
//	//PrintVFT((VFT*)*(int*)&b);
//	C c;
//	PrintVFT((VFT*)(*(int*)((char*)&c+sizeof(A))));
//	PrintVFT((VFT*)(*(int*)((char*)&c)));
//	return 0;
//}

//class A
//{
//public:
//	A(int x=1)
//	{
//		cout << "A()" << endl;
//	}
//	virtual void PrintA()
//	{
//
//	}
//	int b;
//};
//
//class B:virtual public A
//{
//public:
//	B(int x = 1)
//	{
//		cout << "A()" << endl;
//	}
//	virtual void PrintA()
//	{
//
//	}
//	virtual void f()
//	{
//
//	}
//	int a;
//};
//
//int main()
//{
//	B b;
//	b.a = 1;
//	b.b = 2;
//	cout << sizeof B << endl;
//	return 0;
//}


//class A final
//{
//public:
//	int a;
//};
//
//class B:public A
//{
//
//};