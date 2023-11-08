#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1) {
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    }
    else if (i < rowCount - 1) {
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
    }
}

void Print(int **a, const int rowCount, const int colCount, int i, int j) {
    cout << setw(5) << a[i][j];
    if (j < colCount - 1) {
        Print(a, rowCount, colCount, i, j + 1);
    }
    else {
        if (i < rowCount - 1) {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
        else {
            cout << endl
                 << endl;
        }
    }
}

void Transpose(int **a, const int rowCount, const int colCount, const int n) {
    if (rowCount < n) {
        if (colCount < n) {
            if (rowCount < colCount) {
                int temp = a[rowCount][colCount];
                a[rowCount][colCount] = a[colCount][rowCount];
                a[colCount][rowCount] = temp;
            }
            Transpose(a, rowCount, colCount + 1, n);
        }
        else {
            Transpose(a, rowCount + 1, rowCount + 1, n);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Low, High, n;
    cout << "Введіть розмір матриці (n x n): "; cin >> n;
    cout << "Введіть мінімальну границю: "; cin >> Low;
    cout << "Введіть максимальну границю: "; cin >> High;

    int **a = new int *[n];
    for (int i = 0; i < n; i++){
        a[i] = new int[n];
    }

    Create(a, n, n, Low, High, 0, 0);
    cout << "Початкова матриця:" << endl; 
    Print(a, n, n, 0, 0);

    Transpose(a, 0, 1, n);
    cout << "Траспонована матриця:" << endl; 
    Print(a, n, n, 0, 0);

    for (int i = 0; i < n; ++i){
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
