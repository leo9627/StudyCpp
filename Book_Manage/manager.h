#pragma once
#include"Reader.h"


class Manager
{
	template<class Container>
	friend auto Login(const string& name, const string& password, Container& arr);
private:
	string _name;
	string _password;
public:
	Manager(const string& name = "", const string& password = "");
	void Add_Book(vector<Book>& book_arr);
	void Delete_Book(vector<Book>& book_arr);
	vector<Book>::iterator Find_Book(const string& name, vector<Book>& book_arr);
	vector<Reader>::iterator Find_Reader(const string& name, vector<Reader>& Reader_arr);
	void Add_Reader(vector<Reader>& Reader_arr);
	void Delete_Reader(vector<Reader>& Reader_arr, vector<Book>& book_arr);
	void Modify_Reader(vector<Reader>& Reader_arr);
};