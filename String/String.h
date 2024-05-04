#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cassert>
#include<cstring>
#include<string>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

namespace leo
{
	/*class string
	{
	private:
		char* _str;
	public:
		string(const char* str = "")
		{
			assert(str);
			_str=new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s):_str(nullptr)
		{
			string stemp(s._str);
			std::swap( stemp._str,_str);
		}
		string& operator=(const string& s)
		{
			if (this == &s)
				return *this;
			string stemp = s;
			std::swap(stemp._str, _str);
			return *this;
		}
		size_t size()
		{
			return strlen(_str);
		}
		char& operator[](size_t i)
		{
			return _str[i];
		}
		char* c_str()
		{
			return _str;
		}
		~string()
		{
			if (_str == nullptr)
				return;
			delete[] _str;
			_str = nullptr;
		}
	};*/
	class string
	{
	private:
		static size_t npos;
		char* _str;
		size_t _size;   //已经有多少个有效字符
		size_t _capacity;  //最多存多少个有效字符
	public:
		typedef char* iterator;
		string(const char* str = "");
		string(const string& s);
		void reverse(size_t n);
		void rsize(size_t n,char c='\0');
		string& operator=(string s);
		void push_back(const char c);
		void append(const char* str);
		void insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		string& erase(size_t pos, size_t len=npos);
		size_t find(char c);
		size_t find(const char* str);
		char& operator[](size_t i);
		const char& operator[](size_t i)const;
		string& operator+=(const char c);
		string& operator+=(const char* str);
		string& operator<(const string& s);
		string& operator=(const string& s);
		string& operator<=(const string& s);
		size_t size()const;
		size_t capacity()const;
		const char* c_str()const;
		iterator begin();
		iterator end();
		~string();
		
	};
	std::ostream& operator<<(std::ostream& out, const string& s);
	std::istream& operator>>(std::istream& out,string& s);
}
