#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
	// 友元函数  --  这个函数内部可以使用Date对象访问私有成员
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	//不需要写析构函数和拷贝函数，因为没有动态开辟空间，且没有指针成员

	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day < 32)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 构造会频繁调用，所以直接放在类里面定义作为inline
	Date(int year = 2023, int month = 8, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;

		//检测数据是否合法
		assert(CheckDate());
	}

	// 获取某年某月的天数
	// 会频繁调用，所以直接放在类里面定义作为inline
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };  // 因可能频繁调用，故static修饰，防止多次创建

		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return days[month];
	}

	void Print()const;  // const修饰，以兼容const成员  如：const Date d1;

	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator<(const Date& d)const;

	Date operator+(int day)const;
	Date& operator+=(int day);
	Date operator-(int day)const;
	Date& operator-=(int day);

	Date& operator++();  // 前置++
	Date operator++(int);  // 后置++
	Date& operator--(); // 前置--
	Date operator--(int); // 后置--

	// d1 - d2 计算日期差
	int operator-(const Date& d)const;


private:
	int _year;
	int _month;
	int _day;
};

// 内联函数声明和定义不应分离
// 这样设计返回值是为了可以连续调用
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate());

	return in;
}

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
