#include <iostream>
using namespace std;

int main() {
    int hwlength;
    int midlength;
    int finlength;
    double hwavg;
    double midavg;
    double finavg;
    double grade;
    char letter;

    cout << "Write the amount of hw you had" << endl;
    cin >> hwlength;
    cout << "Write the amount of midterms you had" << endl;
    cin >> midlength;
    cout << "Write the amount of finals you had" << endl;
    cin >> finlength;

    int m = hwlength;

    double hw[10000];    
    double mid[10000];    
    double fin[10000];

    cout << "Write your hw scores" << endl;
    for (int i = 0; i < hwlength; i++) {
        cin >> hw[i];
        hwavg += hw[i];
    }

    hwavg /= hwlength;
    cout << "hw avg: " << hwavg << endl << endl;

    cout << "Write your midterm scores" << endl;
    for (int j = 0; j < midlength; j++) {
        cin >> mid[j];
        midavg += mid[j];
    }

    midavg /= midlength;
    cout << "midterm avg: " << midavg << endl << endl;

    cout << "Write your final scores" << endl;
    for (int k = 0; k < finlength; k++) {
        cin >> fin[k];
        finavg += fin[k];
    }

    finavg /= finlength;
    cout << "final avg: " << finavg << endl << endl;

    grade = (double)(0.4) * (hwavg) + (double)(0.4) * (midavg) + (double)(0.2) * (finavg);

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