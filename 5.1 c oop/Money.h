#pragma once
#include "Pair.h"
class Money :
    public Pair
{
public:
	Money(const long x = 0,const unsigned long s = 0);
	Money(const Money&);
	Money(double x);
	~Money(void) {}

	friend	Money operator -(const Money&, const Money&);
	friend	Money operator *(const Money&, const double);
	
	bool operator ==(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	
	operator string() const;
	
	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};

