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
			Line* line1 = new Line(2, 3, 3, 6);
			Assert::AreEqual(line1->line2str(), (string)"3*x+-1*y+-3=0");
		}
		TEST_METHOD(TestMethod2)
		{
			Line* line1 = new Line(0, 0, 0, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Line* line3 = new Line(0, 0, 1, 1);
			Line* line4 = new Line(0, 1, 1, 1);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			container.getNewCross(line4);
			Assert::AreEqual(3, container.getCrossNum());

		}
		TEST_METHOD(TestMethod3)
		{
			Line* line1 = new Line(-10, -9, -9, 10);
			Line* line2 = new Line(-9, 10, 10, 9);
			Line* line3 = new Line(10, 9, 9, -10);
			Line* line4 = new Line(9, -10, -10, -9);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			container.getNewCross(line4);
			Assert::AreEqual(4, container.getCrossNum());
		}
		TEST_METHOD(TestMethod4)
		{
			Line* line1 = new Line(-100, -99, -99, 100);
			Line* line2 = new Line(-99, 100, 100, 99);
			Line* line3 = new Line(100, 99, 99, -100);
			Line* line4 = new Line(90, -100, -100, -99);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			container.getNewCross(line4);
			Assert::AreEqual(5, container.getCrossNum());
		}
		TEST_METHOD(TestMethod5)
		{
			Line* line1 = new Line(101, -914, -159, -304);
			Line* line2 = new Line(-568, 819, -863, 694);
			Line* line3 = new Line(-627, -807, -627, 815);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			Assert::AreEqual(1, container.getCrossNum());
		}
		TEST_METHOD(TestMethod6)
		{
			Line* line1 = new Line(-99999, 0, 99999, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Line* line3 = new Line(-99998, 0, -99998, 1);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			Assert::AreEqual(3, container.getCrossNum());
		}
		TEST_METHOD(TestMethod7)
		{
			Line* line1 = new Line(-99999, 0, 99999, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Assert::IsFalse(parallel(*line1, *line2));
		}
		TEST_METHOD(TestMethod8)
		{
			Line* line1 = new Line(0, 0, 99998, 2);
			Line* line2 = new Line(0, 2, 49999, 3);
			Assert::IsTrue(parallel(*line1, *line2));
		}
		TEST_METHOD(TestMethod9)
		{
			Line* line1 = new Line(0, 0, 99998, 2);
			Line* line2 = new Line(0, 2, 49999, 3);
			Line* line3 = new Line(0, 0, -99999, 0);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			Assert::AreEqual(2, container.getCrossNum());
		}
		TEST_METHOD(TestMethod10) {
			Line* line1 = new Line(0, 0, 1, 1);
			Line* line2 = new Line(1, 0, 0, 1);
			Line* line3 = new Line(1, 2, 2, 0);
			Line* line4 = new Line(0, 3, 1, 2);
			Line* line5 = new Line(0, 1, 2, 2);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			container.getNewCross(line4);
			container.getNewCross(line5);
			Assert::AreEqual(9, container.getCrossNum());
		}
		TEST_METHOD(TestMethod11) {
			Line* line1 = new Line(0, 0, 0, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Line* line3 = new Line(0, 0, 1, 1);
			Line* line4 = new Line(0, 1, 1, 1);
			Container container;
			container.getNewCross(line1);
			container.getNewCross(line2);
			container.getNewCross(line3);
			container.getNewCross(line4);
			Assert::AreEqual(3, container.getCrossNum());
		}
	};

}
