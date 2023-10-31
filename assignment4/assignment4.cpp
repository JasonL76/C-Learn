#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int val[10];
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < 10; i++) {
        cin >> val[i];
        sum += val[i];

        if (val[i] < min) {
            min = val[i];
        }

        if (val[i] > max) {
            max = val[i];
        }
    }
    cout << "Sum: " << sum << ", Min: " << min << ", Max: " << max;
    return 0;
}