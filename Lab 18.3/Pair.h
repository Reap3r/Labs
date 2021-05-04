#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int first;
	double second;
public:
	Pair();
	Pair(int,double);
	Pair(const Pair&);
	~Pair();
	int GetFirst();
	double GetSecond();
	void SetFirst(int);
	void SetSecond(double);
	Pair operator-(int);
	Pair operator-(double);
	friend istream& operator>>(istream& in, Pair&);
	friend ostream& operator<<(ostream& out, const Pair&);
	bool operator==(const Pair&);
	bool operator!=(const Pair&);
	
	
};
