#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception: public exception
{
private:
	string message;
public:
	Exception(string message) : message(message) {}
	string getMessage() { return message; }
};

