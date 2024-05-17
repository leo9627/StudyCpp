#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class key_type,class value_type>
class map
{
private:
	struct instance { key_type key; value_type value; };
	instance** INSTANCES;
	int map_size;
public:
	map(int n) :INSTANCES(new instance* [n]), map_size(n)
	{
		memset(INSTANCES, 0, sizeof(instance*) * n);
	}
	instance* search(key_type k)
	{
		for (int i = 0; i < map_size;i++)
		{
			if (INSTANCES[i]!=nullptr&&INSTANCES[i]->key == k)
				return INSTANCES[i];
		}
		return nullptr;
	}
	void set(key_type real_key, value_type real_value)
	{
		instance* cur = search(real_key);
		if (cur != nullptr)
		{
			cur->value = real_value;
			return;
		}
		for (int i = 0; i < map_size; i++)
		{
			if (INSTANCES[i] == nullptr)
			{
				instance* newnode = new instance;
				newnode->key = real_key;
				newnode->value = real_value;
				INSTANCES[i] = newnode;
				return;
			}
		}
		cout << "error"<<endl;

	}
	value_type* get(key_type k)
	{
		instance* cur = search(k);
		if (cur)
		{
			return &cur->value;
		}
		return nullptr;
	}
	void map_delete(key_type k)
	{
		instance* cur = search(k);
		if (cur)
		{
			for (int i = 0; i < map_size; i++)
			{
				if (INSTANCES[i] == cur)
				{
					delete cur;
					INSTANCES[i] = nullptr;
					return;
				}
			}
		}
	}
	value_type* operator[](key_type k)
	{
		return get(k);
	}
	/*value_type& operator[](key_type k)
	{
		value_type* p = get(k);
		if(p==nullptr)
		{
			set(k, value_type());
			p = get(k);
		}
		return *p;
	}*/
	~map()
	{
		for (int i = 0;i < map_size; i++)
		{
			if (INSTANCES[i])
			{
				delete INSTANCES[i];
				INSTANCES[i] = nullptr;
			}
		}
	}
};
//int main()
//{
//	map<int, int> m(5);
//	m.set(1, 2);
//	m.set(2, 2);
//	m.set(3, 2);
//	m.set(4, 2);
//	m.set(5, 20);
//	m.map_delete(3);
//	m.set(100, 77);
//	cout << *m.get(100);
//	return 0;
//}
template<class T>
void multiples(T& sum,T x,int n)
{
	sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum = sum + i * x;
	}
}
//int main()
//{
//	double d;
//	multiples(d, 2.1, 2);
//	cout << d;
//	return 0;
//}
template<class Container>
void print(const Container&con )
{
	typename Container::const_iterator it=con.begin();
	//auto it = con.begin();
	while (it != con.end())
	{
		cout << *it << " ";
		it++;
	}
}
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	print(v);
//	return 0;
//}
template<class T>
class Node
{
	typedef Node<T> Self;
public:
	T _data;
	Self* _next;
	Node(const T& t=T()):_data(t),_next(nullptr){}
};
//int main()
//{
//	Node<int>* n1 = new Node<int>(1);
//	Node<int>* n2 = new Node<int>(2);
//	Node<int>* n3 = new Node<int>(3);
//	Node<int>* n4 = new Node<int>(4);
//	n1->_next = n2;
//	n2->_next = n3;
//	n3->_next = n4;
//	Node<int>* phead = n1;
//	while (phead != nullptr)
//	{
//		cout << phead->_data << " ";
//		phead = phead->_next;
//	}
//	return 0;
//}
class Emplyee
{
protected:
	int bais;
public:
	Emplyee(int a=0):bais(a){}
	virtual int earnings()const=0;
};

class teacher:public Emplyee
{
private:
	int regular;
	int nums;
	int num;
public:
	teacher(int a, int b, int c) :regular(a), num(b), nums(c){}
	int earnings()const
	{
		return regular + num * nums;
	}
};
class manager :public Emplyee
{
private:
	int em;
public:
	manager(int re,int e):Emplyee(re),em(e){}
	int earnings()const
	{
		return bais +em;
	}
};
class lab_er :public Emplyee
{
private:
	int day;
	int ear;
public:
	lab_er(int re,int da,int ea):Emplyee(re),day(da),ear(ea){}
	int earnings()const
	{
		return bais + day*ear;
	}
};
//int main()
//{
//	teacher t(10000,20, 20);
//	manager m(5000, 8000);
//	lab_er l(50000, 20, 20);
//	cout << t.earnings() << endl;
//	cout << m.earnings() << endl;
//	cout << l.earnings() << endl;
//	return 0;
//}
class Circle
{
protected:
	double radius;
public:
	Circle(double radius_=0):radius(radius_){}
	virtual double area()const
	{
		return 3.14 * radius * radius;
	}
	virtual double volume()const = 0;
};

