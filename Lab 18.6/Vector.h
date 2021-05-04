#pragma once
#include <iostream>
using namespace std;
class Iterator
{
	friend class Vector;
public:
	Iterator(){
		element = 0; 
	}
	Iterator(const Iterator& temp){
		element = temp.element;
	}
	void operator++(){
		++element;
	}
	void operator--(){
		--element;
	}
	void operator-(int n){
		element-=n;
	}
	int& operator *() const{
		return *element;
	}
private:
	int* element;
};

class Vector
{
public:
	Vector(int);
	Vector(const Vector&);
	~Vector();
	Iterator first(){
		return beg;
	}
	Iterator last() {
		return end;
	}
	Vector& operator=(const Vector&);
	int& operator[](int);
	int operator() ();
	Vector operator*(int);
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};
