// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#define MAX 32767

void GetSudokus(int num);
int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int num, int iter, int i, int j);
int** CreateSudokus(char *sudokuString);
void InitSudokus();
int* InitSet();
void SolvePuzzles(int **puzzle);
void FileOutput(char* path, int** sudoku);
void FileInput(char* path);
void print(int **a);

int main(int argc, char* args[])
{
	//GetSudokus(20);
	FileInput("a.txt");
	/*char *path, *n;
	int num = 0, i = 0;
	srand((unsigned)(time(NULL)));
	if (argc == 2) {
		if (strcmp(args[1], "-t") == 0) {
			n = args[2];
			for (i = 0; i < strlen(n); i++) {
				num = num * 10 + (n[i] - '0');
			}
			GetSudokus(num);
		}
		else if(strcmp(args[1], "-s") == 0)
		{
			SolvePuzzles(args[2]);
		}
		else {
			cout << "Please input correct argments" << endl;
		}
	}
	else {
		cout << "Please input correct argments" << endl;
	}*/
	
	getchar();
    return 0;
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

int *InitSet() {
	int *initSet = new int[9];
	int i = 0, set[8] = {0};
	double t = 0;
	int a = 0;
	initSet[0] = 9;
	for (i = 1; i < 9; i++) {
		a = rand() % 8 + 1;
		if (set[a - 1] == 0) {
			initSet[i] = a;
			set[a - 1] = 1;
		}
		else {
			i--;
		}
	}
	return initSet;
}

void SolvePuzzles(int **puzzle) {
	int **row = CreateArray(), **column = CreateArray(), **square = CreateArray();
	int i = 0, j = 0, t = 0;
	int *initSet = new int[9];
	for (i = 0; i < 9; i++) {
		initSet[i] = i + 1;
	}
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

	GenerateSudokus(initSet, row, column, square, puzzle, 0, 0, 1, 1);
	DeleteArray(row);
	DeleteArray(column);
	DeleteArray(square);
	//DeleteArray(puzzle);
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
int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int i, int j, int num, int iter) {
	//cout << "SolvePuzzles";
	if (iter > num)
		return iter;
	int k = 0, t = i / 3 * 3 + j / 3;
	int l = 0;
	for (k = 0; k < 9; k++) {
		if (sudoku[i][j] != 0) {
			if (j == 8) {
				if (i == 8) {
					FileOutput("sudoku.txt", sudoku);
					//print(sudoku);
					iter++;
					return iter;
				}
				else {
					iter = GenerateSudokus(initSet, row, column, square, sudoku, i + 1, 0, num, iter);
				}
			}
			else {
				iter = GenerateSudokus(initSet, row, column, square, sudoku, i, j + 1, num, iter);
			}
		}
		l = initSet[k];
		if (row[i][k] != 0 || column[j][k] != 0 || square[t][k] != 0) {
			continue;
		}
		else {
			sudoku[i][j] = l;
			row[i][k] = 1;
			column[j][k] = 1;
			square[t][k] = 1;
			if (j == 8) {
				if (i == 8) {
					FileOutput("sudoku.txt",sudoku);
					//print(sudoku);
					iter++;
				}
				else {
					iter = GenerateSudokus(initSet, row, column, square, sudoku, i + 1, 0, num, iter);
				}
			}
			else {
				iter = GenerateSudokus(initSet, row, column, square, sudoku, i, j + 1, num, iter);
			}
		}
		if(row[i][k] == 2){
			return iter;
		}
		row[i][k] = 0;
		column[j][k] = 0;
		square[t][k] = 0;
		sudoku[i][j] = 0;
	}
	return iter;
}

void GetSudokus(int num) {
	fstream _file;
	_file.open ("AllSudokus.txt", ios::in);

	int i = 0;
	if (!_file)
	{
		for (i = 0; i < num; i++) {
			GenerateSudokus(InitSet(), CreateArray(), CreateArray(), CreateArray(), CreateArray(), 0, 0, 1, 1);
		}
	}
	else
	{
		//CreateSudokus();
	}
	return;

}

void FileOutput(char* path, int** sudoku) {
	ofstream outputFile;
	outputFile.open(path, ios::app);
	int i = 0, j = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (j == 8) {
				outputFile << sudoku[i][j] << "\n" ;
			}
			else {
				outputFile << sudoku[i][j] << " " ;
			}
		}
	}
	outputFile << endl;
	return;
}

void FileInput(char *path) {
	int **puzzle = CreateArray();
	ifstream inFile;
	inFile.open(path);
	
	char c;
	int i = 0, j = 0;
	while (!inFile.eof()) {
		inFile.read(&c, 1);
		if (c != ' ' && c != '\n') {
			//cout << i << " " << j << endl;
			puzzle[i][j] = c - '0';
			if (j == 8) {
				if (i == 8) {
					SolvePuzzles(puzzle);
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
	}
	inFile.close();
	return;
}



