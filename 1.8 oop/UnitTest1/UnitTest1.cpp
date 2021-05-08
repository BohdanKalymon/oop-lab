#include "pch.h"
#include "CppUnitTest.h"
#include "../1.8 oop/Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestToString)
		{
			Fraction f;
			f.Init("10", 2);
			Assert::AreEqual("10.2", f.toString().c_str());
			//Assert::AreEqual((unsigned int)2, f.GetFrac());
		}
	};
}