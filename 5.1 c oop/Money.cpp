#include "Money.h"
#include <string>
#include <sstream>

using namespace std;

Money::Money(const long x, const unsigned long y)
{
	if (x < 0 || y < 0)
	{
		throw invalid_argument("values must be bigger than 0");
	}
	else
	{
		long a = x;
		unsigned long b = y;
		
		while (b > 99)
		{
			b -= 100;
			a++;
		}
		setGrn(a);
		setKop(b);
	}
}
Money::Money(double x)
{
	if (x < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0");
	}
	else
	{
		long a = (long)x;
		x -= a;
		x *= 100;
		unsigned long b = (unsigned long)x;

		while (b > 99)
		{
			b -= 100;
			a++;
		}
	
		setGrn(a);
		setKop(b);
	}
}
Money::Money(const Money& x)
{
	int a = x.getGrn();
	int b = x.getKop();
	
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money operator -(const Money& first, const Money& second)
{
	long a;
	unsigned long b;
	Money t;
	if (first.getGrn() < second.getGrn())
	{
		a = 0;
		b = 0;
	}
	if ((first.getGrn() > second.getGrn()) && (first.getKop() < second.getKop()))
	{
		a = (first.getGrn() - 1) - second.getGrn();
		b = (100 - (second.getKop() - first.getKop()));
	}
	else
	{
		a = (first.getGrn() - second.getGrn());
		b = (first.getKop() - second.getKop());
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}
Money operator *(const Money& value, const double n)
{
	Money t;
	long a = (value.getGrn() * n);
	unsigned long b = (value.getKop() * n);
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}

bool Money::operator ==(const Money& x)
{
	return(this->getGrn() == x.getGrn() && this->getKop() == x.getKop());
}
bool Money::operator > (const Money& x)
{
	return  ((this->getGrn() > x.getGrn()) || ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop())));
}
bool Money::operator < (const Money& x)
{
	return ((this->getGrn() < x.getGrn()) || ((this->getGrn() == x.getGrn()) && (this->getKop() < x.getKop())));
}
Money& Money::operator ++()
{
	long a = this->getGrn();
	unsigned long b = this->getKop();

	a++;
	b++;

	this->setGrn(a);
	this->setKop(b);

	return *this;
}
Money& Money::operator --()
{
	long a = this->getGrn();
	unsigned long b = this->getKop();

	a--;
	b--;

	this->setGrn(a);
	this->setKop(b);

	return *this;

}
Money Money::operator ++(int)
{
	Money t(*this);

	long a = this->getGrn();
	unsigned long b = this->getKop();

	a++;
	b++;

	this->setGrn(a);
	this->setKop(b);

	return t;
}
Money Money::operator --(int)
{
	Money t(*this);

	long a = this->getGrn();
	unsigned long b = this->getKop();

	a--;
	b--;

	this->setGrn(a);
	this->setKop(b);

	return t;
}