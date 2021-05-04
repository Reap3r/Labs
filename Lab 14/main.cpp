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

void boyer_moore(){
	string ct;
	cout << "Enter the substring: ";
	getline(cin,ct);
	getline(cin,ct);
	string st;
	int stl, ctl;
	int answer;
	bool m=true, n=true;
	for(int z=0; z<size; z++){
		st=astr[z].address;
		stl = st.size();    
	    ctl = ct.size();
		if (stl != 0 && ctl != 0 && stl >= ctl)   
	    {
	        int i, p;
	        int b[256];     
	        for (i = 0; i < 256; i++)
	        {
	            b[i] = ctl;    
	        }
	        for (i = ctl - 2; i >= 0; i--) 
	        {
	            if (b[int((unsigned char)ct[i])] == ctl)    
	            {
	                b[int((unsigned char)ct[i])] = ctl - i - 1; 
	            }
	        }
	        p = ctl - 1; 
	        n=true;
	        while (p < stl && n==true) 
	        {
	            if (ct[ctl - 1] != st[p])  
	            {
	                p += b[int((unsigned char)st[p])];
	            }
	            else  
	            {
	                for (i = ctl - 1; i >= 0; i--) 
	                {
	                    if (ct[i] != st[p - ctl + i + 1]) 
	                    {
	                        p += b[int((unsigned char)st[p])];  
	                        break; 
	                    }
	                    else if (i == 0) 
	                    {
	                        cout << "Element number: " << z+1 << endl;
							cout << "This element: " << endl;
							cout << "	" << astr[z].FCs << endl;
							cout << "	" << astr[z].birthday << endl;
							cout << "	" << astr[z].address << endl;
	                        m=false;
	                        n=false;
	                    }
	                }
	            }
	        }
	    }
	}
	if(m==true){
		cout << "There is no element with this key" << endl;
	}
}

bool KMP(string str,string key)
{
	int stl = str.size();
	int ctl = key.size();
	if (stl != 0 && ctl != 0 && stl > ctl)
	{
		int  i, j = 0, k = -1;
		int* pf = new int[1000];
		pf[0] = -1;
		while (j < ctl - 1)
		{
			while (k >= 0 && key[j] != key[k])
			{
				k = pf[k];
			}
			j++;
			k++;
			if (key[j] == key[k])
			{
				pf[j] = pf[k];
			}
			else
			{
				pf[j] = k;
			}
		}
		i = 0;
		j = 0;
		while (j < ctl && i < stl)
		{
			while (j >= 0 && str[i] != key[j])
			{
				j = pf[j];
			}
			i++;
			j++;
		}
		delete[] pf;
		if (j == ctl)
		{
			return true;
		}
		else
		{
			return false;
		}
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
	string key;
	bool m=true;
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
				cout << "4 - Boyer-Moore string-search" << endl;
				cout << "5 - Knuth-Morris-Pratt string-search" << endl;
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
					case 4:
						boyer_moore();
						break;
					case 5:
						cout << "Enter the key: ";
						getline(cin,key);
						getline(cin,key);
						for(int i=0;i<size;i++){
							if(KMP(astr[i].address, key)){
								cout << "Element number: " << i+1 << endl;
								cout << "This element: " << endl;
								cout << "	" << astr[i].FCs << endl;
								cout << "	" << astr[i].birthday << endl;
								cout << "	" << astr[i].address << endl;
								m=false;
							}
						}
						if(m==true){
							cout << "There is no element with this key" << endl;
						}
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
