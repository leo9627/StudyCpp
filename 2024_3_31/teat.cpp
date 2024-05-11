#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Node
{
	int _data;
	Node* next;
};
class Queue
{
private:
	Node* _head;
	Node* _ptail;
	int num = 1;
public:
	Queue()
		:_head(nullptr)
		, _ptail(nullptr)
	{
		_ptail = _head = new Node;
		_head->next = nullptr;
	}
	void Enqueue(int x)
	{
		Node* n = new Node;
		n->_data = x;
		n->next = nullptr;
		_ptail->next = n;
		_ptail = n;

	}
	void Dequeue()
	{
		if (_head->next == nullptr)
			return;
		Node* temp = _head->next;
		_head->next = _head->next->next;
		if (_head->next == nullptr)
			_ptail = _head;
		delete temp;
	}
	int Peek()
	{
		if (_head->next == nullptr)
			return INT_MAX;
		return _head->next->_data;
	}
	bool IsEmpty()
	{
		return !(_head->next);
	}
	size_t size()
	{
		size_t n = 0;
		Node* begin = _head->next;
		while (begin)
		{
			n++;
			begin = begin->next;
		}
		return n;
	}
	bool IsFull()
	{
		if (size() == num)
			return true;
		return false;
	}
	~Queue()
	{
		while (_head != _ptail)
			Dequeue();
		delete _head;
		_head = _ptail = nullptr;
	}

};
struct Node1
{
	Queue& _data;
	Node1* next;
	Node1(Queue& q):_data(q),next(nullptr){}
};
class task_manager
{
private:
	Queue Queue1;
	Queue Queue2;
	Queue Queue3;
	Queue Queue4;
	Node1* head;
	Node1* ptail;
	Node1* end;

public:
	task_manager()
	{
		Node1* h1 = new Node1(Queue1);
		Node1* h2 = new Node1(Queue2);
		Node1* h3 = new Node1(Queue3);
		Node1* h4 = new Node1(Queue4);
		h1->next = h2;
		h2->next = h3;
		h3->next = h4;
		h4->next = nullptr;
		head = h1;
		ptail = head;
		end = h4;
	}
	void Insert_element(int x)
	{
		if (ptail == nullptr)
			return;
		ptail->_data.Enqueue(x);
		if (ptail->_data.IsFull())
			ptail = ptail->next;
	}
	void Pop_element()
	{

		head->_data.Dequeue();
		if (head->_data.IsEmpty())
		{
			end->next = head;
			head = head->next;
			end = end->next;
			end->next = nullptr;
		}
		if (ptail == nullptr)
		{
			ptail = end;
		}
	}
	size_t size()
	{
		size_t num=	Queue1.size()+ Queue2.size() + Queue3.size() + Queue4.size();
		return num;
	}
	int Peek()
	{
		if (size())
			return head->_data.Peek();
		else
			exit(-1);
	}
	bool IsFull()
	{
		if (ptail==nullptr)
			return true;
		return false;
	}
	~task_manager()
	{
		Node1* temp=nullptr;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};
int main()
{
	task_manager t1;
	t1.Insert_element(1);
	t1.Insert_element(2);
	t1.Insert_element(3);
	t1.Insert_element(4);
	t1.Pop_element();
	t1.Pop_element();
	t1.Pop_element();
	t1.Pop_element();
	t1.Insert_element(5);
	cout << t1.Peek();
	return 0;
}
struct student
{
	int _id;
	float _score;
};
int cmp(const void* s1, const void* s2)
{
	return ((student*)s2)->_score - ((student*)s1)->_score;
}
class score_recorder
{
private:
	student* member_table;
	int numbers;
public:
	score_recorder(int x)
	{
		numbers = x;
		member_table = new student[x];
	}
	void Set()
	{
		for (int i = 0; i < numbers; i++)
		{
			cin >> member_table[i]._id;
			cin >> member_table[i]._score;
		}
	}
	float Find(int id)
	{
		int i = 0;
		for (i = 0; i < numbers; i++)
		{
			if (member_table[i]._id == id)
				break;
		}
		if (i == numbers)
			exit(-1);
		else
			return member_table[i]._score;
	}
	void fix(int id, float score)
	{
		int i = 0;
		for (i = 0; i < numbers; i++)
		{
			if (member_table[i]._id == id)
				break;
		}
		if (i == numbers)
			return;
		member_table[i]._score = score;
		
	}
	void Sort()
	{
		qsort(member_table,numbers,sizeof(student),cmp);
	}
	void print()
	{
		int end = 10;
		if (numbers < 10)
			end = numbers;
		for (int i = 0; i < end; i++)
		{
			cout << member_table[i]._id << "   " << member_table[i]._score<<endl;
		}
	}
};


//int main()
//{
//	score_recorder s1(12);
//	s1.Set();
//	s1.Sort();
//	s1.print();
//	cout << endl;
//	cout<<s1.Find(10);
//	s1.Set();
//	s1.Sort();
//	s1.print();
//}
class Point
{
private:
	float _x;
	float _y;
public:
	Point(float x=0, float y=0)
		:_x(x)
		,_y(y)
	{}
	void print()
	{
		cout << "(" << _x << "," << _y << ")";
	}
};
class Line
{
	friend ostream& operator<<(ostream& out, const Line& l);
	friend Point setPoint(const Line& l1, const Line& l2);
	friend bool HavePoint(const Line& l1, const Line& l2);
private:
	float _a;
	float _b;
public:
	Line(float a,float b):_a(a),_b(b){}

};
ostream& operator<<(ostream& out, const Line& l)
{
	out << "y=" << l._a << "x+" << l._b;
	return out;
}

Point setPoint(const Line& l1,const Line& l2)
{
	if (l1._a == l2._a)
	{
		exit(-1);
	}
	float x = (l2._b - l1._b) / (l1._a - l2._a);
	float y = l2._a * x + l2._b;
	return Point(x, y);
}
bool HavePoint(const Line& l1, const Line& l2)
{
	if (l1._a == l2._a)
		return false;
	return true;
}
//int main()
//{
//	Line l1(2, 3);
//	Line l2(3, 2);
//	cout << l1 << endl << l2 << endl;
//	if (HavePoint(l1, l2))
//	{
//		setPoint(l1, l2).print();
//	}
//	return 0;
//}

//int main()
//{
//	Queue q1;
//	q1.Enqueue(1);
//	q1.Enqueue(2);
//	q1.Enqueue(3);
//	q1.Enqueue(4);
//	cout << q1.size() << endl;
//	cout << q1.IsEmpty() << endl;
//	cout << q1.Peek() << endl;
//	q1.Dequeue();
//	cout << q1.Peek() << endl;
//	q1.Dequeue();
//	q1.Dequeue();
//	cout << q1.Peek() << endl;
//	q1.Dequeue();
//	cout << q1.size() << endl;
//	cout << q1.IsEmpty() << endl;
//
//}
float interestRate=0.02;
class Account
{
	string accountNumber;
	string passWord;
	long long balance;
public:
	Account(string _accountNumber, string _passWord, long long _balance=0)
		:accountNumber(_accountNumber),passWord(_passWord), balance(_balance)
	{}
	void deposit(string _accountNumber, string _passWord, long long x)
	{
		if (_accountNumber != accountNumber || passWord != _passWord)
		{
			cout << "error";
			return;
		}
		balance += x;
	}
	void withdraw(string _accountNumber, string _passWord, long long x)
	{
		if (_accountNumber != accountNumber || passWord != _passWord||balance<x)
		{
			cout << "error";
			return;
		}
		balance -= x;
	}
	long long calculateInterest(string _accountNumber, string _passWord,int year)
	{
		if (_accountNumber != accountNumber || passWord != _passWord)
		{
			cout << "error";
			return 0;
		}
		long long init = balance;
		balance = pow(balance * (1 + interestRate), year);
		return balance - init;
	}
	friend void transfer(Account& a1, Account& a2, long long x);
};
void transfer(Account& a1, Account& a2,long long x)
{
	a1.withdraw(a1.accountNumber, a1.passWord, x);
	a2.deposit(a2.accountNumber, a2.passWord, x);
}
//int main()
//{
//	Account a1("1", "1");
//	Account a2("2", "2");
//	a1.deposit("1","1",100);
//	a2.deposit("2","2",100);
//	transfer(a1, a2, 10);
//	a1.calculateInterest("1", "1", 1);
//	return 0;
//}
class String
{
private:
	char* _str;
public:
	String(const char* str="")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s):_str(nullptr)
	{
		String temp(s._str);
		swap(_str, temp._str);
	}
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	String operator+(const String& s)
	{
		String temp;
		temp._str = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(temp._str, _str);
		strcpy(temp._str + strlen(_str), s._str);
		return temp;
	}
	char* c_str()
	{
		return _str;
	}
	const char* c_str()const
	{
		return _str;
	}
	size_t size()const
	{
		return strlen(_str);
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
	}
};
ostream& operator<<(ostream& out, const String& s)
{
	out << s.c_str();
	return out;
}
//int main()
//{
//	String s1="haha";
//	String s2="11111";
//	String s3 = s1 + s2;
//	cout << s3;
//	return 0;
//}
class Matrix
{
private:
	vector<vector<float>> _v;
	int _w;
	int _h;
public:
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend istream& operator>>(istream& in, Matrix& m);
	Matrix(int h=0,int w=0)
		:_w(w)
		,_h(h)
	{
		for (int i = 0; i < _h; i++)
		{
			vector<float> v;
			for (int j = 0; j < _w; j++)
			{
				v.push_back(0);
			}
			_v.push_back(v);
		}
	}
	Matrix operator+(const Matrix& m)const
	{
		
		if (m._h != _h || m._w != _w)
		{
			Matrix temp;
			cout << "error";
			return temp;
		}
		Matrix temp(_h,_w);
		for (int i = 0; i < _h; i++)
		{
			for (int j = 0; j < _w; j++)
			{
				temp._v[i][j] = _v[i][j] + m._v[i][j];
			}
		}
		return temp;
	}
	Matrix operator-(const Matrix& m)const
	{

		if (m._h != _h || m._w != _w)
		{
			Matrix temp;
			cout << "error";
			return temp;
		}
		Matrix temp(_h, _w);
		for (int i = 0; i < _h; i++)
		{
			for (int j = 0; j < _w; j++)
			{
				temp._v[i][j] = _v[i][j] - m._v[i][j];
			}
		}
		return temp;
	}
	Matrix operator*(const Matrix& m)const
	{

		if (m._h !=_w)
		{
			Matrix temp;
			cout << "error";
			return temp;
		}
		Matrix temp(_h, m._w);
		for (int i = 0; i < _h; i++)
		{
			for (int j = 0; j < m._w; j++)
			{
				float sum=0;
				for (int k = 0; k < _w; k++)
				{
					sum = sum + _v[i][k] * m._v[k][j];
				}
				temp._v[i][j] = sum;
			}
		}
		return temp;
	}
};

