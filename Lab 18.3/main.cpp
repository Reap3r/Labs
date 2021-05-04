#include "Pair.h" 
#include <iostream> 
using namespace std;


int main()
{
	Pair x;
	Pair y;
	cin >> x;
	cin >> y;
	int a;
	cout << "a= ";
	cin >> a;
	double b;
	cout << "b= ";
	cin>> b;
	x=x-a;
	y=y-b;
	cout << "x= " << x << endl; 
	cout << "y= " << y << endl;
	if(x==y){
		cout << x << " == " << y << endl;
	}
	if(x!=y){
		cout << x << " != " << y << endl;
	}
}
