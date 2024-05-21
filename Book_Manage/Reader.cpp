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
		cout << "�ѽ�5��" << endl;
		return;
	}
	for (auto& e : book_arr)
	{
		if (e._name == book_name)
		{
			if (e._borrow == true)
			{
				cout << "�ѱ�����" << endl;
				return;
			}
			e._borrow = true;
			e._Reader_name = _name;
			_borrow_book.push_back(e);
			_borrow_number++;
			cout << "���ĳɹ�!!!!" << endl;
			return;
		}
	}
	cout << "û���Ȿ��" << endl;

}
void Reader::return_book(vector<Book>& book_arr)
{
	int num = 1;
	if (_borrow_book.size() == 0)
	{
		cout << "û�н����鼮������" << endl;
		return;
	}
	for (auto& e : _borrow_book)
	{
		cout <<num<<"  "<< e._name << "   " << e._ID << endl;
		num++;
	}
	string s ;
	cout << "������Ҫ�黹�鼮����ţ�";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "������󣡣���" << endl;
			return;
		}
	}
	int i = stoi(s);
	if (i > _borrow_book.size()||i<=0)
	{
		cout << "������󣡣���" << endl;
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
			cout << "�黹�ɹ�" << endl;
			return;
		}
	}
}