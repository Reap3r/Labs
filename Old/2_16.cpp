#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int s,n;
	cout << "Input last number ";
	cin >> n;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			s=s+i;
		}else{
			s=s-i;
		}
	}
	cout << "Sum: " << s;
}
