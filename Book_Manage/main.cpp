#include"manager.h"
vector<Book> Book_arr;
vector<Manager> Manager_arr;
vector<Reader> Reader_arr;
void Menu()
{
	cout << "1.借书          2.还书"<<endl;
	cout << "3.图书信息管理  4.读者信息管理" << endl;
	cout << "          0.退出系统" << endl;
	cout << "输入选择:";
}
template<class Container>
//typedef vector<Manager> Container;
auto Login(const string& name, const string& password, Container& arr)
{
	auto it = arr.begin();
	while (it != arr.end())
	{
		if (name == it->_name && password == it->_password)
			break;
		it++;
	}
	return it;
}
void BorrowBook(const string& name, const string& password)
{
	auto it=Login(name, password, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "账号或密码错误";
		return;
	}
	string book_name;
	cout << "输入需要借阅的书籍：";
	cin >> book_name;
	it->borrow_book(book_name, Book_arr);
}

void ReturnBook(const string& name, const string& password)
{
	auto it = Login(name, password, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "账号或密码错误";
		return;
	}
	it->return_book(Book_arr);
}
void Book_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "账号或密码错误";
		return;
	}
	it->Add_Book(Book_arr);
	it->Delete_Book(Book_arr);
}
void Reader_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "账号或密码错误";
		return;
	}
	it->Add_Reader(Reader_arr);
	it->Delete_Reader(Reader_arr, Book_arr);
	it->Modify_Reader(Reader_arr);
}
int main()
{

	Book_arr.push_back({ "老人与海","001" });
	Manager_arr.push_back({ "zhansan","123" });
	Reader_arr.push_back({ "lishi","123" });
	Reader_arr.push_back({"wangwu","123"});
	int select = 0;
	do
	{
		Menu();
		cin >> select;
		string name;
		string password;
		if (select)
		{
			cout << "账号:";
			cin >> name;
			cout << "密码:";
			cin >> password;
		}
		switch (select)
		{
		case 1:
			BorrowBook(name, password);
			break;
		case 2:
			ReturnBook(name, password);
			break;
		case 3:
			Book_Manage(name, password);
			break;
		case 4:
			Reader_Manage(name, password);
		}
	} while (select);
	return 0;
}

