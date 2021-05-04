#include <iostream>
#include <string>
using namespace std;

int main() {
	string n,k;
	cout << "Input number " << endl;
	cin >> n;
	for (int i=n.size()-1; i>=0; i--){
		k=k+n[i];
	}
	cout << "Reverse order: " << k;
	return 0;
}
