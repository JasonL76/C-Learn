#include <iostream>
using namespace std;

int main() {
    double hw[6];
    double hwavg;
    double mid[2];
    double midavg;
    double fin;
    double grade;
    char letter;

    cout << "Write your six hw scores" << endl;
    for (int i = 0; i < 6; i++) {
        cin >> hw[i];
        hwavg += hw[i];
    }

    hwavg /= 6;
    cout << "hw avg: " << hwavg << endl << endl;

    cout << "Write your two midterm scores" << endl;
    for (int j = 0; j < 2; j++) {
        cin >> mid[j];
        midavg += mid[j];
    }

    midavg /= 2;
    cout << "midterm avg: " << midavg << endl << endl;

    cout << "Write your final score" << endl;
    cin >> fin;

    grade = (double)(0.4) * (hwavg) + (double)(0.4) * (midavg) + (double)(0.2) * (fin);

    if (grade >= 91) {
        letter = 'A';
    } else if (grade >= 81) {
        letter = 'B';
    } else if (grade >= 71) {
        letter = 'C';
    } else if (grade >= 61) {
        letter = 'D';
    } else {
        letter = 'F';
    }

    cout << "Your final grade is: " << grade << ", which gives you a " << letter << endl;

    return 0;
}