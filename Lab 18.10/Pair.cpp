#include "Pair.h" 
#include <iostream> 
#include <string>
using namespace std;

Pair::Pair(){
	first = 10;
	second = 14.5;
}
Pair::Pair(int x, double y){
	first = x;
	second = y;
}
Pair::Pair(const Pair& temp){
	first = temp.first;
	second = temp.second;
}
Pair::~Pair(){}
int Pair::GetFirst(){
	return first;
}
double Pair::GetSecond(){
	return second;
}
void Pair::SetFirst(int x){
	first = x;
}
void Pair::SetSecond(double x){
	second = x;
}
Pair Pair::operator*(int z){
	this->first = this->first*z;
	this->second = this->second*z;
	return *this;
}
istream& operator>>(istream &in,Pair& temp){
	cout << "First: "; 
	in >> temp.first;
	cout << "Second: "; 
	in >> temp.second;
	return in;
}
ostream& operator<<(ostream &out, const Pair& temp){
	out << temp.first << ":" << temp.second;
	return out;
}
bool Pair::operator==(const Pair& temp)
{
	if((first == temp.first) && (second == temp.second)){
		return true;
	}else{
		return false;
	}
}
bool Pair::operator!=(const Pair& temp)
{
	if((first != temp.first) && (second != temp.second)){
		return true;
	}else{
		return false;
	}
}
