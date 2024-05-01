#include"String.h"

using leo::string;
int main()
{
	
	string s1 = "hello";
	cin >> s1;
	cout << s1<<endl;
	int a = 0;
	cin >> a;
	cout << a<<endl;
	/*s1.push_back(' ');
	cout << s1<<endl;
	s1.append("world");
	cout << s1 << endl;
	s1.insert(0, 'k');
	cout << s1 << endl;
	s1.erase(1,5);
	cout << s1 << endl;*/
	
	return 0;
}
//int main()
//{
//	leo::string s1 = "hello word";
//	leo::string s2=s1;
//	//s2[2]++;
//	/*s1.rsize(12,'c');
//	s1.reverse(20);*/
//	s1.append("hahah");
//	s2.append("hahha");
//	s2.push_back('c');
//	for (auto i : s1)
//	{
//		cout << i << " ";
//	}
//	/*cout << s1 << endl;
//	cout << s2;*/
//	return 0;
//}
//int main()
//{
//	leo::string s1 = "hello";
//	leo::string s2 = s1;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		s1[i]++;
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < s2.size(); i++)
//	{
//		s2[i]++;
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	leo::string s3 = "world";
//	//leo::string s4=nullptr;
//	s2 = s3;
//	s3[0]++;
//	for (int i = 0; i < s2.size(); i++)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	cout << s2.c_str() << endl;
//	cout << s3.c_str() << endl;
//	return 0;
//}
//int main()
//{
//	std::string s1 = "bit.cpp.zip";
//	int pos = s1.rfind('.');
//	cout << s1.substr(pos);
//	return 0;
//}
//int main()
//{
//	string url = "https://cplusplus.com/reference/string/string/";
//	int pos = url.find("://");
//	if (pos != string::npos)
//	{
//		cout << url.substr(0, pos)<<endl;
//	}
//	int pos1 = url.find('/',pos + 3 );
//	if (pos1 != string::npos)
//	{
//		cout << url.substr(pos + 3, pos1 - pos - 3)<<endl;
//	}
//	cout << url.substr(pos1);
//}
//int main()
//{
//	string s1 = "hello world";
//	//s1.insert(2, 1,'k');
//	//s1.insert(s1.begin()+2, 'k');
//	//s1.resize(20,'k');
//	s1.reserve(50);
//	s1.reserve(5);
//	cout << s1;
//	return 0;
//}
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