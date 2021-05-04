#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2 oop/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fghgh
{
	TEST_CLASS(fghgh)
	{
	public:

		TEST_METHOD(TestDisc)
		{
			Assert::AreEqual(1., disc(1, 3, 2), 0.1);
		}
	};
}