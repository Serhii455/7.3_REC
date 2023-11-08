#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_7.3_REC/7.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 2;
			const int colCount = 2;

			int** A = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				A[i] = new int[colCount];

			int g = FindZeroRow(A, 2, 2);


			Assert::AreEqual(g, 0);


			for (int i = 0; i < rowCount; i++)
				delete[] A[i];
			delete[] A;

		}
	};
}
