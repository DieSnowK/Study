#include "Date.h"

void Date::Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//任何一个类，只需要写一个 > == 或者 < == 重载，剩下比较运算符重载复用即可
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);  // 复用==运算符
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

// 思考：为什么先写+=，再写+？
// 传引用返回，可以避免拷贝构造，提高效率
Date& Date::operator+=(int day)
{
	//为了满足 + (-x)的需求
	if (day < 0)
	{
		return *this -= -day;  // 加上负数，相当于减去正数
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

// 只能传值返回
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
	Date ret = *this;  // Date ret(*this);另一种写法
	ret -= day;

	return ret;
}

// 前置++和后置++的区别：参数列表不同 --> int
Date& Date::operator++()  // 前置++
{
	return *this += 1;
}

Date Date::operator++(int)  // 后置++
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}
Date& Date::operator--() // 前置--
{
	return *this -= 1;
}

Date Date::operator--(int) // 后置--
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

// d1 - d2 计算日期差
int Date::operator-(const Date& d)const
{
	int flag = 1;  //用于控制正负，若d1 > d2，则为正数，否则为负数
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	// 累计计数，直到min == max
	int n = 0;
	while (min != max)
	{
		++min;  //思考为什么这里是++min，而不是min++?  -->  前置++传引用返回，避免拷贝构造，提高效率
		++n;
	}

	return n * flag;
}

// 这种写法不好，因为该重载函数第一个参数是this指针，而第二个参数是Date对象，不符合习惯
// 用起来是这样的 d1 << cin;
//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month << "-" << _day << endl;
//}