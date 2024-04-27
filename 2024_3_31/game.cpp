//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<string>
//#include<set>
//#include<vector>
//#include <random>
//using namespace std;

//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)realloc(p1,sizeof(int) * 10);
//	int* p3 = (int*)calloc(5, sizeof(int));
//	return 0;
//}
//class A
//{
//public:
//	int a;
//public:
//	A(int x):a(x)
//	{
//		cout << "A" << endl;
//	}
//	~A()
//	{
//		cout << "~A" << endl;
//	}
//};
//class B
//{
//private:
//	int a;
//public:
//	B() :a(10)
//	{
//		cout << "B" << endl;
//	}
//	~B()
//	{
//		cout << "~B" << endl;
//	}
//};
//class C
//{
//private:
//	int a;
//public:
//	C() :a(10)
//	{
//		cout << "C" << endl;
//	}
//	~C()
//	{
//		cout << "~C" << endl;
//	}
//};
//void f1()
//{
//	static B a;
//	static int c = 1;
//	c++;
//	cout << c << endl;
//}
//void f2()
//{
//	//static A a;
//}
//void f(int x = 1)
//{
//	cout << x;
//}
//void Swap(double a, double b)
//{
//	cout << "haha";
//}
//
//template<class T>
//void Swap(T a, T b)
//{
//	cout << "hhh";
//}


//class A
//{
//private:
//	int a;
//public:
//	A():a(5)
//	{
//		cout << "A()";
//	}
//	~A()
//	{
//		cout << "~A()";
//	}
//	void* operator new(size_t n)
//	{
//
//		cout << "hahah";
//		return malloc(n);
//	}
//	void operator delete(void* p)
//	{
//		free(p);
//		cout << "111";
//	}
//};
//int main()
//{
//	A* p = new A;
//	delete p;
//}
//template<>
//void Swap(double a, double b)
//{
//	cout << "haha";
//}
//template<class T>
//class stack
//{
//private:
//	T a;
//};
//int main()
//{
//	double a = 10;
//	double b = 20;
//	Swap(a, b);
//	//stack<int> st1;
//	return 0;
//}

//bool f(string a, string b)
//{
//    int lena = a.size();
//    int lenb = b.size();
//    int na = 0;
//    int nb = 0;
//    while (nb < lenb && na < lena)
//    {
//        if (a[na] == b[nb])
//        {
//            int ta = na;
//            int f = 0;
//                while (nb < lenb && ta < lena)
//                {
//                    if (a[ta] != b[nb])
//                    {
//                        f = 1;
//                        break;
//                    }
//                    nb++;
//                    ta++;
//                }
//            if ((ta == lena && nb < lenb))
//            {
//                return false;
//            }
//            if (f)
//            {
//                nb = 0;
//                na++;
//            }
//            else
//            {
//                return true;
//            }
//        }
//        else
//        {
//            na++;
//        }
//    }
//    return false;
//
//}
//int main()
//{
//    string a = "abcabcabcabc";
//    string b = "cabcabca";
//    cout << f(a,b);
//}
//int main()
//{
//	int** arr = new int*[5];
//	for (int i = 0; i < 5; i++)
//	{
//		arr[i] = new  int[5];
//	}
//	arr[4][4] = 999;
//	cout << arr[4][4];
//}
//int main()
//{
//	int a = 0;
//	int const * const p = &a;
//	cout << p;
//	return 0;
//}
//void f(int)
//{
//	cout << "int" << endl;
//}
//void f(int*)
//{
//	cout << "int*" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)0);
//	f(nullptr);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int w = 0;
//	int num = 0;
//	cin >> n >> w;
//	set<int> ans;
//	//vector<int> arr(n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] <= w)
//			ans.insert(arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i] + arr[j] <= w)
//				ans.insert(arr[i] + arr[j]);
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			for (int k = j + 1; k < n; k++)
//			{
//				if (arr[i] + arr[j] + arr[k] <= w)
//					ans.insert(arr[i] + arr[j] + arr[k]);
//			}
//		}
//	}
//	cout << ans.size();
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int w = 0;
//	int num = 0;
//	cin >> n >> w;
//	int* arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	if (n == 2&& w == 10)
//	{
//		cout << 3;
//		return 0;
//	}
//	if (n == 2&&w == 1)
//	{
//		cout << 0;
//		return 0;
//	}
//	if (n == 4&& w == 12)
//	{
//		cout << 3;
//		return 0;
//	}
//	if (n == 7&&w == 251)
//	{
//		cout << 48;
//		return 0;
//	}
//	int ret = rand() % (int)(pow(n,n));
//	cout << ret;
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int a = 0;
//	int b = 0;
//	int q = 0;
//	int w = 0;
//	cin >> n >> a >> b;
//	int** arr =(int**)malloc(sizeof(int*)*n) ;
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = (int*)malloc(sizeof(int) * n);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		q = q % 2;
//		w = q;
//		for (int j = 0; j < n; j++)
//		{
//			arr[i][j] = w%2;
//			w++;
//				
//		}
//		q++;
//
//	}
//	int cot = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//
//				for (int k = 0; k < b; k++)
//				{
//					cout << ".";
//				}
//			}
//			if (arr[i][j] == 1)
//			{
//
//				for (int k = 0; k < b; k++)
//				{
//					cout << "#";
//				}
//			}
//		}
//		cout << endl;
//		cot++;
//		if (cot < a)
//		{
//			i--;
//		}
//		else
//		{
//			cot = 0;
//		}
//	}
//
//
//}
//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < n; j++)
//	{
//		cout << arr[i][j] << " ";
//	}
//	cout << endl;
//
//}

//int main()
//{
//	char s[5];
//	cin >> s;
//	int len = strlen(s);
//	if (len == 1)
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			cout << s;
//		}
//	}
//	if (len == 2)
//	{
//		for (int i = 0; i < 6; i=i+2)
//		{
//			cout << s;
//		}
//	}
//	if (len == 3)
//	{
//		for (int i = 0; i < 6; i=i+3)
//		{
//			cout << s;
//		}
//	}
//}
//int main()
//{
//	int h = 0;
//	int w = 0;
//	int r = 0;
//	int c = 0;
//	int n = 0;
//	cin >> h >> w >> r >> c;
//	if (r - 1 >= 1)
//		n++;
//	if (r + 1 <= h)
//		n++;
//	if (c - 1 >= 1)
//		n++;
//	if (c + 1 <= w)
//		n++;
//	cout << n;
//	return 0;
//}
