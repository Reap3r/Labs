#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string s;
    int k = 0,n1,n2;
    cout << "Enter 1st:";
    cin >> n1;
    cout << "Enter 2nd:";
    cin >> n2;
    ifstream f1("f1.txt");
    ofstream f2;
    f2.open("f2.txt");
    bool c = false;
    int count=0;
    if (f1.is_open()) {
        while (getline(f1, s) && k != n1 - 1) {
            k++;
            for (int i = 0; i < s.length(); i++) {
            }
        }
        while (getline(f1, s) && k != n2 - 1) {
        	k++;
            for (int i = 0; i < s.length(); i++) {
                if (((s[i] == 'a') || (s[i] == 'A'))&& c != true) {
                    cout<<s<<endl;
                    f2 << s << endl;
                    c = true;
                    count++;
                }
            }
            c=false;
        }
    }
    f2.close();
    f1.close();
	
	ifstream f3("f2.txt");
	int counter=0;
	int max=0;
	string o;
	if (f3.is_open()){
		while(getline(f3, s) && count != 0){
			for(int i=0; i < s.length(); i++){
				if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]== 'o' || s[i]=='U' || s[i]=='u' || s[i]=='Y' || s[i]=='y'){
					counter++;
				}
			}
			if(max<counter){
				max=counter;
				o=s;	
			}
			counter=0;
			count--;
		}
	}
	cout << endl;
	cout << o;


    return 0;
}
