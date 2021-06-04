#include <iostream>
#include "Dialog.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Choose command:" << endl;
	cout << "m [size] create a group" << endl;
	cout << "+ Add an element" << endl;
	cout << "- Delete an element" << endl;
	cout << "s Show info" << endl;
	cout << "z Show an element info" << endl;
	cout << "q Exit" << endl;
	Dialog D;
	D.Execute();
}
