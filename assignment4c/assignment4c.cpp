#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int val;
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    while (val != -1) {
        cin >> val;
        if (val == -1) {
            break;
        }
        sum += val;
        if (val < min) {
            min = val;
        }
        if (val > max) {
            max = val;
        }
    }

    cout << "Sum: " << sum << ", Min: " << min << ", Max: " << max;
    return 0;
}