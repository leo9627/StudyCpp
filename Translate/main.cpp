#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include"list.h"
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;
int C(int a, int b)
{
	if (b == 0 || a == b)
		return 1;
	return C(a-1,b)+C(a-1,b-1);
}
int gcd(int a, int b)
{
	int max = a;
	int min = b;
	if (b > a)
		swap(max, min);
	while (min)
	{
		int k = min;
		min = max % min;
		max = k;
	}
	return max;
}
int Translate_1(string s)
{
	size_t pos=s.find(',');
	string x1 = s.substr(1, pos-1);
	string x2 = s.substr(pos + 1,s.size()-pos-2);
	int a = stoi(x1);
	int b = stoi(x2);
	if (s[0] == '[')
	{
		return (a * b) / gcd(a, b);
	}
	else
	{
		return gcd(a, b);
	}
}
int Translate_2(string s)
{
	int year, month, day;
	sscanf(s.c_str(),"(%d/%d/%d)",&year,&month,&day);
	int sum = 0;
	for (int i = 1; i < year; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		{
			sum += 366;
		}
		else
			sum += 365;
	}
	int mday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i < month; i++)
	{
		if ((i == 2)&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			sum += 29;
		}
		else
		{
			sum += mday[i];
		}
	}
	sum += day;
	return sum % 7;
}
int Translate_3(string s)
{
	int a = 0;
	int b = 0;
	sscanf(s.data(), "(%d,%d)", &a, &b);
	return C(a, b)/C(b,b);
}
double Translate_4(string s)
{
	size_t pos = s.find(',');
	string x1 = s.substr(1, pos - 1);
	string x2 = s.substr(pos + 1, s.size() - pos - 2);
	int a = stoi(x1);
	int b = stoi(x2);
	double sum = 0;
	if (a > 60)
	{
		sum += 3 * b * (a - 60);
	}

	if (a > 40)
	{
		sum+= 1.5 * b * ((a>60?60:a) - 40);
	}
	sum += b * (a > 40 ? 40 : a);
	return sum;
}
int Factorial(int a)
{
	if (a == 1)
		return 1;
	return a * Factorial(a - 1);
}
int Translate_5(string s)
{
	int a = 0;
	sscanf(s.data(), "(%d)", &a);
	return Factorial(a);
}
void Load_Data_Dict(map<string, string>& m, list& l)
{
	string key;
	string value;
	ifstream in("dict.txt");
	while (in >> key >> value)
	{
		m[key] = value;
	}
	string sub;
	in.close();
	in.open("input.txt");
	while (in>>sub)
	{
		if (sub[0] == '(' || sub[0] == '{' || sub[0] == '<' || sub[0] == '[')
		{

			if (sub[0] == '(')
			{
				if (sub.find(',') != string::npos)
				{
					size_t pos = sub.find(',');
					string x1 = sub.substr(1, pos - 1);
					string x2 = sub.substr(pos + 1, sub.size() - pos - 2);
					if (m.find(x1) != m.end())
						x1 = m[x1];
					if (m.find(x2) != m.end())
						x2 = m[x2];
					l.push_back('(' + x1 + ',' + x2 + ')');
				}
				else if (sub.find('/') != string::npos)
				{
					size_t pos1 = sub.find('/');
					string x1 = sub.substr(1, pos1 - 1);

					size_t pos2 = sub.find('/', pos1 + 1);
					string x2 = sub.substr(pos1 + 1, pos2 - 1 - pos1);

					string x3 = sub.substr(pos2 + 1, sub.size() - pos2 - 2);
					if (m.find(x1) != m.end())
						x1 = m[x1];
					if (m.find(x2) != m.end())
						x2 = m[x2];
					if (m.find(x3) != m.end())
						x3 = m[x3];
					l.push_back('(' + x1 + '/' + x2 + '/' + x3 + ')');
				}
				else
				{
					string x1 = sub.substr(1, sub.size() - 2);
					if (m.find(x1) != m.end())
						x1 = m[x1];
					l.push_back('(' + x1 + ')');
				}

			}
			else
			{
				size_t pos = sub.find(',');
				string x1 = sub.substr(1, pos - 1);
				string x2 = sub.substr(pos + 1, sub.size() - pos - 2);
				if (m.find(x1) != m.end())
					x1 = m[x1];
				if (m.find(x2) != m.end())
					x2 = m[x2];


				if (sub[0] == '{')
					l.push_back('{' + x1 + ',' + x2 + '}');
				else if (sub[0] == '<')
					l.push_back('<' + x1 + ',' + x2 + '>');
				else if (sub[0] == '[')
					l.push_back('[' + x1 + ',' + x2 + ']');

			}
		}
		else
		{

			if (m.find(sub) != m.end())
				sub = m[sub];
			l.push_back(sub);
		}
	}
	in.close();
}

void Write_Reasult(vector<double>& v)
{
	ofstream out("result.txt");
	
	for (auto& e : v)
	{
		out <<std::fixed<< e << " ";
	}
	out.close();
}
string removeTrailingZeros(double num) {
	std::ostringstream out;
	out << std::fixed << num;
	std::string str = out.str();
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	if (str.back() == '.') {
		str.pop_back();
	}
	return str;
}
int main()
{
	map<string, string> m;
	list l;
	Load_Data_Dict(m, l);
	vector<double> v;
	string ans;
	for (auto& e : l)
	{
		if (e[0] >= '0' && e[0] <= '9')
		{
			v.push_back(stoi(e));
			ans = ans + e + ' ';
		}
		else if (e[0] == '(')
		{
			if (e.find(',') != string::npos)
			{
				int ret = Translate_3(e);
				v.push_back(ret);
				ans = ans + to_string(ret) + ' ';
			}
			else if (e.find('/') != string::npos)
			{
				int ret = Translate_2(e);
				v.push_back(ret);
				ans = ans + to_string(ret) + ' ';
			}
			else
			{
				int ret = Translate_5(e);
				v.push_back(ret);
				ans = ans + to_string(ret) + ' ';
			}
		}
		else if (e[0] == '<')
		{
			double ret=Translate_4(e);
			v.push_back(ret);
			ans = ans + to_string(ret) + ' ';
		}
		else if (e[0]=='{')
		{
			int ret = Translate_1(e);
			v.push_back(ret);
			ans = ans + to_string(ret) + ' ';
		}
		else if (e[0] == '[')
		{
			int ret = Translate_1(e);
			v.push_back(ret);
			ans = ans + to_string(ret) + ' ';
		}

	}
	sort(v.begin(), v.end());
	ofstream out("result.txt");
	for (auto& e : v)
	{
		string temp = removeTrailingZeros(e);
		cout << temp<< " ";
		out << temp<<" ";
	}
	out.close();
	return 0;
}