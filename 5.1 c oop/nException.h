#pragma once
#include <iostream>
#include <string>

using namespace std;
class nException
{
private:
	string message;
public:
	nException(string messge) : message(message) { }
	string getMessage() { return message; }
};

