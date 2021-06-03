#include "Vector.h"
#include <iostream>

Vector::Vector(int n){
	size = n;
	data = new Pair[size];
}

Vector::Vector(const Vector& temp){
	size = temp.size;
	data = new Pair[size];
	for (int i = 0; i < size; i++){
		data[i].first = temp.data[i].first;
		data[i].second = temp.data[i].second;
	}
}

Vector::~Vector(){
	delete[]data;
}

Vector& Vector::operator=(const Vector& a){
	if (this == &a){
		return *this;	
	}
	size = a.size;
	if (data != 0){
		delete[]data;	
	};
	data = new Pair[size];
	for (int i = 0; i < size; i++){
		data[i].first = a.data[i].first;
		data[i].second = a.data[i].second;
	}
	return *this;
}

int Vector::operator() (){
	return size;
}

Pair &Vector::operator[](int index){
	if (index < size){
		return data[index];	
	}else{
		cout << "Error!" << endl;		
	}
}

Vector Vector::operator*(int x) {
	for (int i = 0; i < this->size; i++){
		this->data[i].first = this->data[i].first * x;
		this->data[i].second = this->data[i].second * x;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Vector& temp)
{
	for (int i = 0; i < temp.size; i++){
		out << temp.data[i].first << ":" << temp.data[i].second << " ";
	}
	return out;
}

istream& operator>>(istream& in, Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		cout << "Enter " << i+1 << " element: ";
		in >> temp.data[i].first;
		in >> temp.data[i].second;
	}
	return in;
}
