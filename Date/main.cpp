#include<iostream>
using namespace std;

class Date
{
private:
	int _year;
	int _month;
	int _day;
	int GetMonthDay(int year, int month);
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_day = day;
		_month = month;
	}
	bool operator<(const Date& d)
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
	Date operator+(int day)
	{
		Date temp;
		temp = *this;
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
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day<<endl;
	}
};
int Date::GetMonthDay(int year, int month)
{
	static int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
		
	return m[month];
}
int main()
{
	Date d1(2024,1,1);
	Date d2(2024,4,8);
	d2=d1+=1000;
	d1.Print();
	d2.Print();
	cout << (d1 <= d2);
	return 0;
}