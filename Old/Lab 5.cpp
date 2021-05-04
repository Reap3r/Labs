#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	cout << "Input array size ";
	int n;
	cin >> n;
	int mas[n][n];
	srand (time(0));
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			mas[i][j] = rand()%10+1;	
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	bool k=true, x=true;
	int b,p=1;
	for(int i=0;i<n;i++){
		k=true;
		b=0;
		for(int j=0; j<n; j++){
			if(mas[0][i]<mas[j][b]){
				k=false;
			}
			b++;
		}
		b=n-1;
		for(int j=0; j<n; j++){
			if(mas[0][i]<mas[j][b]){
				k=false;
			}
			b--;
		}
		if(k==true){
			x=false;
			for(int j=0; j<n; j++){
				p=p*mas[j][i];
			}
		}
	}
	if(x==false){
		cout << "Product is: " << p;	
	}else{
		cout << "There is no right column";
	}
	return 0;
}
