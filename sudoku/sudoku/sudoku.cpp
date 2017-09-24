// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#define MAX 32767
#define COUNT 40320
int setFile[4032];

void GetSudokus(int num);
int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int num, int iter, int i, int j, char *path);
int* InitSet();
void SolvePuzzles(int **puzzle, char *path);
void FileOutput(char* path, int** sudoku);
int PuzzleInput(char* path);
void print(int **a);
int ToNum(char* n);

int main(int argc, char* args[])
{
	srand((unsigned)(time(NULL)));
	int num;
	if (argc == 3) {
		if (strcmp(args[1], "-c") == 0) {
			num = ToNum(args[2]);
			if (num < 1 || num > 1000000) {
				cout << "Please input correct argments" << endl;
				return 0;
			}
			GetSudokus(num);
		}
		else if(strcmp(args[1], "-s") == 0)
		{
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
	
	int *initSet = new int[9], i = 0,j = 0;
		int set[8] = { 0 };
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

void SolvePuzzles(int **puzzle, char *path) {
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

	GenerateSudokus(initSet, row, column, square, puzzle, 0, 0, 1, 1, path);
	DeleteArray(row);
	DeleteArray(column);
	DeleteArray(square);
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

int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int i, int j, int num, int iter, char *path) {
	if (iter > num)
		return iter;
	int k = 0, t = i / 3 * 3 + j / 3;
	int l = 0;
	for (k = 0; k < 9; k++) {
		if (sudoku[i][j] != 0) {
			if (j == 8) {
				if (i == 8) {
					FileOutput("sudoku.txt", sudoku);
					iter++;
					return iter;
				}
				else {
					iter = GenerateSudokus(initSet, row, column, square, sudoku, i + 1, 0, num, iter, path);
				}
			}
			else {
				iter = GenerateSudokus(initSet, row, column, square, sudoku, i, j + 1, num, iter, path);
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
					FileOutput(path,sudoku);
					iter++;
				}
				else {
					iter = GenerateSudokus(initSet, row, column, square, sudoku, i + 1, 0, num, iter, path);
				}
			}
			else {
				iter = GenerateSudokus(initSet, row, column, square, sudoku, i, j + 1, num, iter, path);
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
	ofstream outFile;
	outFile.open("sudoku.txt", ios::out);
	outFile.close();
		GenerateSudokus(InitSet(), CreateArray(), CreateArray(), CreateArray(), CreateArray(), 0, 0, num, 1, "sudoku.txt");

	return;
}

void FileOutput(char* path, int** sudoku) {
	//ofstream outputFile;
	//outputFile.open(path, ios::app);
	FILE* outputFile;
	freopen_s(&outputFile,path, "a",stdout);
	char *c = new char[256];
	memset(c, 0, sizeof(char) * 256);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			c[k++] = sudoku[i][j] + '0';
			if (j == 8) {
				c[k++] = '\n';
			}
			else {
				//outputFile << sudoku[i][j] << " " ;
				c[k++]= ' ';
			}
		}
	}
	c[k++] = '\n';
	puts(c);
	fclose(outputFile);
	delete c;
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
	ofstream outFile;
	outFile.open("sudoku.txt", ios::out);
	outFile.close();
	char c;
	int i = 0, j = 0;
	while (!inFile.eof()) {
		inFile.read(&c, 1);
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
	}
	inFile.close();
	return 0;
}



