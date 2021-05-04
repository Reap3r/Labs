#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Vector{
	Object**beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int);
	~Vector();
	void add(Object *);
	friend ostream& operator<<(ostream& out, const Vector&);
	
};
