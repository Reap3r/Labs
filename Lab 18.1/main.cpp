#include <iostream>
#include "fraction.h"

using namespace std;

const int NotUsed = system( "color F0" );

fraction MakeFraction(int f, double s){
    fraction p;
    p.init(f,s);
    return p;
}



int main() {
    fraction A;
    fraction B;
    int n=3;
   	A.init(5, 2.3);
    B.read();
    A.show();
    B.show();
	cout << "A.multiply(" << A.first << ", " << A.second <<") = " << A.multiply() << endl;
	cout << "B.multiply(" << B.first << ", " << B.second << ") = " << B.multiply() << endl;
	cout << endl;
    fraction *x = new fraction;
    x->init(2, 0.5);
    x->show();
    cout << "X.multiply(" << x->first << ", " << x->second << ") = " << x->multiply() << endl;
    delete x;
    cout << endl;
    fraction arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].read();
    }
    for (int i = 0; i < n; i++) {
        arr[i].show();
    }
    for (int i = 0; i < n; i++) {
        cout << "arr["<<i<<"].multiply(" << arr[i].first << ", " << arr[i].second << ") = " << arr[i].multiply() << endl;
    }
    cout << endl;
    fraction* d_arr = new fraction[n];
    for (int i = 0; i < n; i++) {
        d_arr[i].read();
    }
    for (int i = 0; i < n; i++) {
        d_arr[i].show();
    }
    for (int i = 0; i < n; i++) {
        cout << "d_arr[" << i << "].multiply(" << d_arr[i].first << ", " << d_arr[i].second << ") = " << d_arr[i].multiply() << endl;
    }
    cout << endl;
    int y; double z;
    cout << "First: "; cin >> y;
    cout << "Second: "; cin >> z;
    fraction f = MakeFraction(y, z);
    f.show();
}
