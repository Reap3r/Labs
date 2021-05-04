#include <iostream>
#include "fraction.h"

using namespace std;

void fraction::init(int f, double s) {
    first = f;
    second = s;
}

void fraction::read() {
    cout << "First: "; cin >> first;
    cout << "Second: "; cin >> second;
}

void fraction::show() {
    cout << "First = " << first << endl;
    cout << "Second = " << second << endl;
}

double fraction::multiply() {
    int k;
    cout << "K: ";
    cin >> k;
    return first*second*k;
}
