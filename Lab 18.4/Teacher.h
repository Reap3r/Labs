#pragma once
#include "Person.h"
#include <string>
class Teacher : public Person
{
protected:
	string subject;
	int hours;
public:
	Teacher();
	Teacher(string, int, string, int);
	Teacher(const Teacher&);
	~Teacher();
	string GetSubject();
	int GetHours();
	void SetSubject(string);
	void SetHours(int);
	void add(int);
	Teacher& operator=(const Teacher&);
	friend istream& operator >> (istream& in, Teacher& l);
	friend ostream& operator << (ostream& out, const Teacher& l);
};
