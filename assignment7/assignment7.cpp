#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void contact() {
    string fname, lname, phone, email;
    bool at = false;
    bool dot = false;
    ofstream w;

    cout << "Give me their first name" << endl;
    cin >> fname;
    cout << "Give me their last name" << endl;
    cin >> lname;
    cout << "Give me their phone number" << endl;
    cin >> phone;
    while (phone.length() != 10) {
        if (phone.length() != 10) {
            cout << "Phone number not valid. Try again." << endl;
            cin >> phone;
        } else {
            break;
        }
    }
    cout << "Give me their email" << endl;
    cin >> email;
    while (at == false && dot == false) {
        for (int i = 0; i < email.length(); i++) {
            if (email[i] == '@') {
                at = true;
            }
            if (email[i] == '.') {
                dot = true;
            }
        }
        if (at && dot) {
            break;
        }
        cout << "Invalid email. Try again." << endl;
        at = false;
        dot = false;
        cin >> email;
    }

    w.open("Contacts.txt", ios::app);
    w << fname << " " << lname << " " << phone << " " << email << endl;
    w.close();
}

void search() {
    ifstream findname;
    string name, fileline, remove;

    cout << "======================" << endl;
    cout << "Enter the name to search for:" << endl;
    cin >> name;

    findname.open("Contacts.txt");
    bool found = false;
    while (getline(findname, fileline)) {
        //find function returns -1 if it can't find the name.
        if (fileline.find(name) != -1) {
            cout << fileline << endl;
            found = true;
        }
    }
    findname.close();

    if (!found) {
        cout << "Name not found" << endl;
    }
    cout << "======================" << endl;
}

void display() {
    ifstream all;
    string fileline;
    cout << "Here is your total list of contact info:" << endl;
    all.open("Contacts.txt");
    while (getline(all, fileline)) {
        cout << fileline << endl;
    }
    all.close();
}

int main() {
    contact();
    search();
    display();
    return 0;
}