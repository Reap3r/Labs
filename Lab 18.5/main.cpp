#include <iostream>
#include <string>
#include "Person.h"
#include "Teacher.h"
#include "Vector.h"

int main()
{
	Vector x(5);
	Person a;
	cin >> a;
	cout << endl;
	a.Show();
	cout << endl;
	Teacher b;
	cin >> b;
	cout << endl;
	b.Show();
	cout << endl;
	cout << "--------------------------" << endl;
	Object *p = &a;
	p->Show();
	cout << endl;
	x.add(p);
	p = &b;
	p->Show();
	x.add(p);
	cout << "--------------------------" << endl;
	cout << "Our vector:" << endl;
 	cout << x;
	return 0;
}
