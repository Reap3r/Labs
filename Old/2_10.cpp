#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Amount of elements: ";
	cin >> n;
	int arr[n];
	cout << "Enter the numbers: " << endl ;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << "Your array is: " << endl;
	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	int max=arr[0];
	for (int i=0; i<n; i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	cout << "Max number: " << max;
	return 0;
}
