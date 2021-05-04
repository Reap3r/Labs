#include <iostream>
#include "ATM.h"
using namespace std;

ATM make_ATM() {
    int n;
    double d;
    double s;
    cout << "Enter id: ";
    cin >> n;
    cout << "Enter your money: ";
    cin >> d;
    cout << "Enter max sum to withdrawal: ";
    cin >> s;
    return ATM(n, d, s);
}

void print_ATM(ATM r){
    r.show();
}

int main()
{
    ATM x;
    x.show();
    ATM y(123, 15842.2, 5625.5);
    y.show();
    ATM z = y;
    z.set_id(241);
    z.set_money(89000.0);
    z.set_sum(20420.55);
    print_ATM(z);
    x = make_ATM();
    x.show();
}
