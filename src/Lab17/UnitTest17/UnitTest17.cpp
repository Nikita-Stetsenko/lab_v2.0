#include "pch.h"
#include "CppUnitTest.h"

#include "../Calculator.h"
#include "../Calculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest17
{
	TEST_CLASS(UnitTest17)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a = 3, b = 10;
			int res = 30;

			Assert::AreEqual(multiply(a, b), res);
		}
	};
}
