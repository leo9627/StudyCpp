#include<iostream>
#include<string>
#include<vector>
using namespace std;
//struct Node
//{
//	char _val;
//	Node* _next;
//};
//void f(Node*& str1, Node*& str2)
//{
//	Node* n1 = new Node;
//	Node* n2 = new Node;
//	Node* n3 = new Node;
//	Node* n4 = new Node;
//	Node* n5 = new Node;
//	Node* n6 = new Node;
//	Node* n7 = new Node;
//	Node* n8 = new Node;
//	n2->_val = 'l';
//	n3->_val = 'o';
//	n4->_val = 'a';
//	n5->_val = 'd';
//	n6->_val = 'i';
//	n7->_val = 'n';
//	n8->_val = 'g';
//	n1->_next = n2;
//	n2->_next = n3;
//	n3->_next = n4;
//	n4->_next = n5;
//	n5->_next = n6;
//	n6->_next = n7;
//	n7->_next = n8;
//	n8->_next = nullptr;
//	Node* t1 = new Node;
//	Node* t2 = new Node;
//	Node* t3 = new Node;
//	t2->_val = 'b';
//	t3->_val = 'e';
//	t1->_next = t2;
//	t2->_next = t3;
//	t3->_next = n6;
//	str1 = n1;
//	str2 = t1;
//}
//int Find(Node* str1,Node*str2)
//{
//	int len1 = 0;
//	int len2 = 0;
//	Node* cur = str1;
//	while (cur != nullptr)
//	{
//		len1++;
//		cur = cur->_next;
//	}
//	cur = str2;
//	while (cur != nullptr)
//	{
//		len2++;
//		cur = cur->_next;
//	}
//	Node* t1 = str1;
//	Node* t2 = str2;
//	if (len1 > len2)
//	{
//		int i = len1 - len2;
//		while (i--)
//			t1 = t1->_next;
//	}
//	if (len1 < len2)
//	{
//		int i = len2 - len1;
//		while (i--)
//			t2 = t2->_next;
//	}
//	int pos = 0;
//	while (t1 != t2)
//	{
//		pos++;
//		t1 = t1->_next;
//		t2 = t2->_next;
//	}
//	return pos;
//}
//int main()
//{
//	Node* str1;
//	Node* str2;
//	f(str1, str2);
//	int pos = Find(str1, str2);
//	cout << pos;
//	return 0;
//}
//int f(Node* head)
//{
//	Node* slow ;
//	Node* faster ;
//	if (head && head->_next)
//	{
//		slow=head->_next;
//		faster = head->_next->_next;
//	}
//	else
//		return -1;
//	
//	while (slow != faster&&faster!=nullptr&&faster->_next!=nullptr)
//	{
//		faster = faster->_next->_next;
//		slow = slow->_next;
//	}
//	if (slow != faster)
//		return -1;
//	int pos = 0;
//	while (head != slow)
//	{
//		pos++;
//		head = head->_next;
//		slow = slow->_next;
//	}
//	return pos;
//}
//int main()
//{
//	Node* n1 = new Node;
//	Node* n2 = new Node;
//	Node* n3 = new Node;
//	Node* n4 = new Node;
//	n1->_val = 3;
//	n2->_val = 2;
//	n3->_val = 0;
//	n4->_val = -4;
//	n1->_next = n2;
//	n2->_next = n3;
//	n3->_next = n4;
//	n4->_next = n2;
//	Node* head = n1;
//	cout << f(head);
//	return 0;
//}
//struct Node
//{
//	int _val;
//	Node* _next;
//};
//void BuildList(Node*& head,int n)
//{
//	Node* newNode = new Node;
//	newNode->_val = 1;
//	newNode->_next = newNode;
//	head = newNode;
//	Node* ptail = head;
//	int k = 2;
//	while (k <= n)
//	{
//		newNode = new Node;
//		newNode->_val = k;
//		newNode->_next = ptail->_next;
//		ptail->_next = newNode;
//		ptail = ptail->_next;
//		k++;
//	}
//}
//void Reverse(Node*& head)
//{
//	Node* prev = head;
//	Node* cur = head->_next;
//	Node* next = cur->_next;
//	Node* end = head->_next;
//	do
//	{
//		cur->_next = prev;
//		prev = cur;
//		cur = next;
//		next = next->_next;
//	} while (cur!=end);
//}
//void PrintList(Node* &head)
//{
//	Node* cur = head;
//	while (cur->_next != head)
//	{
//		cout << cur->_val<<"->";
//		cur = cur->_next;
//	}
//	cout << cur->_val;
//
//}
//int main1()
//{
//	Node* head = nullptr;
//	int n = 5;
//	BuildList(head, n);
//	PrintList(head);
//	cout << endl;
//	int interval = 3;
//	Node* cur = head;
//	Node* prev = head;
//	while (prev->_next != head)
//		prev = prev->_next;
//	while (cur != cur->_next)
//	{
//		for (int i = 0; i < interval - 1; i++)
//		{
//			prev = cur;
//			cur = cur->_next;
//		}
//		prev->_next = cur->_next;
//		delete cur;
//		cur = prev->_next;
//		Reverse(cur);
//	}
//	cout << cur->_val;
//	return 0;
//}
//int main()
//{
//	Node* head=nullptr;
//	int n = 5;
//	BuildList(head, n);
//	PrintList(head);
//	cout << endl;
//	Reverse(head);
//	PrintList(head);
//	cout << endl;
//	int interval = 3;
//	Node* cur = head;
//	Node* prev = head;
//	while (prev->_next != head)
//		prev = prev->_next;
//	while (cur != cur->_next)
//	{
//		for (int i = 0; i < interval-1; i++)
//		{
//			prev = cur;
//			cur = cur->_next;
//		}
//		prev->_next = cur->_next;
//		delete cur;
//		cur = prev->_next;
//	}
//	cout << cur->_val;
//	return 0;
//}
bool cmp(const string& a, const string& b);
void Erase(string& s);
string Add(const string& a, const string& b);
string Sub(const string& x, const string& y);
string Mul(const string& x, const string& y);
string Div(const string& x, const string& y);
string Mod(const string& a, const string& b);
//int main()
//{
//	string x;
//	string y;
//	cin >> x >> y;
//	string ret = Add(x, y);
//	cout << "Add:" << ret << endl;
//	string ret1 = Sub(x, y);
//	cout << "Sub:" << ret1 << endl;
//	string ret2 = Mul(x, y);
//	cout << "Mul:" << ret2 << endl;
//	string ret3 = Div(x, y);
//	cout << "Div:" << ret3 << endl;
//	string ret4 = Mod(x, y);
//	cout << "Mod:" << ret4 << endl;
//	return 0;
//}
bool cmp(const string& a, const string& b)
{
	if (a.size() < b.size())
	{
		return false;
	}
	if (a.size() == b.size())
	{
		size_t i = 0;
		while (i < a.size())
		{
			if ((a[i] - '0') < (b[i] - '0'))
			{

				return false;
			}
			else if ((a[i] - '0') > (b[i] - '0'))
			{
				return true;
			}
			else
			{
				i++;
			}

		}
	}
	return true;
}
void Erase(string& s)
{
	size_t i = 0;
	for (i = 0; i < s.size() - 1; i++)
	{
		if (s[i] != '0')
		{
			break;
		}
	}
	s.erase(0, i);
}
string Add(const string& a,const string& b)
{
	int f = 0;
	string sum;
	string max = a;
	string min = b;
	if (a.size() < b.size())
	{
		max = b;
		min = a;
	}
	Erase(max);
	Erase(min);
	if (max[0] == '-' && min[0] != '-')
	{
		return Sub(min, max.substr(1));
	}
	if (min[0] == '-' && max[0] != '-')
	{
		return Sub(max, min.substr(1));
	}
	if (min[0] == '-' && max[0] == '-')
	{
		min = min.substr(1);
		max = max.substr(1);
		f = 1;
	}
	int pmax = max.size() - 1;
	int pmin = min.size() - 1;
	int n = 0;
	while (pmin >= 0)
	{
		sum.push_back((((max[pmax] - '0' + min[pmin] - '0' + n) % 10) + '0'));
		n = (max[pmax] - '0' + min[pmin] - '0' + n) / 10;
		pmax--;
		pmin--;
	}
	while (pmax >= 0)
	{
		sum.push_back(((max[pmax] - '0' + n) % 10) + '0');
		n = (max[pmax] - '0' + n) / 10;
		pmax--;
	}
	if (n)
		sum.push_back(n + '0');
	reverse(sum.begin(), sum.end());
	if (f)
		sum = "-" + sum;
	return sum;
}
string Sub( const string& x,const string& y)
{
	string a = x;
	string b = y;
	int f = 1;
	Erase(a);
	Erase(b);
	if (a[0] == '-' && b[0] != '-')
	{
		b = "-" + b;
		return Add(a, b);
	}
	if (b[0] == '-' && a[0] != '-')

		return Add(a, b.substr(1));

	if (a[0] == '-' && b[0] == '-')
		return Sub(b.substr(1), a.substr(1));
	string max = b;
	string min = a;
	if (cmp(a, b))
	{
		f = 0;
		max = a;
		min = b;
	}

	vector<int> vmax;
	vector<int> vmin;
	for (auto i : max)
	{
		vmax.push_back(i - '0');
	}
	for (auto i : min)
	{
		vmin.push_back(i - '0');
	}
	int pmin = vmin.size() - 1;
	int pmax = vmax.size() - 1;
	while (pmin >= 0)
	{
		if (vmax[pmax] < vmin[pmin])
		{
			vmax[pmax - 1]--;
			vmax[pmax] += 10;
			vmax[pmax] -= vmin[pmin];
		}
		else
			vmax[pmax] -= vmin[pmin];
		pmax--;
		pmin--;
	}
	while (pmax >= 0)
	{
		if (vmax[pmax] < 0)
		{
			vmax[pmax - 1]--;
			vmax[pmax] += 10;
		}
		pmax--;
	}
	string ret;
	int i = 0;
	while (i < vmax.size()&&vmax[i]==0)
		i++;
	for (; i < vmax.size(); i++)
	{
		ret.push_back(vmax[i]+'0');
	}
	if (f)
		ret.insert(0, "-");
	if (ret.size())
		return ret;
	else
		return "0";
}
string Mul( const string& x, const string& y)
{
	string a = x;
	string b = y;
	int f = 0;
	if (a[0] == '-' && b[0] != '-')
	{
		f = 1;
		a = a.substr(1);
	}
	if (b[0] == '-' && a[0] != '-')
	{
		f = 1;
		b = b.substr(1);
	}
	if (a[0] == '-' && b[0] == '-')
		return Mul(b.substr(1), a.substr(1));
	string sum="0";
	string temp;
	string temp2 = "0";
	for (int i = b.size() - 1; i >=0; i--)
	{
		temp2 = "0";
		for (int j = 1; j <= b[i]-'0'; j++)
		{
			temp2 = Add(temp2, a);
		}
		temp2 += temp;  //一位相乘的结果
		temp += "0";  
		sum = Add(sum, temp2);
	}
	if (f&&sum!="0")
		sum = "-" + sum;
	return sum;
}
string Div( const string& x,  const string& y)
{
	if (y == "0")
		return "error";
	if (x[0] == '-' && y[0] != '-')
	{
		string temp = Div(x.substr(1), y);
		if (temp == "0")
			return temp;
		return "-" + temp;
	}
	if (y[0] == '-' && x[0] != '-')
	{
		string temp = Div(x, y.substr(1));
		if (temp == "0")
			return temp;
		return "-" + temp;

	}
	if (x[0] == '-' && y[0] == '-')
		return Div(x.substr(1), y.substr(1));

	string a = x;
	string b = y;
	int end = a.size()-b.size()+1;
	int k = b.size();
	string ret="0";
	string ta;
	while ((int)ret.size()<=end)
	{
			string ret1 = "1";
			string temp="1";
			ta = a.substr(0,k);  //要被除的字符串
			string tb = b;
			while (temp!="0" && temp[0] != '-')
			{
				temp=Mul(b, ret1);
				temp = Sub(ta, temp);
				ret1 = Add(ret1, "1");
			}
			ret1 = Sub(ret1, "1");
			if (temp[0] == '-')
			{
				ret1 = Sub(ret1, "1");
			}
			ret.push_back(ret1[0]);
			if (ret1[0] != '0')
			{
				a = Sub(ta,Mul(b,ret1)) + a.substr(k);
				k = Sub(ta, Mul(b, ret1)).size()+1;
			}
			else
			{
				k++;
			}
					
	}
	Erase(ret);
	return ret;
}
string Mod(const string& a, const string& b)
{
	string div = Div(a, b);
	if (div == "error")
		return div;
	string ret = Sub(a, Mul(div, b));
	return ret;
}
//struct Student
//{
//	int id;
//	string name;
//	float height;
//	int arr[10];
//
//};
//int cmp(const void* x, const void* y)
//{
//	Student* a = *(Student**)x;
//	Student* b = *(Student**)y;
//	int a1 = (a->arr[0] + a->arr[1] + a->arr[2]) / 3;
//	int b1= (b->arr[0] + b->arr[1] + b->arr[2]) / 3;
//	return b1 - a1;
//}
//Student* arr[3];
//
//int f(int k)
//{
//	return arr[k - 1]->id;
//}
//int g(int k)
//{
//	int i = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		if (k == (arr[i]->arr[0] + arr[i]->arr[1] + arr[i]->arr[2]) / 3)
//			return arr[i]->id;
//	}
//	return -1;
//}
//int main()
//{
//	Student s1 = { 1,"zhansan",185,{98,88,66} };
//	Student s2 = { 2,"lisi",185,{77,88,66} };
//	Student s3 = { 3,"wangwu",185,{98,44,66} };
//	//arr[3] = { &s1,&s2,&s3 };
//	arr[0] = &s1;
//	arr[1] = &s2;
//	arr[2] = &s3;
//	qsort(arr, 3, sizeof(Student*), cmp);
//	int k = 1;
//	int ret=f(1);
//	cout << ret << endl;
//	ret=g(77);
//	cout << ret << endl;
//
//}
//struct Node
//{
//	int _val;
//	Node* next;
//};
//int main()
//{
//	Node* head = nullptr;
//	Node* n1 = new Node;
//	Node* n2 = new Node;
//	Node* n3 = new Node;
//	Node* n4 = new Node;
//	n1->_val = 1;
//	n2->_val = 2;
//	n3->_val = 3;
//	n4->_val = 4;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = nullptr;
//	head = n1;
//	cout << head->_val << endl;
//	Node* prev = nullptr;
//	Node* cur = head;
//	int k = 1;
//	k = k - 1;
//	while (k--)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	if (prev == nullptr)
//	{
//		head = cur->next;
//		delete cur;
//	}
//	else
//	{
//		prev->next = cur->next;
//		delete cur;
//	}
//	prev = nullptr;
//	cur = head;
//	while (cur->_val != 4)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	if (prev == nullptr)
//	{
//		head = cur->next;
//		delete cur;
//	}
//	else
//	{
//		prev->next = cur->next;
//		delete cur;
//	}
//
//	prev = nullptr;
//	cur = head;
//	Node* newNode = new Node;
//	newNode->_val = 9;
//	newNode->next = nullptr;
//	int x = 2;
//	x = x - 1;
//	while (x--)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	if (prev == nullptr)
//	{
//		newNode->next = head;
//		head = newNode;
//	}
//	else
//	{
//		newNode->next = cur;
//		prev->next = newNode;
//	}
//	cur = head;
//	while (cur != nullptr)
//	{
//		cout << cur->_val << "->";
//		cur = cur->next;
//	}
//	cout << "NULL";
//	return 0;
//}
//int main()
//{
//	string a;
//	string b;
//	cin >> a >> b;
//	
//	string sum = Sub(a, b);
//	cout << sum;
//	return 0;
//}