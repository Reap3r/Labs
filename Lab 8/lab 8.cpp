#include <iostream>
#include <string>
using namespace std;

const int sportssize = 10;
const int structsize = 10;
	
struct stadium{
    string name;
    string address;
    string capacity; 
    string sports[sportssize];
};

stadium s[structsize];

void make(){
	int n,x;
	cout << "Input amount of stadiums: ";
	cin >> n;
	getline(cin, s[0].name);
	for(int i=0;i<n;i++){
		cout << "Enter name of " << i+1 << " stadium: ";
		getline(cin, s[i].name);
		cout << "Enter address of " << i+1 << " stadium: ";
		getline(cin, s[i].address);
		cout << "Enter capacity of " << i+1 << " stadium: ";
		getline(cin, s[i].capacity);
		cout << "Input amount of types of sport: ";
		cin >> x;
		getline(cin, s[i].sports[i]);
		for(int j=0; j<x; j++){
			cout << "Enter " << j+1 << " spotr's type: ";
			getline(cin, s[i].sports[j]);
		}
	}
}

void print(){
	if(s[0].name == " "){
		cout << "Struct is empty" << endl;
	}
	int i=0;
	int j;
	while(s[i].name != ""){
		cout << i+1 << ". " << s[i].name << endl;
		cout << "   " << s[i].address << endl;
		cout << "   " << s[i].capacity << endl;
		cout << "   " << "Sport's types: " << endl;
		j=0;
		while(s[i].sports[j] != ""){
			cout << "     " << s[i].sports[j] << endl;
			j++;
		}
		i++;
	}
}

void del(){
	string tmp;
	cout << "Enter name you want to delete: ";
	getline(cin, tmp);
	int i=0;
	int j=0;
	while(s[i].name != tmp){
		i++;
	}
	while(s[i].name != ""){
		s[i].name = s[i+1].name;
		s[i].address = s[i+1].address;
		s[i].capacity = s[i+1].capacity;
		while(s[i+1].sports[j] != ""){
			s[i].sports[j] = s[i+1].sports[j];			
			j++;
		}
		if(s[i].sports[j] != ""){
			while(s[i].sports[j] != ""){
				s[i].sports[j] = "";
				j++;
			}
		}
		i++;
	}
}

void add(){
	int tmp;
	cout << "Enter after what number you want to add elements: ";
	cin >> tmp;
	int i=tmp;
	int j;
	while(s[i].name != ""){
		s[i+2].name = s[i].name;
		s[i+2].address = s[i].address;
		s[i+2].capacity = s[i].capacity;
		while(s[i].sports[j] != ""){
			s[i+2].sports[j] = s[i].sports[j];
			j++;
		}
		i++;
	}
	int x=1, y;
	getline(cin, s[8].name);
	for(int i=tmp; i<=tmp+1; i++){
		cout << "Enter name of " << x << " new stadium: ";
		getline(cin, s[i].name);
		cout << "Enter address of " << x << " new stadium: ";
		getline(cin, s[i].address);
		cout << "Enter capacity of " << x << " new stadium: ";
		getline(cin, s[i].capacity);
		cout << "Input amount of types of sport: ";
		cin >> y;
		getline(cin, s[i].sports[i]);
		for(int j=0; j<y; j++){
			cout << "Enter " << j+1 << " spotr's type: ";
			getline(cin, s[i].sports[j]);
		}
		x++;
	}
}

int main(){
	make();
	print();
	del();
	cout << "Your struct after deleting:" << endl;
	print();
	add();
	cout << "Your struct after adding:" << endl;
	print();
    return 0;
}

    
