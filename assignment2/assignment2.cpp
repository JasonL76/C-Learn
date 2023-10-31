#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int int1,int2;
    cout << "Type two numbers:" << endl;
    cin >> int1;
    cin >> int2;

    int sum = int1 + int2;
    int diff = int1 - int2;
    int prod = int1 * int2;
    int div = int1 / int2;

    cout << "Sum: " << sum << ", Difference: " << diff << ", Product: " << prod << ", Quotient: " << div << endl;

    float float1,float2;
    cout << "Type two float numbers:" << endl;
    cin >> float1;
    cin >> float2;

    float fsum = float1 + float2;
    float fdiff = float1 - float2;
    float fprod = float1 * float2;
    float fdiv = float1 / float2;

    cout << "Sum: " << fsum << ", Difference: " << fdiff << ", Product: " << fprod << ", Quotient: " << fdiv << endl;

    string str1, str2, result;
    cout << "Type two random words" << endl;
    cin >> str1;
    cin >> str2;

    for (int i = 0; i < str1.size(); i++) {
        result = result + str1[i];
    }

    for (int j = 0; j < str2.size(); j++) {
        result = result + str2[j];
    }

    cout << "Here is the concatenated string: " << result << endl;

    //check+ portion: do trig
    float degree;

    cout << "Give me an angle" << endl;
    cin >> degree;

    float PI = 3.14159265358;
    float radian = (degree) * (PI/180);
    float sine = sin(radian);
    float cosine = cos(radian);
    float tangent = tan(radian);

    cout << "Sine: " << sine << ", Cosine: " << cosine << ", Tangent: " << tangent;

    return 0;
}