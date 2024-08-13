#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;


//int Div(int x, int y)
//{
//	
//	try
//	{
//		if (y == 0)
//		{
//			throw string("除零错误");
//		}
//		else
//			return 4;
//	}
//	catch (string& s)
//	{
//		cout << s << "1";
//	}
//	return -1;
//}
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	try
//	{
//		cout << Div(x, y);
//		cout << "hahha";
//	}
//	catch (string& s)
//	{
//		cout << s;
//	}
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1,2,3,4,5,6 };
//	try
//	{
//		int x=v.at(6);
//	}
//	catch (out_of_range& ex)
//	{
//		cout << ex.what();
//	}
//	return 0;
//}


//class Exception
//{
//protected:
//	string _errmsg;
//	int _errid;
//public:
//	Exception(const char* errmsg,int errid)
//		:_errmsg(errmsg)
//		,_errid(errid)
//	{}
//	string what()const
//	{
//		return _errmsg;
//	}
//};
//class SqlErr:public Exception
//{
//public:
//	SqlErr(const char* errmsg, int errid)
//		:Exception(errmsg,errid)
//	{}
//	string what()const
//	{
//		return _errmsg;
//	}
//};
//
//class SeverErr :public Exception
//{
//public:
//	SeverErr(const char* errmsg, int errid)
//		:Exception(errmsg, errid)
//	{}
//	string what()const
//	{
//		return _errmsg;
//	}
//};
//
//void SeverStart()throw(SeverErr,SqlErr)
//{
//	srand(time(nullptr));
//	Sleep(100);
//	if (rand()%14==0)
//		throw SeverErr("服务器错误", 1);
//	if(rand()%15==0)
//		throw SqlErr("数据库错误", 1);
//	cout << "成功"<<endl;
//}
//
//int main()
//{
//	for (size_t i = 0; i < 100; i++)
//	{
//		try
//		{
//			SeverStart();
//		}
//		catch (SeverErr& se)
//		{
//			cout << se.what() << endl;
//		}
//		catch (SqlErr& se)
//		{
//			cout << se.what()<<endl;
//		}
//		/*catch (Exception& ex)
//		{
//			cout << ex.what() << endl;
//		}*/
//	}
//	return 0;
//}


void f3()noexcept
{
	cout << 23 << endl;
}

//可能内存泄露
void f2()
{
	throw string("error");
}

void f1()
{
	int* p = new int[10];
	try
	{
		f2();
	}
	catch (...)        //这里得再抛一次异常，不然可能内存泄漏
	{
		delete[] p;
		throw;
	}
	delete[] p;
}

int main()
{
	f3();
	try
	{
		f1();
	}
	catch (const string& s)
	{
		cout << s << endl;
	}
	Sleep(1000000);
	return 0;
}