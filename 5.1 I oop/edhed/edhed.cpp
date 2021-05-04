#include "pch.h"
#include "CppUnitTest.h"
#include "../5.1 I oop/DigitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace edhed
{
	TEST_CLASS(edhed)
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