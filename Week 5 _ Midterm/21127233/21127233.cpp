/*
Ho va ten : Vo Quoc Binh
MSSV : 21127233
*/

#include "Function.h"

int main()
{
    /*-----------------------*/
    const char* path = "data.txt";
    srand(1403);
    int nRow = rand() % 6 + 4;
    int nCol = rand() % 8 + 6;
    Matrix* matrix = CreateMatrix(nRow, nCol);
    Options opt = { -100, 100, 2 };
    GenerateMatrix(matrix, opt);
    PrintMatrix(matrix);
    // tạo Ma trận B từ Ma trận A (truyền vào hàm) theo nguyên tắc
    // phần tử B[i,j] là trung bình cộng các số dương trong 
    // ô vuông 3x3 tâm tại (i,j) của A
    // nếu không có số dương thì giá trị 0 được chọn
    Matrix* matrixB = CreateMatrixB(matrix);
    PrintMatrix(matrixB);
    PrintMatrix(matrixB, path);
    FreeMatrix(matrix);
    FreeMatrix(matrixB);
    system("pause");
    return 0;

}
