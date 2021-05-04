#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b,c;
	float x1,x2;
	cout << "Input A then B then C: " << endl;
	cin >> a >> b >> c;
	x1 = (b*(-1)+sqrt(b*b-4*a*c))/(2*a);
	x2 = (b*(-1)-sqrt(b*b-4*a*c))/(2*a);
	cout << "First root: " << x1 << endl;
	cout << "Second root: " << x2 << endl;
	return 0;
}
