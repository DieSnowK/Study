#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
	// ��Ԫ����  --  ��������ڲ�����ʹ��Date�������˽�г�Ա
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	//����Ҫд���������Ϳ�����������Ϊû�ж�̬���ٿռ䣬��û��ָ���Ա

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

	// �����Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
	Date(int year = 2023, int month = 8, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;

		//��������Ƿ�Ϸ�
		assert(CheckDate());
	}

	// ��ȡĳ��ĳ�µ�����
	// ��Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };  // �����Ƶ�����ã���static���Σ���ֹ��δ���

		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return days[month];
	}

	void Print()const;  // const���Σ��Լ���const��Ա  �磺const Date d1;

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

	Date& operator++();  // ǰ��++
	Date operator++(int);  // ����++
	Date& operator--(); // ǰ��--
	Date operator--(int); // ����--

	// d1 - d2 �������ڲ�
	int operator-(const Date& d)const;


private:
	int _year;
	int _month;
	int _day;
};

// �������������Ͷ��岻Ӧ����
// ������Ʒ���ֵ��Ϊ�˿�����������
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate());

	return in;
}

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}
