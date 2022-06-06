#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\5.1 c oop\5.1 c oop\Money.cpp"
#include "C:\Users\Misha\source\repos\5.1 c oop\5.1 c oop\Pair.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money a(15, 50);
			double x = 2;
			double res = a.getGrn() * x;
			Assert::AreEqual(30., res);
		}
	};
}
