#include "pch.h"
#include "CppUnitTest.h"
#include "../2.7 oop/DigitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	
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