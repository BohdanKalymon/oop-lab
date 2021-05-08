#include "pch.h"
#include "CppUnitTest.h"
#include "../1.4/Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestToString)
		{
			Complex c;
			c.Init(2, 1);
			Assert::AreEqual("2 + i * 1", c.toString().c_str());
		}
	};
}