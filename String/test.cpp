#include<iostream>
#include<string>
using namespace std;



int main()
{
	string s1 = "hello world";
	//s1.insert(2, 1,'k');
	//s1.insert(s1.begin()+2, 'k');
	//s1.resize(20,'k');
	s1.reserve(50);
	s1.reserve(5);
	cout << s1;
	return 0;
}
//int main()
//{
//	string s1 = "hello";
//	string s2(s1, 2);
//	getline(cin, s1);
//	cout << s2 << endl;
//	/*string::iterator it = s1.begin();
//	*it = 'b';
//	cout << s1;*/
//	/*for (auto i : s1)
//	{
//		cout << i << " ";
//	}*/
//	/*while (it != s1.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}*/
//	return 0;
//}
//int main()
//{
//	string s1 = "hello";
//	s1.reserve(2);
//	s1.resize(10);
//	cout << s1<<endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.clear();
//	cout << s1 << endl;
//	cout << s1.empty() << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	return 0;
//}
//int main()
//{
//	string s1;
//	string s2="hello world";
//	string s3("helloworld",5);
//	string s4(s2,3,6);
//	//s2.append("cccc");
//	//s3.push_back('a');
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//}