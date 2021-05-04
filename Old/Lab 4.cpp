#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	cout << "Input array size ";
	int n,i;
	cin >> n;
	int mas[n];
	srand (time(0));
	for(i=0; i<n; i++){
		mas[i] = rand()%50;
	}
	for(i=0; i<n; i++){
		cout << mas[i] << " ";
	}
	cout << endl;
	if(n%2!=0){
		for(i=n/2; i<n; i++){
			mas[i]=mas[i+1];
		}
		n--;
	}
	n+=3;
	int mas2[n];
	int j=n-4;
	for(i=3; i<n; i++){
		mas2[i]=mas[j];
		j--;
	}
	for(i=0;i<3;i++){
		mas2[i]=mas2[i+10]-2;
	}
	
	for(int i=0; i<n; i++){
		cout << mas2[i] << " ";
	}
	return 0;
}
