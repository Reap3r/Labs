#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void logarifm(int a, int b){
	double c;
	c = log(b)/log(a);
	cout << c << endl;
}
void logarifm(int b){
	double c=log(b);
	cout << c << endl;
}




int main() {
	cout << "Log or ln: " << endl;
	cout << "	1 - Log" << endl;
	cout << "	2 - Ln" << endl;
	int c;
	cin >> c;
	int a, b;
	cout << "Loga(b), where a - basis " << endl;
	if(c == 1){
		cout << "Input basis: " << endl;
		cin >> a;
		cout << "Input b: " << endl;
		cin >> b;
		logarifm(a,b);
	}else{
		cout << "Input b: " << endl;
		cin >> b;
		logarifm(b);
	}
	return 0;
}	
