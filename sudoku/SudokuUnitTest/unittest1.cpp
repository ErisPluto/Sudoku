#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/stdafx.h"
#include "../sudoku/sudoku.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int result = 0;
			result = PuzzleInput("s.txt");
			Assert::AreEqual(result, -1);
			
		}

	};
}