class Sphere :public Circle
{
public:
	Sphere(double radius_=0):Circle(radius_){}
	virtual double area()const
	{
		return 4*3.14 * radius * radius;
	}
	virtual double volume()const
	{
		return (4 * 3.14 * radius * radius * radius) / 3;
	}
};
class Column :public Circle
{
protected:
	double h;
public:
	Column(double radius_=0,double _h=0):Circle(radius_),h(_h){}
	virtual double area()const
	{
		return 2 * Circle::area() + 2 * 3.14 * radius * h;
	}
	virtual double volume()const
	{
		return Circle::area() * h;
	}
};
//int main()
//{
//	Sphere s(2);
//	Column c(2, 3);
//	cout << s.area() << endl;
//	cout << s.volume() << endl;
//	cout << c.area() << endl;
//	cout << c.volume() << endl;
//	return 0;
//}




struct date
{
	int year;
	int month;
	int day;
};
class RESIDENT
{
	friend ostream& operator<<(ostream& out, const RESIDENT& p);
	friend istream& operator>>(istream& in, RESIDENT& p);
protected:
	long ID_NUMBER;
	string NAME;
	bool SEXUAL;
	date BIRTH;
public:
	RESIDENT(){}
	RESIDENT(long id,const string& na,bool sex,date bir)
		:ID_NUMBER(id),NAME(na),SEXUAL(sex),BIRTH(bir){}
};
istream& operator>>(istream& in, RESIDENT& p)
{
	cout << "id:" << endl;
	in >> p.ID_NUMBER;
	cout << "name:"  << endl;
	in >> p.NAME;
	cout << "sex:"  << endl;
	in >> p.SEXUAL;
	cout << "birth:" << endl;
	in >> p.BIRTH.year >> p.BIRTH.month >> p.BIRTH.day;
	return in;
}
ostream& operator<<(ostream& out, const RESIDENT& p)
{
	out << "id:" << p.ID_NUMBER << endl;
	out << "name:" << p.NAME << endl;
	out << "sex:" << p.SEXUAL << endl;
	out << "birth:" << p.BIRTH.year << " " << p.BIRTH.month << " " << p.BIRTH.day << endl;
	return out;
}
class ADULT :public RESIDENT
{
	friend ostream& operator<<(ostream& out, const ADULT& p);
	friend istream& operator>>(istream& in, ADULT& p);
protected:
	string EDUCATION;
	string PROFESSION;
public:
	ADULT() {}
	ADULT(long id, const string& na, bool sex, date bir, const string& edu, const string& pro)
		:RESIDENT(id,na,sex,bir), EDUCATION(edu), PROFESSION(pro){}
	void f()
	{
		int a = RESIDENT::ID_NUMBER;
	}
};
istream& operator>>(istream& in, ADULT& p)
{
	cout << "id:" << endl;
	in >> p.ID_NUMBER;
	cout << "name:"  << endl;
	in >> p.NAME;
	cout << "sex:"  << endl;
	in >> p.SEXUAL;
	cout << "birth:" << endl;
	in >> p.BIRTH.year >> p.BIRTH.month >> p.BIRTH.day;
	cout << "eduaction:"  << endl;
	in >> p.EDUCATION;
	cout << "profession:"  << endl;
	in>>p.PROFESSION;
	return in;
}
ostream& operator<<(ostream& out, const ADULT& p)
{
	out << "id:" << p.ID_NUMBER << endl;
	out << "name:" << p.NAME << endl;
	out << "sex:" << p.SEXUAL << endl;
	out << "birth:" << p.BIRTH.year << " " << p.BIRTH.month << " " << p.BIRTH.day << endl;
	out << "eduaction:" << p.EDUCATION << endl;
	out << "profession:" << p.PROFESSION << endl;
	return out;
}
class PARTY_MEM :public ADULT
{
	friend ostream& operator<<(ostream& out, const PARTY_MEM& p);
	friend istream& operator>>(istream& out, PARTY_MEM& p);
private:
	string CATEGORY;
public:
	PARTY_MEM() {}
	PARTY_MEM(long id, const string& na, bool sex, date bir, 
		const string& edu, const string& pro, const string& cat )
		:ADULT(id, na, sex, bir,edu,pro), CATEGORY(cat){}
};
istream& operator>>(istream& in, PARTY_MEM& p)
{
	cout << "id:"  << endl;
	in>>p.ID_NUMBER;
	cout << "name:"  << endl;
	in >> p.NAME;
	cout << "sex:" << endl;
	in>>p.SEXUAL;
	cout << "birth:" << endl;
	in >> p.BIRTH.year >> p.BIRTH.month >> p.BIRTH.day;
	cout << "eduaction:" << endl;
	in >> p.EDUCATION;
	cout << "profession:"  << endl;
	in>>p.PROFESSION;
	cout << "categogry:" << endl;
	in>>p.CATEGORY;
	return in;
}
ostream& operator<<(ostream& out, const PARTY_MEM& p)
{
	out << "id:" << p.ID_NUMBER<<endl;
	out << "name:" << p.NAME << endl;
	out << "sex:" << p.SEXUAL << endl;
	out << "birth:" << p.BIRTH.year << " " << p.BIRTH.month << " " << p.BIRTH.day << endl;
	out << "eduaction:" << p.EDUCATION << endl;
	out << "profession:" << p.PROFESSION << endl;
	out << "categogry:" << p.CATEGORY << endl;
	return out;
}
int main()
{
	PARTY_MEM p1;
	cin >> p1;
	cout << p1;
	return 0;
}
// (1, "zhansan", true, { 2011,5,8 }, "college", "teacher", "normal");