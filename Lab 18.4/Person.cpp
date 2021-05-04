#include "Person.h" 
#include <iostream> 
#include <string>
using namespace std;

Person::Person()
{
	name = "None";
	age = 0;
}
Person::~Person()
{

}
Person::Person(string x, int y)
{
	name = x;
	age = y;
}
Person::Person(const Person& temp)
{
	name = temp.name;
	age = temp.age;
}
void Person::SetName(string x)
{
	name = x;
}
void Person::SetAge(int x)
{
	age = x;
}
string Person::GetName(){
	return name;
}
int Person::GetAge(){
	return age;
}
Person& Person::operator=(const Person& temp)
{
	if (&temp == this)return *this;
	name = temp.name;
	age = temp.age;
	return *this;
}
istream& operator>>(istream& in, Person& temp)
{
	cout << "Name: "; 
	in >> temp.name;
	cout << "Age: "; 
	in >> temp.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& temp)
{
	out << "	Name: " << temp.name << endl;
	out << "	Age =  " << temp.age << endl;
	return out;
}

