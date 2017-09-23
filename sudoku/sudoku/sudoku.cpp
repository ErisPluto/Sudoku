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

void CreateSet(int i, int *set, int *rec);
void GetSudokus(int num);
int GenerateSudokus(int *initSet, int **row, int **column, int **square, int **sudoku, int num, int iter, int i, int j, char *path);
void InitSudokus();
int* InitSet();
void SolvePuzzles(int **puzzle, char *path);
void FileOutput(char* path, int** sudoku);
void PuzzleInput(char* path);
void print(int **a);
int ToNum(char* n);

int main(int argc, char* args[])
{
	srand((unsigned)(time(NULL)));

	if (argc == 3) {
		if (strcmp(args[1], "-t") == 0) {
			GetSudokus(ToNum(args[2]));
		}
		else if(strcmp(args[1], "-s") == 0)
		{
			PuzzleInput(args[2]);
		}
		else {
			cout << "Please input correct argments" << endl;
		}
	}
	else if (argc == 2 && strcmp(args[1] , "-i") == 0) {
		InitSudokus();
	}
	else {
		cout << "Please input correct argments" << endl;
	}
	getchar();
    return 0;
}

int ToNum(char* n) {
	int i = 0, num = 0;
	for (i = 0; i < strlen(n); i++) {
		num = num * 10 + (n[i] - '0');
	}
	return num;
}

void InitSudokus() {
	int *rec = new int[8], *set = new int[9];
	set[0] = 9;
	memset(rec, 0, sizeof(int) * 9);
	CreateSet(1, set, rec);
	return;
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

int *InitSet(char sign, char *Str) {
	ifstream sFile;
	sFile.open("set.txt");
	int *initSet = new int[9], i = 0,j = 0;
	if (!sFile) {
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
	}
	else {
		if (sign == 's') {
			cout << sign;
			int index = 0;
			do {
				index = (rand() * rand()) % (COUNT / 10);
			} while (setFile[index] != 0);
			setFile[index] = 1;
			cout << index;
			char *str = new char[10];
			while (j <= index) {
				sFile.read(str, 10);
			}
			for (j = 0; j < 9; j++) {
				initSet[j] = str[j] - '0';
			}
			sFile.close();
		}
		else if (sign == 'l') {
			for (j = 0; j < 9; j++) {
				initSet[j] = Str[j] - '0';
			}
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
					//print(sudoku);
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

void CreateSet(int i, int *set, int *rec) {
	int k = 0;
	for (k = 0; k < 8; k++) {
		if (rec[k] != 0) {
			continue;
		}
		set[i] = k + 1;
			rec[k] = 1;
			if (i == 8) {
				ofstream outf;
				outf.open("set.txt", ios::app);
				for (i = 0; i < 9; i++) {
					outf << set[i];
				}
				outf << endl;
				outf.close();
			}
			else {
				CreateSet(i + 1, set, rec);
			}
		rec[k] = 0;
	}
	return;
}

void GetSudokus(int num) {
	ofstream outFile;
	outFile.open("sudoku.txt", ios::out);
	outFile.close();
	int i = 0;
	char sign, str[10];
	int turn = num / COUNT;
	int rest = num - COUNT * turn;
	double t = (double)num / COUNT;
	double r = (double)rest / COUNT;
	ifstream inFile;
	inFile.open("set.txt");
	for (i = 0; i < COUNT; i++) {
		sign = 'l';
		inFile.read(str, 10);
		GenerateSudokus(InitSet(sign, str), CreateArray(), CreateArray(), CreateArray(), CreateArray(), 0, 0, turn, 1, "sudoku.txt");
	}
	if (r < 0.1) {
		sign = 's';
		GenerateSudokus(InitSet(sign, ""), CreateArray(), CreateArray(), CreateArray(), CreateArray(), 0, 0, rest, 1, "sudoku.txt");
	}
	else {
		inFile.seekg(0);
		for (i = 0; i < rest;i++) {
			sign = 'l';
			GenerateSudokus(InitSet(sign, str), CreateArray(), CreateArray(), CreateArray(), CreateArray(), 0, 0, 1, 1, "sudoku.txt");
		}
	}
	inFile.close();
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

void PuzzleInput(char *path) {
	int **puzzle = CreateArray();
	ifstream inFile;
	inFile.open(path);
	ofstream outFile;
	outFile.open("sudoku.txt", ios::out);
	outFile.close();
	char c;
	int i = 0, j = 0;
	while (!inFile.eof()) {
		inFile.read(&c, 1);
		if (c != ' ' && c != '\n') {
			//cout << i << " " << j << endl;
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
	return;
}



