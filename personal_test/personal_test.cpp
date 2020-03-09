#include "pch.h"
#include "CppUnitTest.h"
#include "../src/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Line* l = new Line(0, 0, 2, 1);
			Line* l2 = new Line(0, 1, 2, 0);
		}
	};

}
