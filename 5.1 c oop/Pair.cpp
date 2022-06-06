#include "Pair.h"
#define debug
using namespace std;

void Pair::setGrn(long value)
{
	if (value < 0)
		throw Exception("\nGrn must be > 0\n");

	else
		grn = value;
}
void Pair::setKop(unsigned long value)
{
	if (value < 0)
		throw Exception("\nKop must be > 0\n");
	
	else
		kop = value;
	
}
Pair::Pair(const long x, const unsigned long y) : grn(x), kop(y)
{ }

Pair::Pair(const Pair& x)
{
	grn = x.grn;
	kop = x.kop;
}

Pair::operator string() const
{
	stringstream ss;
	ss << grn << ". " << kop;
	return ss.str();
}
ostream& operator << (ostream& out, const Pair& x)
{
	
	return out << (string)x;
}
istream& operator >> (istream& in, Pair& r)
{
	long hrn;
	unsigned long kop;

	cout << "a = "; in >> hrn;
	cout << "b = "; in >> kop;

	if (hrn < 0 || kop < 0)
	{
		throw nException("Grn and Kop must be > 0");
	}
	else
	{
		r.setGrn(hrn);
		r.setKop(kop);
	}

	return in;
}