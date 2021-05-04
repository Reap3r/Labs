#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int size1,size2;
	cout << "input size of array" << endl;
	cout << "Input lines: ";
	cin >> size1;
	cout << "Input columns: ";
	cin >> size2;
	int **arr = new int *[size1];
	for(int i=0;i<size1;i++){
		arr[i] = new int [size2];
	}
	srand (time(0));
	for(int i=0; i<size1; i++){
		for(int j=0; j<size2; j++){
			arr[i][j] = rand()%90+10;
		}
	}
	cout << "Your array: " << endl;
	for(int i=0; i<size1; i++){
		for(int j=0; j<size2; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int min,mini=0,minj=0;
	min= arr[mini][minj];
	for(int i=0; i<size1; i++){
		for(int j=0; j<size2; j++){
			if(min > arr[i][j]){
				min = arr[i][j];
				mini=i;
				minj=j;
			}
		}
	}
	int** narr = new int *[size1-1];
	for(int i=0;i<size1-1;i++){
		narr[i] = new int [size2-1];
	}
	for(int i=0; i<size1-1; i++){
		for(int j=0; j<size2-1; j++){
			narr[i][j] = 0;
		}
	}
	int x=0,y=0;
	for(int i=0;i<size1;i++){
		if(i!=mini){
			y=0;
			for(int j=0;j<size2;j++){
				if(j!=minj){
					narr[x][y]=arr[i][j];
					y++;
				}
			}
			x++;
		}
	}
	for (int i = 0; i < size1; i++){
		delete[] arr[i];	
	}
	delete[]arr;
	cout << "Your new array: " << endl;
	for(int i=0; i<size1-1; i++){
		for(int j=0; j<size2-1; j++){
			cout << narr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
