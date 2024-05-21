#include"manager.h"
vector<Book> Book_arr;
vector<Manager> Manager_arr;
vector<Reader> Reader_arr;
void Menu()
{
	cout << "1.����          2.����"<<endl;
	cout << "3.ͼ����Ϣ����  4.������Ϣ����" << endl;
	cout << "          0.�˳�ϵͳ" << endl;
	cout << "����ѡ��:";
}
template<class Container>
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
		cout << "�˺Ż��������";
		return;
	}
	string book_name;
	cout << "������Ҫ���ĵ��鼮��";
	cin >> book_name;
	it->borrow_book(book_name, Book_arr);
}

void ReturnBook(const string& name, const string& password)
{
	auto it = Login(name, password, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "�˺Ż��������";
		return;
	}
	it->return_book(Book_arr);
}
void Book_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "�˺Ż��������";
		return;
	}
	int select = 0;
	cout << "1.���ͼ��   2.ɾ��ͼ��" << endl;
	string s;
	cout << "����ѡ��:";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "������󣡣���" << endl;
			return;
		}
	}
	select = stoi(s);
	switch (select)
	{
	case 1:
		it->Add_Book(Book_arr);
		break;
	case 2:
		it->Delete_Book(Book_arr);
		break;
	default:
		cout << "������󣡣�" << endl;
	}
}
void Reader_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "�˺Ż��������" << endl;
		return;
	}
	int select = 0;
	cout << "1.��Ӷ�����Ϣ  2.�޸Ķ�����Ϣ  3.ɾ��������Ϣ" << endl;
	string s;
	cout << "����ѡ��:";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "������󣡣���" << endl;
			return;
		}
	}
	select = stoi(s);
	switch (select)
	{
	case 1:
		it->Add_Reader(Reader_arr);
		break;
	case 2:
		it->Modify_Reader(Reader_arr);
		break;
	case 3:
		it->Delete_Reader(Reader_arr, Book_arr);
		break;
	default:
		cout << "�������" << endl;
	}
}
int main()
{

	Book_arr.push_back({ "�����뺣","001" });
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
			cout << "�˺�:";
			cin >> name;
			cout << "����:";
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