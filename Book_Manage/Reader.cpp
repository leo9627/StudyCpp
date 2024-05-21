#include"Reader.h"


Reader::Reader(const string& name, const string& password)
	:_name(name)
	, _password(password)
{
	_borrow_number = 0;
}

void Reader::borrow_book(const string& book_name, vector<Book>& book_arr)
{
	if (_borrow_book.size() == 5)
	{
		cout << "已借5本" << endl;
		return;
	}
	for (auto& e : book_arr)
	{
		if (e._name == book_name)
		{
			if (e._borrow == true)
			{
				cout << "已被借阅" << endl;
				return;
			}
			e._borrow = true;
			e._Reader_name = _name;
			_borrow_book.push_back(e);
			_borrow_number++;
			cout << "借阅成功!!!!" << endl;
			return;
		}
	}
	cout << "没有这本书" << endl;

}
void Reader::return_book(vector<Book>& book_arr)
{
	int num = 1;
	if (_borrow_book.size() == 0)
	{
		cout << "没有借阅书籍！！！" << endl;
		return;
	}
	for (auto& e : _borrow_book)
	{
		cout <<num<<"  "<< e._name << "   " << e._ID << endl;
		num++;
	}
	string s ;
	cout << "输入需要归还书籍的序号：";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "输入错误！！！" << endl;
			return;
		}
	}
	int i = stoi(s);
	if (i > _borrow_book.size()||i<=0)
	{
		cout << "输入错误！！！" << endl;
		return;
	}
	for (auto& e : book_arr)
	{
		if (e._name == _borrow_book[i-1]._name)
		{
			e._Reader_name = "";
			e._borrow = false;
			_borrow_book.erase(_borrow_book.begin() + i - 1);
			_borrow_number--;
			cout << "归还成功" << endl;
			return;
		}
	}
}