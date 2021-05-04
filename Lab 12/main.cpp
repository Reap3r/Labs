#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int NotUsed = system( "color F0" );
const int size = 100;

struct info{
	string FCs;
	string birthday;
	string address;
};

info* astr = new info[size];

void make(){
	string a;
	ifstream str("Struct.txt");
	for(int i=0; i<size; i++){
		if(str.is_open()){
			if(getline(str, a)){
				astr[i].FCs = a;
			}
			if(getline(str, a)){
				astr[i].birthday = a;
			}
			if(getline(str, a)){
				astr[i].address = a;
			}
		}	
	}
	str.close();
}

void linear_search(){
	string a;
	bool n = true;
	cout << "Enter the key: ";
	getline(cin,a);
	getline(cin,a);
	for(int i=0; i<size; i++){
		if(astr[i].address == a){
			cout << "Element number: " << i+1 << endl;
			cout << "This element: " << endl;
			cout << "	" << astr[i].FCs << endl;
			cout << "	" << astr[i].birthday << endl;
			cout << "	" << astr[i].address << endl;
			n=false;
		}
	}
	if(n=true){
		cout << "There is no element with this key" << endl;
	}
}

void substr_search(){
	string substr;
	cout << "Enter the substring: ";
	getline(cin,substr);
	getline(cin,substr);
	string str;
	bool x=true, n=true;
	for(int i=0; i<size; i++){
		str=astr[i].address;
		for(int j=0; j<str.size(); j++){
			x=true;
			for(int k=0; k<substr.size();k++){
				if(substr[k]!=str[j+k]){
					x=false;
				}
			}
			if(x==true){
				cout << "Element number: " << i+1 << endl;
				cout << "This element: " << endl;
				cout << "	" << astr[i].FCs << endl;
				cout << "	" << astr[i].birthday << endl;
				cout << "	" << astr[i].address << endl;
				n=false;
			}
		}
	}
	if(n=true){
		cout << "There is no element with this key" << endl;
	}
}


void interp_search(){
	int* arr = new int[size];
	int sum;
	string str;
	for(int i=0; i<size;i++){
		str=astr[i].address;
		sum=0;
		for(int j=0;j<str.size();j++){
			sum+=str[j];
		}
		arr[i]=sum;
	}
	int min, temp; 
	for (int i = 0; i < size-1; i++) 
	{
		min = i; 
		for (int j = i + 1; j < size; j++) 
		{
		    if (arr[j] < arr[min]){
		    	min = j;
			}      
		}
		temp = arr[i];    
		arr[i] = arr[min];
		arr[min] = temp;
	}
	string key;
	int sumkey;
	cout << "Enter the key: ";
	getline(cin,key);
	getline(cin,key);
	for(int i=0;i<key.size();i++){
			sumkey+=key[i];
	}
	int mid, left=0, right = size-1;
	int answer;
	bool z=true;
	while(arr[left]<=sumkey && arr[right]>= sumkey && z){
		mid = left + ((sumkey - arr[left]) * (right - left))/(arr[right]-arr[left]);
		if (arr[mid]<sumkey){
			left=mid+1;
		}else{
			if(arr[mid]> sumkey){
				right = mid-1;
			}else{
				answer=mid;
				z=false;
			}
		}
	}
	sum=0;
	int l=0;
	if(z==true){
		if (arr[left]==sumkey){
			answer = left;
		}else{
			answer = -1;
		}
	}
	if (answer>-1){
		for(int i=0; i <size; i++){
			str=astr[i].address;
			sum=0;
			for(int j=0; j<str.size(); j++){
				sum+=str[j];
			}
			if(sum==arr[answer]){
				cout << "Element number: " << i+1 << endl;
				cout << "This element: " << endl;
				cout << "	" << astr[i].FCs << endl;
				cout << "	" << astr[i].birthday << endl;
				cout << "	" << astr[i].address << endl;
			}
		}
	}else{
		cout << "There is no element with this key" << endl;
	}
}

void print(){
	cout << "Your struct: " << endl;
	for(int i=0; i<size;i++){
		cout << "Your " << i+1 << " person: " << endl;
		cout << "	" << astr[i].FCs << endl;
		cout << "	" << astr[i].birthday << endl;
		cout << "	" << astr[i].address << endl;
	}
}


void save(){
	string a;
	ofstream str;
	str.open("Struct.txt");
	for(int i=0; i<size; i++){
		str << astr[i].FCs << endl;
		str << astr[i].birthday << endl;
		str << astr[i].address << endl;
	}
	str.close();
}

int main() {
	bool x=true;
	int i;
	while(x){
		cout << "1 - Take info for structure from Struct.txt" << endl;
		cout << "2 - Save structure in file Struct.txt" << endl;
		cout << "3 - Print your structure" << endl;
		cout << "4 - Find an element by a key Address" << endl;
		cout << "9 - Clean the console" << endl;
		cout << "0 - Exit the programm" << endl;
		cout << "Your choice: ";
		cin >> i;
		switch(i){
			case 1:
				make();
				break;
			case 2:
				save();
				break;
			case 3:
				print();
				break;
			case 4:
				int v;
				cout << "1 - Linear search method" << endl;
				cout << "2 - Method of straight search of substring in a string" << endl;
				cout << "3 - Interpolation method" << endl;
				cout << "0 - Choose other operation" << endl;
				cout << "Your choice: ";
				cin >> v;
				switch(v){
					case 1:
						linear_search();
						break;
					case 2:
						substr_search();
						break;
					case 3:
						interp_search();
						break;
					case 0:
						break;
					default:
						cout << "Unexcepted error, try again" << endl;
						break;		
				}
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
