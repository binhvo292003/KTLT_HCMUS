#include "Function.h"


void InputOptions(Options& opt) {
	cout << "\nmin: "; cin >> opt.min;
	cout << "max: "; cin >> opt.max;
	cout << "decimals: "; cin >> opt.decimals;
}

void OutputOptions(Options& opt) {
	cout << "\nmin: " << opt.min << endl;
	cout << "max: " << opt.max << endl;
	cout << "decimals: " << opt.decimals << endl;
}

double GenerateDecimal(const Options& opt) {
	double res = 0;
	int randInt = rand() % (opt.max - opt.min);

	int numDec = pow(10, (opt.decimals));
	int rand100 = rand() % numDec;

	res = opt.min + randInt + ((double)rand100) / numDec;
	return res;
}

Matrix* CreateMatrix(const int& nRow, const int& nCol) {
	/*double* data;
	int nRow, nCol;*/

	Matrix* matrix = new Matrix[nRow];
	for (int i = 0; i < nRow; i++) {
		matrix[i].data = new double[nCol];
	}
	matrix->nRow = nRow;
	matrix->nCol = nCol;

	return matrix;
}

void GenerateMatrix(Matrix* m, const Options& opt) {
	for (int i = 0; i < m->nRow; i++) {
		for (int j = 0; j < m->nCol; j++) {
			m[i].data[j] = GenerateDecimal(opt);
		}
	}
}

void PrintMatrix(Matrix* m) {
	for (int i = 0; i < m->nRow; i++) {
		if (i == 0) {
			cout << "{ ";
		}
		else {
			cout << "  ";
		}
		for (int j = 0; j < m->nCol; j++) {
			cout << m[i].data[j] << " ";
		}
		if (i == m->nRow - 1) {
			cout << "}";
		}
		cout << endl;
	}
}

double* MaxElement(Matrix* m, int& iRow, int& iCol) {
	double* maxElement = new double[3];
	maxElement[0] = m[0].data[0];
	maxElement[1] = 0;
	maxElement[2] = 0;

	iRow = 0;
	iCol = 0;

	for (int i = 0; i < m->nRow; i++) {
		for (int j = 0; j < m->nCol; j++) {
			if (*maxElement < m[i].data[j]) {
				*maxElement = m[i].data[j];
				maxElement[1] = i;
				maxElement[2] = j;
			}
		}
	}

	return maxElement;
}

Matrix* CreateMatrixB(Matrix* m) {
	Matrix* res = CreateMatrix(m->nRow, m->nCol);

	for (int i = 0; i < m->nRow; i++) {
		for (int j = 0; j < m->nCol; j++) {
			double value = 0;
			for (int iA = i - 1; iA < i + 1; iA++) {
				if (iA<0 || iA>m->nRow) {
					continue;
				}
				else {
					for (int jA = j - 1; jA < j + 1; jA++) {
						if (jA<0 || jA>m->nCol) {
							continue;
						}
						else {
							value += m[iA].data[jA];
						}
					}
				}
			}
			value /= 9;
			res[i].data[j] = value;
		}
	}

	return res;
}

void FreeMatrix(Matrix* m) {
	for (int i = 0; i < m->nRow; i++) {
		delete[] m[i].data;
	}
	delete[] m;
}

void PrintMatrix(Matrix* m, string path) {
	ofstream ofs;
	ofs.open(path);

	for (int i = 0; i < m->nRow; i++) {
		if (i == 0) {
			ofs << "{ ";
		}
		else {
			ofs << "  ";
		}
		for (int j = 0; j < m->nCol; j++) {
			ofs << m[i].data[j] << " ";
		}
		if (i == m->nRow - 1) {
			ofs << "}";
		}
		ofs << endl;
	}

	ofs.close();
}