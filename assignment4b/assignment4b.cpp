#include <iostream>
using namespace std;

int main() {
    int A[2][2];
    int B[2][2];
    int C[2][2];

    cout << "A Matrix: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }
    cout << "A: " << endl << A[0][0] << " " << A[1][1] << endl << A[1][0] << " " << A[1][1] << endl;

    cout << "B Matrix: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }
    cout << "B: " << endl << B[0][0] << " " << B[1][1] << endl << B[1][0] << " " << B[1][1] << endl;

    cout << "C Matrix: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            C[i][j] = (A[i][j] + B[i][j]);
        }
    }
    cout << "C: " << endl << C[0][0] << " " << C[1][1] << endl << C[1][0] << " " << C[1][1] << endl;
    return 0;
}