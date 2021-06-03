#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class Vector
{
public:
	Vector(int);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector&);
	Pair& operator[](int);
	int operator() ();
	Vector operator*(int);
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
private:
	int size;
	Pair* data;
};
