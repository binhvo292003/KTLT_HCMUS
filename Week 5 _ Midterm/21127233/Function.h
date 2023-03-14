#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>

using namespace std;

struct Matrix
{
	double* data;
	int nRow, nCol;
};

struct Options
{
	int min, max, decimals;
};

double GenerateDecimal(const Options& opt);
void InputOptions(Options& opt);
void OutputOptions(Options& opt);
Matrix* CreateMatrix(const int& nRow, const int& nCol);
void GenerateMatrix(Matrix* m, const Options& opt);
void PrintMatrix(Matrix* m);
double* MaxElement(Matrix* m, int& iRow, int& iCol);
Matrix* CreateMatrixB(Matrix* m);
void FreeMatrix(Matrix* m);
void PrintMatrix(Matrix* m, string path);


#endif // !FUNCTION_H
