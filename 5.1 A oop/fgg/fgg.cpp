#include "pch.h"
#include "CppUnitTest.h"
#include "../5.1 A oop/Goods.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fgg
{
	TEST_CLASS(fgg)
	{
	public:

		TEST_METHOD(TestCost)
		{
			double first = 10.02;
			int second = 1;
			Goods g;
			g.Init(first, second);
			Assert::AreEqual(10.02, g.cost(), 0.01);
		}
	};
}