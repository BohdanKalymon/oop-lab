#include "pch.h"
#include "CppUnitTest.h"
#include "../5.1 G oop/Man.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rfhr
{
	TEST_CLASS(rfhr)
	{
		public:

			TEST_METHOD(TestToString)
			{
				Man m;
				m.Init("name", 20, 'm', 50.5);
				Assert::AreEqual("	Name : name\n	Age : 20\n	Gender : m\n	Weight : 50.5", m.toString().c_str());
			}
		};
	}