#pragma once
#include "Pair.h"
class PrMoney :
    private Pair
{
public:
	PrMoney(const long x = 0, const unsigned long y = 0);
	PrMoney(const PrMoney&);
	PrMoney(double x);
	~PrMoney(void);
	
	using Pair::getGrn;
	using Pair::getKop;
	using Pair::setGrn;
	using Pair::setKop;

	friend PrMoney operator -(const PrMoney&, const PrMoney&);
	friend PrMoney operator *(const PrMoney&, const double);
	
	bool operator ==(const PrMoney&);
	bool operator >(const PrMoney&);
	bool operator <(const PrMoney&);
	
	operator string() const;
	friend ostream& operator <<(ostream&, const PrMoney&);
	friend istream& operator >>(istream&, PrMoney&);
	
	PrMoney& operator++();
	PrMoney& operator--();
	PrMoney operator++(int);
	PrMoney operator--(int);
};

