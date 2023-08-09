#include "Date.h"

void TestDate1()
{
	Date d1;
	Date d2(2023, 10, 1);
	Date d3;
	d1.Print();
	d2.Print();

	cout << (d1 == d3) << endl;
	cout << (d1 == d2) << endl;
	cout << endl;

	cout << (d1 != d3) << endl;
	cout << (d1 > d2) << endl;
	cout << endl;

	(d1 + 100).Print();
	Date d4 = d1 - 100;
	d4.Print();
	d4 -= 100;
	d4.Print();
	cout << endl;

	cin >> d4;
	cout << d4;
}

int main()
{
	TestDate1();

	return 0;
}