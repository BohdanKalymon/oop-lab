#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1 oop/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::array<int, 10> b{ {2, 5, 21, 0, 1, 0, 1, 0, 0, 0} };
			double avg = avg_even(b);
			Assert::AreEqual(avg, 5.);
		}
	};
}