#include "Person.h"
#include "Teacher.h" 
#include <iostream> 
#include <string>
using namespace std;

Teacher::Teacher() : Person()
{
	subject = "None";
	hours = 0;
}
Teacher::~Teacher()
{

}
Teacher::Teacher(string x, int y, string a, int b) : Person(x,y)
{
	subject = a;
	hours = b;
}
Teacher::Teacher(const Teacher& temp)
{
	name = temp.name;
	age = temp.age;
	subject = temp.subject;
	hours = temp.hours;
}
void Teacher::SetSubject(string x)
{
	subject = x;
}
void Teacher::SetHours(int x)
{
	hours = x;
}
string Teacher::GetSubject(){
	return subject;
}
int Teacher::GetHours(){
	return hours;
}
Teacher& Teacher::operator=(const Teacher& temp)
{
	if (&temp == this)return *this;
	name = temp.name;
	age = temp.age;
	subject = temp.subject;
	hours = temp.hours;
	return *this;
}
istream& operator>>(istream& in, Teacher& temp)
{
	cout << "Name: "; 
	in >> temp.name;
	cout << "Age: "; 
	in >> temp.age;
	cout << "Subject: "; 
	in >> temp.subject;
	cout << "Hours: "; 
	in >> temp.hours;
	return in;
}
ostream& operator<<(ostream& out, const Teacher& temp)
{
	out << "	Name: " << temp.name <<endl;
	out << "	Age: " << temp.age<<endl;
	out << "	Subject: " << temp.subject<<endl;
	out << "	Hours: " << temp.hours<<endl;
	return out;
}

void Teacher::add(int x){
	hours=hours+x;
}
void Teacher::Show(){
	cout << "	Name: " << name <<endl;
	cout << "	Age: " << age<<endl;
	cout << "	Subject: " << subject<<endl;
	cout << "	Hours: " << hours<<endl;
}

