#include"biginteger.h"
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
string Add(const string& a, const string& b)
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
string Sub(const string& x, const string& y)
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
	while (i < vmax.size() && vmax[i] == 0)
		i++;
	for (; i < vmax.size(); i++)
	{
		ret.push_back(vmax[i] + '0');
	}
	if (f)
		ret.insert(0, "-");
	if (ret.size())
		return ret;
	else
		return "0";
}
string Mul(const string& x, const string& y)
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
	string sum = "0";
	string temp;
	string temp2 = "0";
	for (int i = b.size() - 1; i >= 0; i--)
	{
		temp2 = "0";
		for (int j = 1; j <= b[i] - '0'; j++)
		{
			temp2 = Add(temp2, a);
		}
		temp2 += temp;  //一位相乘的结果
		temp += "0";
		sum = Add(sum, temp2);
	}
	if (f && sum != "0")
		sum = "-" + sum;
	return sum;
}
string Div(const string& x, const string& y)
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
	int end = a.size() - b.size() + 1;
	int k = b.size();
	string ret = "0";
	string ta;
	while ((int)ret.size() <= end)
	{
		string ret1 = "1";
		string temp = "1";
		ta = a.substr(0, k);  //要被除的字符串
		string tb = b;
		while (temp != "0" && temp[0] != '-')
		{
			temp = Mul(b, ret1);
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
			a = Sub(ta, Mul(b, ret1)) + a.substr(k);
			k = Sub(ta, Mul(b, ret1)).size() + 1;
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