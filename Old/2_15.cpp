#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	char z;
	bool x=0;
	cout << "Input number " << endl;
	cin >> n;
	cout << "Input digit " << endl;
	cin >> z;
	for (int i=0;i<n.size();i++){
		if(n[i]==z){
			x=1;
		}
	}
	if(x==1){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}
