#include "pch.h"
#include "CppUnitTest.h"
#include "../4.4 oop/Equilateral.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My44f
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestPerimeter)
		{
			Equilateral e(10, 10, 60);
			Assert::AreEqual(30., e.Perimeter(), 0.1);
		}
	};
}
