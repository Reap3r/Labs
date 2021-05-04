#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	int size;
	cout << "Enter vector's size: ";
	cin >> size;
	Vector a(size);
	cin >> a;
	cout << "Your vector:" << endl;
	cout << a;
	cout << endl;
	int n;
	cout << "What element you want to change: ";
	cin >> n;
	cout << "Enter new data: ";
	cin >> a[n];
	cout << "Your vector:" << endl;
	cout << a;
	cout << endl;
	cout << "Enter value you want to increase your vector: ";
	cin >> n;
	a=a*n;
	cout << "Your vector's size is " << a() << endl;
	cout << "Your vector:" << endl;
	cout << a;
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "Last element: ";
	cout << *(a.last()) << endl;
	Iterator i = a.last();
	int z;
	cout << "Enter element offset: ";
	cin >> z;
	i-z;
	cout << "Now element is: ";
	cout << *i << endl;
	return 0;
}
