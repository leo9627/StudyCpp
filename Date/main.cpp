#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
private:
	static int n;
	int _year;
	int _month;
	int _day;
	int GetMonthDay(const int& year, const int& month)const;
public:
	Date(int year , int month = 1, int day = 1)
	{
		_year = year;
		_day = day;
		_month = month;
		n++;
	}
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
			return true;
		if (_year == d._year && _month < d._month)
			return true;
		if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		return false;
	}
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}
	Date operator+(int day) const
	{
		Date temp(*this);
		temp._day += day;
		while (temp._day > GetMonthDay(temp._year, temp._month))
		{
			temp._day -= GetMonthDay(temp._year, temp._month);
			temp._month++;
			if (temp._month > 12)
			{
				temp._month = 1;
				temp._year++;
			}
		}
		return temp;
	}

	Date& operator+=(int day)
	{
		this->_day += day;
		while (this->_day > GetMonthDay(this->_year, this->_month))
		{
			this->_day -= GetMonthDay(this->_year, this->_month);
			this->_month++;
			if (this->_month > 12)
			{
				this->_month = 1;
				this->_year++;
			}
		}
		return *this;
	}
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp._day -= day;
		while (tmp._day <= 0)
		{
			tmp._month--;
			if (tmp._month == 0)
			{
				tmp._month = 12;
				tmp._year--;
			}
			tmp._day += GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}
	int operator-(const Date& d)const
	{
		Date max = *this;
		Date min = d;
		int f = 1;
		if (max < min)
		{
			f = -1;
			max = d;
			min = *this;
		}
		int n = 0;
		while (!(min == max))
		{
			min++;
			n++;
		}
		return n*f;
	}
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	Date& operator++(int)
	{
		*this += 1;
		return *this;
	}
	Date operator++()
	{
		Date ret=*this + 1;
		return ret;
	}
	Date& operator--(int)
	{
		*this -= 1;
		return *this;
	}
	Date operator--()
	{
		Date ret = *this - 1;
		return ret;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day<<endl;
	}
	Date* operator&()
	{
		return nullptr;
	}
	static int GetN();
};
int Date::GetN()
{
	return n;
}
int Date::GetMonthDay(const int& year, const int& month) const
{
	static int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
		
	return m[month];
}
Date operator+(int x, const Date& d)
{
	return d + x;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day;
	return out;
}
int Date::n = 0;   //这里才创建空间
int main()
{
	Date d1 = Date(2024,4,13 );
	Date d2 = Date(2024,4,15 );
	d2 = 1 + d1;
	cout << d2;
	return 0;
}