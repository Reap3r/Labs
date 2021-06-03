#include "Vector.h"
#include <iostream>
Vector::Vector(int n){
	size = n;
	data = new int[size];
	beg.element = &data[0];
	end.element = &data[size-1];
}

Vector::Vector(const Vector& temp){
	size = temp.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = temp.data[i];
	beg = temp.beg;
	end = temp.end;
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
	data = new int[size];
	for (int i = 0; i < size; i++){
		data[i] = a.data[i];	
	}
	beg = a.beg;
	end = a.end;
	return *this;
}

int Vector::operator() (){
	return size;
}

int& Vector::operator[](int index){
	try{
		if (index < size){
			return data[index];	
		}else{
			throw index;
		}
	}
	catch (int index){
		cout << "We caught an exception, your index could not be bigger or equal to size " << index << " > " << size << endl;
		cout << "Index was changed to last element"<<endl;
		return data[size-1];
	}
}

Vector Vector::operator*(int x) {
	for (int i = 0; i < this->size; i++)
		this->data[i] = this->data[i] * x;
	return *this;
}

ostream& operator<<(ostream& out, const Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
		out << temp.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		cout << "Enter " << i+1 << " element: ";
		in >> temp.data[i];
	}
	return in;
}
