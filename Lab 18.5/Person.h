#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string,int);
	Person(const Person&);
	~Person();
	string GetName();
	int GetAge();
	void SetName(string);
	void SetAge(int);
	Person& operator=(const Person&);
	friend istream& operator>>(istream& in, Person&);
	friend ostream& operator<<(ostream& out, const Person&);
	void Show();
	
};
