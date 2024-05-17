#include"manager.h"


vector<Book>::iterator Manager::Find_Book(const string& name, vector<Book>& book_arr)
{
	auto it = book_arr.begin();
	while (it != book_arr.end())
	{
		if (it->_name == name)
			break;
	}
	return it;
}
void Manager::Add_Book(vector<Book>& book_arr)
{
	cout << "��������:";
	string name;
	cin >> name;
	cout << "���:";
	string id;
	cin >> id;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it != book_arr.end())
	{
		cout << "���и���" << endl;
		return;
	}
	Book b1 = { name,id };
	book_arr.push_back(b1);

}
void Manager::Delete_Book(vector<Book>& book_arr)
{
	cout << "��������:";
	string name;
	cin >> name;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it == book_arr.end())
	{
		cout << "δ�ҵ�����" << endl;
		return;
	}
	if (it->_borrow == true)
	{
		cout << "�����ѱ�����" << endl;
		return;
	}
	book_arr.erase(it);
}
vector<Reader>::iterator Manager::Find_Reader(const string& name, vector<Reader>& Reader_arr)
{
	auto it = Reader_arr.begin();
	while (it != Reader_arr.end())
	{
		if (it->_name == name)
			break;
	}
	return it;
}
void Manager::Add_Reader(vector<Reader>& Reader_arr)
{
	cout << "�����û���:";
	string name;
	cin >> name;
	cout << "��������:";
	string password;
	cin >> password;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it != Reader_arr.end())
	{
		cout << "�����Ѵ���" << endl;
		return;
	}
	Reader b1 = { name,password };
	Reader_arr.push_back(b1);
}
void Manager::Delete_Reader(vector<Reader>& Reader_arr, vector<Book>& book_arr)
{
	cout << "�����û���:";
	string name;
	cin >> name;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "���û�������" << endl;
		return;
	}

	for (int i = it->_borrow_number - 1; i >= 0; i--)
	{
		vector<Book>::iterator it_book = Find_Book(it->_borrow_book[i]._name, book_arr);
		it_book->_Reader_name = "";
		it_book->_borrow = false;
		it->_borrow_book.pop_back();
		it->_borrow_number--;
	}
	Reader_arr.erase(it);
}
void Manager::Modify_Reader(vector<Reader>& Reader_arr)
{

}

