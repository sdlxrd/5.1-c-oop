#include "PrMoney.h"
#include <string>
#include <sstream>

using namespace std;

PrMoney::PrMoney(const long x, const unsigned long y)
{
	if (x < 0 || y < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0");
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
PrMoney::PrMoney(double z)
{
	if (z < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = (long)z;
		z -= a;
		z *= 100;
		unsigned long b = (unsigned long)z;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		setGrn(a);
		setKop(b);
	}
}

PrMoney::PrMoney(const PrMoney& x)
{
	long a = x.getGrn();
	long b = x.getKop();

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
PrMoney::~PrMoney(void)
{}
PrMoney operator -(const PrMoney& first, const PrMoney& second)
{
	PrMoney t;

	if (first.getGrn() < second.getGrn())
	{
		long a = 0;
		unsigned	long b = 0;
		t.setGrn(a);
		t.setKop(b);
	}
	else
		if ((first.getGrn() > second.getGrn()) && (first.getKop() < second.getKop()))
		{
			long a = (first.getGrn() - 1) - second.getGrn();
			unsigned long b = (100 - (second.getKop() - first.getKop()));
			t.setGrn(a);
			t.setKop(b);
		}
		else
			if ((first.getGrn() > second.getGrn()) && ((first.getKop() > second.getKop())))
			{
				long a = (first.getGrn() - second.getGrn());
				unsigned long b = (first.getKop() - second.getKop());
				t.setGrn(a);
				t.setKop(b);
			}

	return t;
}
PrMoney operator *(const PrMoney& x, const double y)
{
	PrMoney t;
	double a = (x.getGrn() * y);
	double b = (x.getKop() * y);

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	
	t.setGrn(a);
	t.setKop(b);
	
	return t;
}
string format(unsigned long b)
{
	stringstream ss;

	if (b < 10)
	{
		ss << "0";
	}

	ss << b;

	return ss.str();
}
PrMoney::operator string() const
{
	stringstream ss;
	ss << getGrn() << ", " << format(getKop());

	return ss.str();
}
ostream& operator << (ostream& out, const PrMoney& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, PrMoney& x)
{
	long a;
	unsigned long b;
	cout << "Grn = "; in >> a;
	cout << "Kop = "; in >> b;

	x.setGrn(a);
	x.setKop(b);
	return in;

}

bool PrMoney::operator ==(const PrMoney& x)
{
	return(this->getGrn() == x.getGrn() && this->getKop() == x.getKop());
}
bool PrMoney::operator > (const PrMoney& x)
{
	return  ((this->getGrn() > x.getGrn()) or ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop())));
}
bool PrMoney::operator < (const PrMoney& x)
{
	return ((this->getGrn() < x.getGrn()) or ((this->getGrn() == x.getGrn()) && (this->getKop() < x.getKop())));
}
PrMoney& PrMoney::operator ++()
{
	int a = this->getGrn();
	int b = this->getKop();

	a++;
	b++;
	this->setGrn(a);
	this->setKop(b);
	return *this;
}
PrMoney& PrMoney::operator --()
{
	int a = this->getGrn();
	int b = this->getKop();

	a--;
	b--;
	this->setGrn(a);
	this->setKop(b);
	return *this;
}
PrMoney PrMoney::operator ++(int)
{
	PrMoney t(*this);

	int a = this->getGrn();
	int b = this->getKop();

	a++;
	b++;

	this->setGrn(a);
	this->setKop(b);

	return t;
}
PrMoney PrMoney::operator --(int)
{
	PrMoney t(*this);

	int a = this->getGrn();
	int b = this->getKop();

	a--;
	b--;

	this->setGrn(a);
	this->setKop(b);

	return t;
}