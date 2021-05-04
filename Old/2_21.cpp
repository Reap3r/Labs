#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "Input first number ";
	cin >> x;
	int y=x;
	bool k=true;
	if(x!=0){
		while (x!=0){
			cout << "Input next number ";
			cin >> x;
			if (x<y && x!=0){
				k=false;
			}
			y=x;
		}
	}
	if(k==true){
		cout << "Yes ";
	}else{
		cout << "No ";	
	}
}
