#include "Date.h"

void Date::Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//�κ�һ���ֻ࣬��Ҫдһ�� > == ���� < == ���أ�ʣ�±Ƚ���������ظ��ü���
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);  // ����==�����
}

bool Date::operator>(const Date& d)const
{
	if (_year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}

// ˼����Ϊʲô��д+=����д+��
// �����÷��أ����Ա��⿽�����죬���Ч��
Date& Date::operator+=(int day)
{
	//Ϊ������ + (-x)������
	if (day < 0)
	{
		return *this -= -day;  // ���ϸ������൱�ڼ�ȥ����
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

// ֻ�ܴ�ֵ����
Date Date::operator+(int day)const
{
	Date ret(*this);
	ret += day;

	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)const
{
	Date ret = *this;  // Date ret(*this);��һ��д��
	ret -= day;

	return ret;
}

// ǰ��++�ͺ���++�����𣺲����б�ͬ --> int
Date& Date::operator++()  // ǰ��++
{
	return *this += 1;
}

Date Date::operator++(int)  // ����++
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}
Date& Date::operator--() // ǰ��--
{
	return *this -= 1;
}

Date Date::operator--(int) // ����--
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

// d1 - d2 �������ڲ�
int Date::operator-(const Date& d)const
{
	int flag = 1;  //���ڿ�����������d1 > d2����Ϊ����������Ϊ����
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	// �ۼƼ�����ֱ��min == max
	int n = 0;
	while (min != max)
	{
		++min;  //˼��Ϊʲô������++min��������min++?  -->  ǰ��++�����÷��أ����⿽�����죬���Ч��
		++n;
	}

	return n * flag;
}

// ����д�����ã���Ϊ�����غ�����һ��������thisָ�룬���ڶ���������Date���󣬲�����ϰ��
// �������������� d1 << cin;
//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month << "-" << _day << endl;
//}