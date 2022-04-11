#include "pch.h"
#include "CppUnitTest.h"
#include "../PR3.1A/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT31A
{
	TEST_CLASS(UT31A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			int N = 4;
			Student* s = new Student[N];

			s[0].math = 5;
			s[0].physics = 5;
			s[1].math = 4;
			s[1].physics = 4;
			s[2].math = 3;
			s[2].physics = 4;
			s[3].math = 2;
			s[3].physics = 5;

			t = LineSearch(s, N);

			Assert::AreEqual(t, 50.0);
		}
	};
}