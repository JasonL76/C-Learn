#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int rowA;
    int colA;
    int rowB;
    int colB;

    while (colA != rowB) {
        cout << "Type in the Row of Matrix A:" << endl;
        cin >> rowA;
        cout << "Type in the Column of Matrix A:" << endl;
        cin >> colA;

        cout << "Type in the Row of Matrix B:" << endl;
        cin >> rowB;
        cout << "Type in the Column of Matrix B:" << endl;
        cin >> colB;
        if (colA != rowB) {
            cout << "That won't generate a matrix C. Try again." << endl;
        }
    }

    //use dynamic array
    int** A = new int*[rowA];
    for (int i = 0; i < rowA; i++) {
        A[i] = new int[colA];
    }

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cout << "Enter the value of row " << i << " and column " << j << endl;
            cin >> A[i][j];
        }
    }
    cout << "Matrix A:" << endl;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int** B = new int*[rowB];
    for (int i = 0; i < rowB; i++) {
        B[i] = new int[colB];
    }

    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cout << "Enter the value of row " << i << " and column " << j << endl;
            cin >> B[i][j];
        }
    }
    cout << "Matrix B:" << endl;
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    int** C = new int*[rowA];
    for (int i = 0; i < rowA; i++) {
        C[i] = new int[colB];
    }

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < rowB; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
        cout << endl;
    }

    cout << "Matrix C: " << endl;

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}