#include"Reader.h"
Reader::Reader(const string& name, const string& password,int x)
	:Person(name,password)
	,_borrow_number(x)
{}
void Reader::borrow_book(const string& book_name, vector<Book>& book_arr)
{
	if (_borrow_book.size() == 5)
	{
		cout << "Warning:已借5本,已达上限!!!" << endl;
		return;
	}
	auto it = Find_Book(book_name, book_arr);
	if (it == book_arr.end())
	{
		cout << "Warning:该书籍不存在!!!" << endl;
		return;
	}
	if (it->_borrow == true)
	{
		cout << "Warning:该书籍已被借阅!!!" << endl;
		return;
	}
	it->_borrow = true;
	it->_Reader_name = _name;
	_borrow_book.push_back(*it);
	_borrow_number++;
	cout << "Notice:借阅成功!!!!" << endl;
}
void Reader::return_book(vector<Book>& book_arr)
{
	int num = 1;
	if (_borrow_book.size() == 0)
	{
		cout << "Notice:无借阅书籍!!!" << endl;
		return;
	}
	//打印
	sort(_borrow_book.begin(), _borrow_book.end());
	cout << "--------------------------------" << endl;
	cout << "     已借阅的书籍     |  图书ID" << endl;
	for (auto& e : _borrow_book)
	{
		cout <<"("<<num<<")  " <<setw(17) <<std::left<< e._name << "|  " << e._ID << endl;
		num++;
	}
	cout << "--------------------------------" << endl;
	string s ;
	cout << "请输入需要归还书籍的ID：";
	cin >> s;
	auto it1 = Find_Book(s, _borrow_book);
	auto it2 = Find_Book(s, book_arr);
	if (it1 == _borrow_book.end() || it2 == book_arr.end())
	{
		cout << "Warning:输入错误!!!" << endl;
	}
	it2->_Reader_name = "";
	it2->_borrow = false;
	_borrow_book.erase(it1);
	_borrow_number--;
	cout << "Notice:归还成功!!!" << endl;
}