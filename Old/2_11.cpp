#include <iostream>
using namespace std;

int main() {
	int n, i;
	cout << "Amount of elements: ";
	cin >> n;
	int arr[n];
	cout << "Enter the numbers: " << endl ;
	for (i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << "Your array is: " << endl;
	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	bool k = false;
	i=0;
	while(i<n && k==false){
		if(arr[i] > 0){
			k=true;
		}
		if(arr[i] < 0){
			k=true;
		}
		i++;
	}
	if(k==false){
		cout << "All numbers = 0";
	}else{
		if(arr[i-1]>0){
			cout << "First number >0: " << arr[i-1];
		}else{
			cout << "First number <0: " << arr[i-1];
		}
	}
	return 0;
}
