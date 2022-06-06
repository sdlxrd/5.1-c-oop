#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Exception.h"
#include "nException.h"

using namespace std;

class Pair
{
private:
	long grn;
	unsigned long kop;
public:
	Pair(const long f = 0, const unsigned long s = 0);
	Pair(const Pair&);
	~Pair(void) {}
	
	long getGrn() const { return grn; }
	unsigned long getKop() const { return kop; }
	
	void setGrn(long value);
	void setKop(unsigned long value);

	operator string() const;
	
	friend ostream& operator <<(ostream&, const Pair&);
	friend istream& operator >>(istream&, Pair&);
};

