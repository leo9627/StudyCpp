#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Book
{
	string _name="";
	string _ID="";
	bool _borrow=false;
	string _Reader_name = "";
	bool operator<(const Book& b)const
	{
		return stoi(_ID) < stoi(b._ID);
	}
};

class Person
{
protected:
	string _name;
	string _password;
	vector<Book>::iterator Find_Book(const string& name, vector<Book>& book_arr)
	{
		auto it = book_arr.begin();
		while (it != book_arr.end())
		{
			if (it->_name == name)
				break;
			it++;
		}
		if (it == book_arr.end())
		{
			it = book_arr.begin();
			while (it != book_arr.end())
			{
				if (it->_ID == name)
					break;
				it++;
			}
		}
		return it;
	}
public:
	Person(const string& name,const string& password)
		:_name(name)
		,_password(password)
	{}
};
class Reader:public Person
{
	friend class Manager;
	template<class Container>
	friend auto Login(const string& name, const string& password, Container& arr);
	friend void BorrowBook(const string& name, const string& password);
	friend void Read_Data();
	friend void Write_Data();
private:
	int _borrow_number;
	vector<Book> _borrow_book;
public:
	Reader(const string& name, const string& password,int x=0);
	void borrow_book(const string& book_name,vector<Book>& book_arr);
	void return_book(vector<Book>& book_arr);
};