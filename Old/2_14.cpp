#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int s=0;
	cout << "Input number " << endl;
	cin >> n;
	for (int i=0; i<n.size(); i++){
		s= n[i] - '0' + s;
	}
	cout << "Sum of digits: " << s;
	return 0;
}
