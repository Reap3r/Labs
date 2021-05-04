#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void deleting(int mas[], int n){
	for(int i = 0; i<n; i++){
		if(mas[i]%2 == 0){
			for(int j=i; j<n; j++){
				mas[j]=mas[j+1];
			}
			n--;
			i--;
		}
	}
	cout << "Answer: " << endl;
	for(int i=0; i<n; i++){
		cout << mas[i] << " ";
	}
	cout << endl;
}

void adding(int mas[], int n){
	srand (time(0));
	int k;
	cout << "Input K: " << endl;
	cin >> k;
	int dopmas[k];
	for(int i=0; i<k; i++){
		dopmas[i] = rand()%50;
	}
	cout << "Your K elemnts: " << endl;
	for(int i=0; i<k; i++){
		cout << dopmas[i] << " ";
	}
	cout << endl;
	int itog[n+k];
	for(int i=0; i<n; i++){
		itog[i]=mas[i];
	}
	int j=0;
	for(int i=n;i<n+k;i++){
		itog[i]=dopmas[j];
		j++;
	}
	cout << "Answer: " << endl;
	for(int i=0; i<n+k; i++){
		cout << itog[i] << " ";
	}
	cout << endl;
}

void transposition(int mas[], int n){
	int temp,k=0;
	for(int i=0; i<n; i++){
		if(mas[i]<0 && i<n-k){
			temp=mas[i];
			for(int j=i; j<n; j++){
				mas[j]=mas[j+1];
			}
			mas[n-1]=temp;
			i--;
			k++;
		}
	}
	cout << "Answer: " << endl;
	for(int i=0; i<n; i++){
		cout << mas[i] << " ";
	}
	cout << endl;
}

void searching(int mas[], int n){
	int j=0;
	while(mas[j]>=0 && j<n){
		j++;
	}	
	cout << "Answer: " << endl;
	if(j!=n){
		cout << mas[j];
	}else{
		cout << "There is no negative";
	}
	cout << endl;
}




void select(int mas[], int n){
	int min, temp; 
	for (int i = 0; i < n - 1; i++) 
	{
		min = i; 
		for (int j = i + 1; j < n; j++) 
		{
		    if (mas[j] < mas[min]){
		    	min = j;
			}      
		}
		temp = mas[i];    
		mas[i] = mas[min];
		mas[min] = temp;
	}
	cout << "Answer: " << endl;
	for (int i=0; i<n; i++){
		cout << mas[i] << " ";
	}
	cout << endl;	
}

int main(){
	int n,k;
	char p = 'n';
	while(p == 'n'){
		system("cls");
		cout <<	"Input numbers' amount of array" << endl;
		cin >> n;
		int mas[n];
		srand (time(0));
		for(int i=0; i<n; i++){
			mas[i] = rand()%50-20;
		}
		cout << "Your array: " << endl;
		for(int i=0; i<n; i++){
			cout << mas[i] << " ";
		}
		cout << endl;
		cout << "Input the number of necessary task" << endl;
		cout << "1 - Deleting all even numbers" << endl;
		cout << "2 - Adding K elements to the end" << endl;
		cout << "3 - Transposition positive numbers to the start, negative to the end" << endl;
		cout << "4 - Searching first negative number" << endl;
		cout << "5 - Selection sorting" << endl;
		cin >> k;
	
		switch (k){
			case 1:
				deleting(mas, n);
				break;
			case 2:
				adding(mas, n);
				break;
			case 3:
				transposition(mas, n);
				break;
			case 4:
				searching(mas, n);
				break;
			case 5:
				select(mas,n);
				break;
			default:
				cout << "Error, try again " << endl;
				break;
		}
		cout << "If you want to stop program type 'e', else type 'n'" << endl;
		cin >> p;
	}
}
