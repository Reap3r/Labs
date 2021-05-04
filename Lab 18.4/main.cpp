#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include <string>
using namespace std;


int main()
{
	Person a("Person", 24);
	Person b;
	cin >> b;
	cout << " a: " << endl << a << endl;
	cout << " b: " << endl << b << endl;
	Teacher x("Teacher", 34, "chemistry", 24);
	Teacher y;
	cin >> y;
	cout << " x: " << endl << x << endl;
	cout << " y: " << endl << y << endl;
	int temp;
	cout << "How many hour u want to add: ";
	cin >> temp;
	y.add(temp);
	cout << " y: " << endl << y << endl;
	return 0;
}
