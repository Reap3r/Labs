#include <iostream>
#include <cmath>
using namespace std;
double s=0;
double n = 1;
int lim(double eps, unsigned long int n){
	if(eps>s){
		s=s+pow((1+1/n), n);
		lim(eps, n);
		cout << s << endl;
	}else{
		return s;
	}
}




int main() {
	const double eps = 10e-16;
	lim(eps, n);
	cout << s;
	return 0;
}	
