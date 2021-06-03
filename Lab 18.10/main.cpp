#include "Pair.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int NotUsed = system( "color F0" );
int size = 100;
Pair *elem = new Pair[size];
int n=0;
void substr_search(){

}

void show(){
	string a;
	ifstream str("elements.txt");
	cout << "Your elements: ";
	if(str.is_open()){
		while(getline(str, a)){
			cout << a << " ";
		}
	}	
	str.close();
	cout << endl;
}

void add(){
	cin >> elem[n];
	n++;
	string a;
	ofstream str;
	str.open("elements.txt");
	for(int i=0;i<n;i++){
		str << elem[i] << endl;
	}
	str.close();
}


void del(){
	Pair k1,k2;
	cout<<"Enter first element: " << endl;
	cin >> k1;
	cout << "Enter second element: " << endl;
	cin >> k2;
	int a1=0,a2=0;
	while(elem[a1]!=k1 || a1<size){
		a1++;
	}
	while(elem[a2]!=k2 || a2<size){
		a2++;
	}
	int count =1;
	if(a1 != size && a2!= size){
		for(int i=a1;i<a2;i++){
			elem[i] = elem[a2+count];
			n--;
			count++;
		}
	}
	string a;
	ofstream str;
	str.open("elements.txt");
	for(int i=0;i<n;i++){
		str << elem[i] << endl;
	}
	str.close();
}

void addn(){
	cout << "Enter amount of elements to add: ";
	int n;
	cin >> n;
	for(int i=size-n-1;i>0;i--){
		elem[i]=elem[i+n];
	}
	cout << "Enter your elements: " << endl;
	for(int i=0;i<n;i++){
		cin>>elem[i];
	}
	string a;
	ofstream str;
	str.open("elements.txt");
	for(int i=0;i<n;i++){
		str << elem[i] << endl;
	}
	str.close();
}

void inc(){
	cout << "Enter element you want to increase: ";
	Pair temp;
	cin >> temp;
	for(int i=0;i<size;i++){
		if(elem[i]==temp){
			elem[i]*2;
		}
	}
	string a;
	ofstream str;
	str.open("elements.txt");
	for(int i=0;i<n;i++){
		str << elem[i] << endl;
	}
	str.close();
}
int main() {
	bool x=true;
	int i;
	while(x){
		cout << "1 - Add element to file" << endl;
		cout << "2 - Show all elements" << endl;
		cout << "3 - Delete all elements between k1 and k2" << endl;
		cout << "4 - Add n elements to the begining" << endl;
		cout << "5 - Increase all k elements" << endl;
		cout << "9 - Clean the console" << endl;
		cout << "0 - Exit the programm" << endl;
		cout << "Your choice: ";
		cin >> i;
		switch(i){
			case 1:
				add();
				break;
			case 2:
				show();
				break;
			case 3:
				del();
				break;
			case 4:
				addn();
				break;
			case 5:
				inc();
				break;
			case 9:
				system("cls");
				break;
			case 0:
				x = 0;
				break;
			default:
				cout << "Unexcepted error, try again" << endl;
				break;
		}
	}
	return 0;
}
