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
		
		TEST_METHOD(GenerateArg)
		{
			int result = 0;
			char *num1 = "abs", *num2 = "123";
			result = ToNum(num1);
			Assert::AreEqual(result, -1);
			result = ToNum(num2);
			Assert::AreEqual(result, 123);

			
		}
		TEST_METHOD(StopStep)
		{
			N = 10;
			n = 11;
			int result = 0;
			result = Mix(CreateArray(), CreateSet(8), CreateArray());
			Assert::AreEqual(result, -1);
			mode = 'c';
			result = GetSudokus(0, CreateArray(), CreateSet(9), CreateSet(9), CreateSet(9));
			//Assert::AreEqual(result, -2);
			N = 3;
			result = GetSudokus(0, CreateArray(), CreateSet(9), CreateSet(9), CreateSet(9));
			char *args[] = {"a", "-c", "10"};
			int argc = 3;
			main(argc, args);

		}
		TEST_METHOD(SolveArg)
		{
			int result = 0;
			mode = 's';
			result = PuzzleInput("m.txt");
			Assert::AreEqual(result, 0);
			result = PuzzleInput("s.txt");
			Assert::AreEqual(result, -1);
		}

	};
}