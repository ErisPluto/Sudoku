// //

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;
using std::string;

#define MAX 32767
#define FIX  9
#define M 256 * 1024 * 1024

char outStr[M];
char inStr[M];
int outN;

int n = 0, N = 0;
char mode = '\0';
string out = "";

int **CreateArray();
int *CreateSet(int num);
void DeleteArray(int **array);
int GetSudokus(int i, int **sudoku, int *row, int *col, int *squa);
int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int i, int j, char *path);
int* InitSet();
int SolvePuzzles(int **puzzle, char *path);
void FileOutput(char* path, int** sudoku);
int PuzzleInput(char* path);
void print(int **a);
int ToNum(char* n);

int main(int argc, char* args[])
{
	srand((unsigned)(time(NULL)));

	if (argc == 3) {
		if (strcmp(args[1], "-c") == 0) {
			mode = 'c';
			N = ToNum(args[2]);
			if (N < 1 || N > 1000000) {
				cout << "Please input correct argments" << endl;
				return 0;
			}
			GetSudokus(0, CreateArray(), CreateSet(9), CreateSet(9), CreateSet(9));
		}
		else if(strcmp(args[1], "-s") == 0)
		{
			mode = 's';
			PuzzleInput(args[2]);
		}
		else {
			cout << "Please input correct argments" << endl;
			return 0;
		}
	}
	else {
		cout << "Please input correct argments" << endl;
		return 0;
	}

	FILE *outFile;
	fopen_s(&outFile ,"sudoku.txt", "w");
	outStr[outN++] = '\0';
	fputs(outStr, outFile);

	fclose(outFile);
    return 0;
}

int ToNum(char* n) {
	int i = 0, num = 0;
	for (i = 0; i < strlen(n); i++) {
		if (n[i] < '0' || n[i] > '9') {
			return -1;
		}
		num = num * 10 + (n[i] - '0');
	}
	return num;
}

int *CreateSet(int num) {
	int *set = new int[num];
	memset(set, 0, sizeof(int) * num);
	return set;
}

int** CreateArray() {
	int **a = NULL;
	a = new int *[9];
	int i = 0, j = 0;
	for (i = 0; i < 9; i++) {
		a[i] = new int[9];
		memset(a[i], 0, sizeof(int) * 9);
	}

	return a;
}

void DeleteArray(int **a) {
	int i = 0;
	for (i = 0; i < 9; i++) {
		delete[] a[i];
	}
	delete a;
	return;
}

void print(int **a) {
	int i = 0, j = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (j == 8) {
				cout << a[i][j] << endl;
			}
			else {
				cout << a[i][j] << " ";
			}
		}
	}
	cout << endl;
	return;
}

int *InitSet() {
	int *initSet = new int[9], i = 0,  set[8] = { 0 }, a = 0;;
	switch (mode)
	{
	case 'c':
		initSet[8] = 9;
		for (i = 0; i < 8; i++) {
			a = rand() % 8 + 1;
			if (set[a - 1] == 0) {
				initSet[i] = a;
				set[a - 1] = 1;
			}
			else {
				i--;
			}
		}
		break;
	case 's':
		for (i = 0; i < 9; i++) {
			initSet[i] = i + 1;
		}
		break;
	default:
		break;
	}
	for (i = 0; i < 9; i++) {
		//cout << initSet[i];
	}
	return initSet;
}

int **CopyArray(int **ori) {
	int i = 0, j = 0, **copy = CreateArray();
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			copy[i][j] = ori[i][j];
		}
	}
	return copy;
}

int GetSudokus(int i, int **sudoku, int *row, int *col, int *squa) {
	int t = 0, j =  0, sign = 0;
	for (j = 0; j < 9; j++) {
		t = i / 3 * 3 + j / 3;
		if (row[i] != 0 || col[j] != 0 || squa[t] != 0) {
			continue;
		}
		sudoku[i][j] = FIX;
		row[i] = col[j] = squa[t] = 1;
		if (i == 8) {
			sign = SolvePuzzles(CopyArray(sudoku), "sudoku.txt");
		}
		else {
			 sign = GetSudokus(i + 1, sudoku, row, col, squa);
		}
		if (sign == -1) {
			return sign;
		}
		sudoku[i][j] = row[i] = col[j] = squa[t] = 0;
	}
	return sign;
}

