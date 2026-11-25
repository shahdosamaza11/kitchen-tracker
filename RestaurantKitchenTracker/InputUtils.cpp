#include "InputUtils.h"
#include <cstdlib>

// read an integer, ask again if the user types letters
int readInt() {
    int x;
    cin >> x;
    while (cin.fail()) {
        if (cin.eof())
            exit(0);
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  ! Invalid number, try again: ";
        cin >> x;
    }
    cin.ignore(1000, '\n');   // remove the rest of the line
    return x;
}

// read a decimal number (for prices)
double readDouble() {
    double x;
    cin >> x;
    while (cin.fail()) {
        if (cin.eof())
            exit(0);
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  ! Invalid number, try again: ";
        cin >> x;
    }
    cin.ignore(1000, '\n');
    return x;
}

// read a full line of text (names can have spaces)
string readText() {
    string s;
    getline(cin, s);
    while (s == "") {
        if (cin.eof())
            exit(0);
        cout << "  ! This field cannot be empty: ";
        getline(cin, s);
    }
    return s;
}

// read y or n
bool readYesNo() {
    string s = readText();
    while (s != "y" && s != "Y" && s != "n" && s != "N") {
        cout << "  ! Please type y or n: ";
        s = readText();
    }
    if (s == "y" || s == "Y")
        return true;
    else
        return false;
}

void pressEnter() {
    cout << endl << "  Press Enter to continue...";
    string s;
    getline(cin, s);
    if (cin.eof())
        exit(0);
}

// print the text then spaces until the column reaches the width
void printLeft(string text, int width) {
    cout << text;
    for (int i = text.length(); i < width; i++)
        cout << " ";
}

// print spaces first so the text ends at the column width
void printRight(string text, int width) {
    for (int i = text.length(); i < width; i++)
        cout << " ";
    cout << text;
}

// price with 2 digits after the point, ex: 8.5 -> "8.50"
string formatPrice(double price) {
    int cents = (int)(price * 100 + 0.5);
    int pounds = cents / 100;
    int rest = cents % 100;
    string s = to_string(pounds) + ".";
    if (rest < 10)
        s = s + "0";
    s = s + to_string(rest);
    return s;
}

void printTitle(string title) {
    cout << endl << "  === " << title << " ===" << endl << endl;
}