ostream& operator<<(ostream& out, const Matrix& m)
{
	for (int i = 0; i < m._h; i++)
	{
		for (int j = 0; j < m._w; j++)
		{
			out << m._v[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in,Matrix& m)
{
	for (int i = 0; i < m._h; i++)
	{
		for (int j = 0; j < m._w; j++)
		{
			in >> m._v[i][j];
		}
	}
	return in;
}
//int main()
//{
//	Matrix m1(2, 2);
//	Matrix m2(2, 3);
//	cin >> m1 >> m2;
//	Matrix m = m1 * m2;
//	cout << m;
//	return 0;
//}






class MyVector
{
private:
	float _x;
	float _y;
	float _z;
public:
	MyVector(float x = 0, float y = 0, float z = 0)
		:_x(x)
		, _y(y)
		, _z(z)
	{}
	MyVector operator+(const MyVector& m)const
	{
		MyVector temp;
		temp._x = _x + m._x;
		temp._y = _y + m._y;
		temp._z = _z + m._z;
		return temp;
	}
	MyVector operator-(const MyVector& m)const
	{
		MyVector temp;
		temp._x = _x - m._x;
		temp._y = _y - m._y;
		temp._z = _z - m._z;
		return temp;
	}
	float operator*(const MyVector& m)const
	{

		return _x * m._x + _y * m._y + _z * m._z;
	}
	friend ostream& operator<<(ostream& out, const MyVector& m);
};
ostream& operator<<(ostream& out, const MyVector& m)
{
	out << "( " << m._x << " , " << m._y << " , " << m._z << " )";
	return out;
}
//int main()
//{
//	MyVector v1 = { 2,2,2 };
//	MyVector v2 = { 3,3,3 };
//	MyVector v3 = v1 - v2;
//	float f = v1 * v2;
//	cout << v3<<endl<<f;
//	return 0;
//}




//class A
//{
//	
//public:
//	int a;
//	A(int a1=0):a(a1){}
//	A operator - ()
//	{
//		A temp = *this;
//		temp.a = -temp.a;
//		return temp;
//	}
//	A operator+(const A& a2)
//	{
//		A a1;
//		a1.a = a + a2.a;
//		return a1;
//	}
//
//};
//
//int main()
//{
//	A a1;
//	A a2;
//	a1.a = 3;
//	a2.a = 5;
//	A a3 = a1 + 4;
//	cout << a3.a;
//	return 0;
//}