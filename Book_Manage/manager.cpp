#include"manager.h"


Manager::Manager(const string& name , const string& password)
	:Person(name,password)
{}
void Manager::Add_Book(vector<Book>& book_arr)
{
	cout << "请输入书籍名称:";
	string name;
	cin >> name;
	cout << "请输入书籍编号:";
	string id;
	cin >> id;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it != book_arr.end())
	{
		cout << "Warning:已有该书!!!" << endl;
		return;
	}
	Book b1 = { name,id };
	book_arr.push_back(b1);
	cout << "Notice:执行成功!!!" << endl;

}
void Manager::Delete_Book(vector<Book>& book_arr)
{
	cout << "请输入书籍名称:";
	string name;
	cin >> name;
	vector<Book>::iterator it = Find_Book(name, book_arr);
	if (it == book_arr.end())
	{
		cout << "Warning:该书籍不存在!!!" << endl;
		return;
	}
	if (it->_borrow == true)
	{
		cout << "Warning:该书已被借阅!!!" << endl;
		return;
	}
	book_arr.erase(it);
	cout << "Notice:执行成功！！！！" << endl;
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
	cout << "请输入用户名:";
	string name;
	cin >> name;
	cout << "请输入密码:";
	string password;
	cin >> password;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it != Reader_arr.end())
	{
		cout << "Warning:读者已存在!!!" << endl;
		return;
	}
	Reader b1 = { name,password };
	Reader_arr.push_back(b1);
	cout << "Notice:执行成功!!!" << endl;
}
void Manager::Delete_Reader(vector<Reader>& Reader_arr, vector<Book>& book_arr)
{
	cout << "请输入用户名:";
	string name;
	cin >> name;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "Warning:该用户不存在!!!" << endl;
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
	cout << "Notice:执行成功!!!" << endl;
}
void Manager::Modify_Reader(vector<Reader>& Reader_arr)
{
	cout << "请输入需要修改的用户名:";
	string name;
	cin >> name;
	vector<Reader>::iterator it = Find_Reader(name, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "Warning:该用户不存在!!!" << endl;
		return;
	}
	cout << "请输入新的用户名:";
	string newName;
	cin >> newName;
	cout << "请输入新的密码:";
	string newpassword;
	cin >> newpassword;
	it->_name = newName;
	it->_password = newpassword;
	cout << "Notice:执行成功!!!" << endl;
}