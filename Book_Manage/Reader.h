#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;
struct Book
{
	string _name="";
	string _ID="";
	bool _borrow=false;
	string _Reader_name = "";
};
class Reader
{
	friend class Manager;
	template<class Container>
	friend auto Login(const string& name, const string& password, Container& arr);
	friend void BorrowBook(const string& name, const string& password);
private:
	string _name;
	string _password;
	int _borrow_number;
	vector<Book> _borrow_book;
public:
	Reader(const string& name, const string& password);
	void borrow_book(const string& book_name,vector<Book>& book_arr);
	void return_book(vector<Book>& book_arr);
};