int Mix(int **puzzle, int *minSet, int **out) {
	int i = 0, j = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (puzzle[i][j] == 9) {
				out[i][j] = puzzle[i][j];
			}
			else {
				out[i][j] = minSet[puzzle[i][j]-1];
			}
		}
	}
	n++;
	FileOutput("sudoku.txt", out);
	if (n >= N) {
		DeleteArray(out);
		return -1;
	}
	return 0;
}

int MixSet(int *mixSet, int i, int *set, int **puzzle, int **out) {
	int j = 0, sign = 0;
	for (j = 0; j < 8; j++) {
		if (set[j] != 0) {
			continue;
		}
		mixSet[i] = j + 1;
		set[j] = 1;
		if (i == 7) {
			sign = Mix(puzzle, mixSet, out);
		}
		else {
			sign = MixSet(mixSet, i + 1, set, puzzle, out);
		}
		if (sign == -1)
			return sign;
		set[j] = 0;
	}
	return sign;
}

int SolvePuzzles(int **puzzle, char *path) {
	int **row = CreateArray(), **column = CreateArray(), **square = CreateArray();
	int i = 0, j = 0, t = 0;
	int *initSet = InitSet();
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			t = i / 3 * 3 + j / 3;
			if (puzzle[i][j] != 0) {
				row[i][puzzle[i][j] - 1] = 2;
				column[j][puzzle[i][j] - 1] = 2;
				square[t][puzzle[i][j] - 1] = 2;
			}
		}
	}
	int sign = GenerateSudokus(initSet, row, column, square, puzzle, 0, 0, path);
	DeleteArray(row);
	DeleteArray(column);
	DeleteArray(square);
	return sign;
}

int ToNext(int *initSet, int **row, int **column, int** square, int **sudoku, int i, int j, char *path) {
	int sign = 0;
	if (j == 8) {
		if (i == 8) {
			if (mode == 'c') {
				sign = MixSet(CreateSet(8), 0, CreateSet(8), sudoku, CreateArray());
			}
			else {
				FileOutput(path, sudoku);
				sign = -2;
			}
			if (sign == 0)
				return -2;
		}
		else {
			sign = GenerateSudokus(initSet, row, column, square, sudoku, i + 1, 0, path);
		}
	}
	else {
		sign = GenerateSudokus(initSet, row, column, square, sudoku, i, j + 1, path);
	}
	return sign;
}

int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int i, int j, char *path) {
	int sign = 0;
	if (sudoku[i][j] != 0) {
		sign = ToNext(initSet, row, column, square, sudoku, i, j, path);
	}
	else {
		int k = 0, t = i / 3 * 3 + j / 3;
		int l = 0;
		for (k = 0; k < 9; k++) {
			l = initSet[k];
			if (row[i][k] != 0 || column[j][k] != 0 || square[t][k] != 0) {
				continue;
			}
			else {
				sudoku[i][j] = l;
				row[i][k] = column[j][k] = square[t][k] = 1;
				sign = ToNext(initSet, row, column, square, sudoku, i, j, path);
				if(sign != 0)
					return sign;
			}
			row[i][k] = (row[i][k] == 2) ? 2 : 0;
			column[j][k] = (column[j][k] == 2) ? 2 : 0;
			square[t][k] = (square[t][k] == 2) ? 2 : 0;
			sudoku[i][j] = 0;
		}
	}
	return sign;
}

void FileOutput(char* path, int** sudoku) {

	int i = 0, j = 0, k = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			char c = sudoku[i][j] + '0';

			outStr[outN++] = c;
			if (j == 8) {

				outStr[outN++] = '\n';
			}
			else {

				outStr[outN++] = ' ';
			}
		}
	}
	outStr[outN++] = '\n';
	return;
}

int PuzzleInput(char *path) {
	ifstream inFile;
	inFile.open(path);
	if (!inFile) {
		cout << "Please input correct argments" << endl;
		return -1;
	}
	int **puzzle = CreateArray();
	stringstream in;
	in << inFile.rdbuf();
	string inStr = in.str();
	char c;
	int i = 0, j = 0, k = 0;
	while (k < inStr.length()) {
		c = inStr[k];
		if (c != ' ' && c != '\n') {
			puzzle[i][j] = c - '0';
			if (j == 8) {
				if (i == 8) {
					SolvePuzzles(puzzle, "sudoku.txt");
					i = 0;
					j = 0;
				}
				else {
					i++;
					j = 0;
				}
			}
			else {
				j++;
			}
		}
		k++;
	}
	inFile.close();
	return 0;
}



