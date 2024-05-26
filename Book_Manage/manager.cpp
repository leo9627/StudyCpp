#include"manager.h"


Manager::Manager(const string& name , const string& password)
	:Person(name,password)
{}
void Manager::Add_Book(vector<Book>& book_arr)
{
	cout << "�������鼮����:";
	string name;
	cin >> name;
	cout << "�������鼮���:";
	string id;
	cin >> id;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it != book_arr.end())
	{
		cout << "Warning:���и���!!!" << endl;
		return;
	}
	Book b1 = { name,id };
	book_arr.push_back(b1);
	cout << "Notice:ִ�гɹ�!!!" << endl;

}
void Manager::Delete_Book(vector<Book>& book_arr)
{
	cout << "�������鼮����:";
	string name;
	cin >> name;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it == book_arr.end())
	{
		cout << "Warning:���鼮������!!!" << endl;
		return;
	}
	if (it->_borrow == true)
	{
		cout << "Warning:�����ѱ�����!!!" << endl;
		return;
	}
	book_arr.erase(it);
	cout << "Notice:ִ�гɹ���������" << endl;
}
vector<Reader>::iterator Manager::Find_Reader(const string& name, vector<Reader>& Reader_arr)
{
	auto it = Reader_arr.begin();
	while (it != Reader_arr.end())
	{
		if (it->_name == name)
			break;
		it++;
	}
	return it;
}
void Manager::Add_Reader(vector<Reader>& Reader_arr)
{
	cout << "�������û���:";
	string name;
	cin >> name;
	cout << "����������:";
	string password;
	cin >> password;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it != Reader_arr.end())
	{
		cout << "Warning:�����Ѵ���!!!" << endl;
		return;
	}
	Reader b1 = { name,password };
	Reader_arr.push_back(b1);
	cout << "Notice:ִ�гɹ�!!!" << endl;
}
void Manager::Delete_Reader(vector<Reader>& Reader_arr, vector<Book>& book_arr)
{
	cout << "�������û���:";
	string name;
	cin >> name;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "Warning:���û�������!!!" << endl;
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
	cout << "Notice:ִ�гɹ�!!!" << endl;
}
void Manager::Modify_Reader(vector<Reader>& Reader_arr)
{
	cout << "��������Ҫ�޸ĵ��û���:";
	string name;
	cin >> name;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "Warning:���û�������!!!" << endl;
		return;
	}
	cout << "�������µ��û���:";
	string newName;
	cin >> newName;
	cout << "�������µ�����:";
	string newpassword;
	cin >> newpassword;
	it->_name = newName;
	it->_password = newpassword;
	cout << "Notice:ִ�гɹ�!!!" << endl;
}