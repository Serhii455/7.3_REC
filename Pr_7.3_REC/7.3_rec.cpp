#include <iostream>
#include <iomanip>

using namespace std;

void Input(int** A, const int rowCount, const int colCount, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
            Input(A, rowCount, colCount, i, j + 1);
        }
        else {
            Input(A, rowCount, colCount, i + 1, 0);
        }
    }
}

void Print(int** A, const int rowCount, const int colCount, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << A[i][j];
            Print(A, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(A, rowCount, colCount, i + 1, 0);
        }
    }
    else {
        cout << endl;
    }
}

int FindZeroRowRecursive(int** A, const int rowCount, const int colCount, int i, int j, int zerorow) {
    if (i < rowCount) {
        if (j < colCount) {
            if (A[i][j] == 0) {
                zerorow++;
            }
            return FindZeroRowRecursive(A, rowCount, colCount, i, j + 1, zerorow);
        }
        else {
            return FindZeroRowRecursive(A, rowCount, colCount, i + 1, 0, zerorow);
        }
    }
    else {
        return zerorow;
    }
}

int FindZeroRow(int** A, const int rowCount, const int colCount) {
    return FindZeroRowRecursive(A, rowCount, colCount, 0, 0, 0);
}

void RorateRight(int** A, const int rowCount, const int colCount, int k, int i) {
    if (i < rowCount) {
        for (int j = 0; j < k; j++) {
            int rotate = A[i][colCount - 1];
            for (int l = colCount - 1; l > 0; l--) {
                A[i][l] = A[i][l - 1];
            }
            A[i][0] = rotate;
        }
        RorateRight(A, rowCount, colCount, k, i + 1);
    }
}

void RorateDown(int** A, const int rowCount, const int colCount, int k, int j) {
    if (j < colCount) {
        for (int i = 0; i < k; i++) {
            int rotate = A[rowCount - 1][j];
            for (int l = rowCount - 1; l > 0; l--) {
                A[l][j] = A[l - 1][j];
            }
            A[0][j] = rotate;
        }
        RorateDown(A, rowCount, colCount, k, j + 1);
    }
}

void ChangeMode(int** A, const int rowCount, const int colCount, int mode, int k) {
    if (mode == 1) {
        RorateRight(A, rowCount, colCount, k, 0);
    }
    else {
        RorateDown(A, rowCount, colCount, k, 0);
    }
}

int main() {
    int rowCount, colCount;

    cout << "rowCount = ";
    cin >> rowCount;
    cout << "colCount = ";
    cin >> colCount;
    cout << setw(5) << endl;

    int** A = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        A[i] = new int[colCount];

    Input(A, rowCount, colCount, 0, 0);

    cout << "Matrix A:" << endl;
    Print(A, rowCount, colCount, 0, 0);
    cout << setw(5) << endl;

    cout << "Number of zero row: " << FindZeroRow(A, rowCount, colCount) << endl;
    cout << setw(5) << endl;

    cout << "If you want the matrix to shift to the right, enter 1, if down - any other value" << endl;
    int mode;
    cout << "mode: ";
    cin >> mode;

    int k;
    cout << "Enter the number by which the elements will shift" << endl;
    cout << "k = ";
    cin >> k;

    ChangeMode(A, rowCount, colCount, mode, k);

    cout << "Updated Matrix A:" << endl;
    Print(A, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
