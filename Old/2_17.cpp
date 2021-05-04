#include <iostream>
#include <cmath>
using namespace std;

int fact(int i){
	if (i==0){
		return 1;
	}else{
		return i*fact(i-1);
	}
}

int main() {
	int n,x;
	float s=0;
	cout << "Input n ";
	cin >> n;
	cout << "Input x ";
	cin >> x;
	for(int i=0;i<=n;i++){
		s=s+(pow(x,i)/fact(i));
	}
	cout << "Sum: " << s;
}
