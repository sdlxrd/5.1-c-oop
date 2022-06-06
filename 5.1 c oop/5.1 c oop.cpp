#include <iostream>

#include "Money.h"
#include "PrMoney.h"

using namespace std;

int main()
{
	Money a(0,0), b(0, 0);
	double x;
	PrMoney a1(0, 0), b1(0, 0);
	double x1;
	
	bool res;
	do
	{
		try
		{
			res = true;
			cout << "public: " << endl;
			cout << "Enter the first value: " << endl; cin >> a;
			cout << "\nEnter the second value: " << endl; cin >> b;
			cout << "\nEnter the value of x: ";cin >> x;

			cout << endl;

			cout << "private: " << endl;
			cout << "Enter the first value: " << endl; cin >> a1;
			cout << "\nEnter the second value: " << endl; cin >> b1;
			cout << "\nEnter the value of x: ";cin >> x1;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << endl << ex.what() << endl << endl;
		}
		catch (nException& ex)
		{
			res = false;
			cout << endl << ex.getMessage() << endl << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cout << endl << ex->getMessage() << endl << endl;
		}
	} while (!res);
	

	system("cls");

	cout << "public: " << endl;
	cout << "First sum = " << a << "\tSecond sum = " << b << "\tX = " << x << endl;
	cout << endl << "first - second: " << a - b << endl;
	cout << "\nfirst * x: " << a * x << endl;
	cout << "second * x: " << b * x << endl;

	if (a == b)
	{
		cout << a << " == " << b << endl;
	}
	else
		if (a > b)
		{
			cout << a << " > " << b << endl;
		}
		else
			if (a < b)
			{
				cout << a << " < " << b << endl;
			}
	cout << endl;
	cout << "a++ " << a++;
	cout << "\nresult: " << a << endl;
	cout << "\na-- " << a--;
	cout << "\nresult: " << a << endl;

	cout << "\n++a " << ++a << endl;
	cout << "--a " << --a << endl;

	cout << endl;

	cout << "private: " << endl;
	cout << "First sum = " << a1 << "\tSecond sum = " << b1 << "\tX = " << x1 << endl;

	PrMoney t(a1 - b1);
	PrMoney t1(a1 * x1);
	PrMoney t2(b1 * x1);

	cout << "\nfirst - second = " << t << endl;
	cout << "\nfirst * x = " << t1 << endl;
	cout << "second * x = " << t2 << endl;

	cout << endl;

	if (a1 == b1)
	{
		cout << a1 << " == " << b1 << endl;
	}
	else

		if (a1 > b1)
		{
			cout << a1 << " > " << b1 << endl;
		}
		else
			if (a1 < b1)
			{
				cout << a1 << " < " << b1 << endl;
			}
	cout << endl;
	cout << "a++ " << a1++;
	cout << "\nresult: " << a1 << endl;
	cout << "\na-- " << a1--;
	cout << "\nresult: " << a1 << endl;

	cout << "\n++a " << ++a1 << endl;
	cout << "--a " << --a1 << endl;
	
	cout << endl;
	system("pause");
 }