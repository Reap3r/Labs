#include "Vector.h"


Vector::Vector(){
	beg=0;
	size=0;
	cur=0;
}

Vector::~Vector(){
} 

Vector::Vector(int n){
	beg=new Object*[n];
	cur=0;
	size=n;
}

void Vector::add(Object *x){
	if(cur<size){
		beg[cur]=x;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& x){
	if(x.size==0){
		out << "Empty" << endl;
	}
	Object **p=x.beg;
	for(int i=0; i<x.cur; i++){
		(*p)->Show();
		cout << endl;
		p++;
	}
	return out;	
}
