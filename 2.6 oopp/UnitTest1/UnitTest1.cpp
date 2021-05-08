#include "pch.h"
#include "CppUnitTest.h"
#include "../2.6 oopp/Student.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	

	{
	public:

		TEST_METHOD(TestToString)
		{
			Student::Man m;
			m.Init("name", 20, 'm', 50.5);
			Assert::AreEqual("	Name : name\n	Age : 20\n	Gender : m\n	Weight : 50.5", m.toString().c_str());
		}
	};
}

	