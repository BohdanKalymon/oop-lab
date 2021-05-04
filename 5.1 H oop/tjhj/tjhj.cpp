#include "pch.h"
#include "CppUnitTest.h"
#include "../5.1 H oop/DigitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tjhj
{
	TEST_CLASS(tjhj)
	{
	public:

		TEST_METHOD(TestToString)
		{
			DigitString ds;
			ds.Init("10");
			Assert::AreEqual("10", ds.toString().c_str());
		}
	};
}