#include"manager.h"
 
const char* file1 = "������Ϣ.txt";
const char* file2 = "ͼ����Ϣ.txt";
const char* file3 = "����Ա��Ϣ.txt";
const char* file4 = "��������Ϣ.txt";
vector<Book> Book_arr;
vector<Manager> Manager_arr;
vector<Reader> Reader_arr;
void Menu();
template<class Container>
auto Login(const string& name, const string& password, Container& arr);
void BorrowBook(const string& name, const string& password);
void ReturnBook(const string& name, const string& password);
void Book_Manage(const string& name, const string& password);
void Reader_Manage(const string& name, const string& password);
void Read_Data();
void Write_Data();
int main()
{
	cout << "����������!!!" << endl;
	Read_Data();
	cout << "�������!!!" << endl;
	string s;
	int select = 0;
	do
	{
		Menu();
		cin >> s;
		for (auto& e : s)
		{
			if (!(e >= '0' && e <= '9'))
			{
				s = "5";
			}
		}
		select = stoi(s);
		string name;
		string password;
		if (select<=4&&select>=1)
		{
			cout << "�������˺�:";
			cin >> name;
			cout << "����������:";
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
		//default:
		}
	} while (select);
	Write_Data();
	return 0;
}


void Menu()
{
	cout << "--------------MENU--------------" << endl;
	cout << "1.����            2.����" << endl;
	cout << "3.ͼ����Ϣ����    4.������Ϣ����" << endl;
	cout << "0.�˳�ϵͳ               " << endl;
	cout << "--------------------------------" << endl;
	cout << "����������ı��:";
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
	auto it = Login(name, password, Reader_arr);
	if (it == Reader_arr.end())
	{
		cout << "Warning:�Ƿ��û�!!!" << endl;
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
		cout << "Warning:�Ƿ��û�!!!" << endl;
		return;
	}
	it->return_book(Book_arr);
}
void Book_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "Warning:�Ƿ��û�!!!" << endl;
		return;
	}
	int select = 0;
	cout << "--------------MENU--------------" << endl;
	cout << "1.���ͼ��        2.ɾ��ͼ��" << endl;
	cout << "--------------------------------" << endl;
	string s;
	cout << "����������ı��:";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "Warning:�������!!!" << endl;
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
		cout << "Warning:�������!!!" << endl;
	}
}
void Reader_Manage(const string& name, const string& password)
{
	auto it = Login(name, password, Manager_arr);
	if (it == Manager_arr.end())
	{
		cout << "Warnimg:�Ƿ��û�!!!" << endl;
		return;
	}
	int select = 0;
	cout << "--------------MENU--------------" << endl;
	cout << "1.��Ӷ�����Ϣ    2.�޸Ķ�����Ϣ" << endl;
	cout << "3.ɾ��������Ϣ" << endl;
	cout << "--------------------------------" << endl;
	string s;
	cout << "����������ı��:";
	cin >> s;
	for (auto& e : s)
	{
		if (!(e >= '0' && e <= '9'))
		{
			cout << "Warning:�������!!!" << endl;
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
		cout << "Warning:�������!!!" << endl;
	}
}

void Read_Data()
{


	string name;
	string password;
	int num = 0;

	//������Ϣ����
	ifstream f1(file1, ios::in);
	if (f1)
	{
		while (f1 >> name >> password >> num)
		{
			Reader r(name, password, num);
			Reader_arr.push_back(r);
		}
		f1.close();
	}

	//ͼ����Ϣ����
	f1.open(file2, ios::in);
	if (f1)
	{
		string n1;
		bool n2;
		while (f1 >> name >> n1 >> n2)
		{
			Book b;
			b._name = name;
			b._ID = n1;
			b._borrow = n2;
			Book_arr.push_back(b);
		}
		f1.close();
	}
	f1.open(file3, ios::in);
	if (f1)
	{
		while (f1 >> name >> password)
		{
			Manager m(name, password);
			Manager_arr.push_back(m);
		}
		f1.close();
	}
	f1.open(file4, ios::in);
	if (f1)
	{
		string name2;
		while (f1 >> name >> name2 >> num)
		{
			auto it1 = Manager().Find_Reader(name, Reader_arr);
			auto it2 = Manager().Find_Book(name2, Book_arr);
			it2->_borrow = true;
			it2->_Reader_name = name;
			it1->_borrow_book.push_back(*it2);
		}
		f1.close();
	}


}
void Write_Data()
{
	ofstream file(file1, ios::out);
	for (auto& e : Reader_arr)
	{
		file << e._name << "   " << e._password << "   " << e._borrow_number << endl;
	}
	file.close();

	file.open(file2, ios::out);
	for (auto& e : Book_arr)
	{
		file << e._name << "  " << e._ID << "  " << e._borrow << endl;
	}
	file.close();
	file.open(file4, ios::out);
	for (auto& e : Reader_arr)
	{
		for (auto& i : e._borrow_book)
		{
			file << e._name << "  " << i._name << "  " << i._ID << endl;
		}
	}
	file.close();
}