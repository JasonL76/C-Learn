#include <iostream>
using namespace std;

void printGreeting() {
    cout << "Hope you're having a good day." << endl;
}

void divideNumbers(float x, float y)     {
    float q = x/y;
    if (y == 0) {
        cout << "Cannot perform division" << endl;
    } else {
        cout << q << endl;
    }
}

int factorial(int num) {
    int val = num;
    if (num < 0) {
        cout << 0 << endl;
    } else {
        while (num > 1) {
            val *= (num - 1);
            num--;
        }
        cout << val << endl;
    }
    return 0;
}

void fibonacci(int n) {
    int start = 1;
    int current = 1;
    int prev = 0;

    cout << "0";
    while (start < n) {
        cout << ", " << current;
        current += prev;
        prev = current - prev;
        start++;
    }

}

//Towers of Hanoi: So much recursion involved I gave up (is there a way to do this without recursion lol)

int main() {
    printGreeting();
    divideNumbers(3,2);
    divideNumbers(3,0);
    factorial(5);
    factorial(-3);
    fibonacci(10);
    return 0;
}