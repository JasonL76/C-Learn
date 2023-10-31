#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 5; i++) {
        SetConsoleTextAttribute(h,i);
        cout << "Party Pooper!" << endl;
    }
    return 0;
}