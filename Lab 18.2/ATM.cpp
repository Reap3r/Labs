#include "ATM.h"
#include <iostream>

using namespace std;

ATM::ATM() {
	id = 0;
	money = 0.0;
	sum = 0.0;
	cout << "Empty constructor worked for " << this << endl;
}

ATM::ATM(int n, double d, double s) {
	id = n;
	money = d;
	sum = s;
	cout << "Constructor with parameters worked for " << this << endl;
}

ATM::ATM(const ATM &r) {
	id = r.id;
	money = r.money;
	sum = r.sum;
	cout << "Copy constructor worked for " << this << endl;
}

ATM::~ATM() {
	cout << "Destructor worked for " << this << endl;
}

int ATM::get_id() {
	return id;
}

void ATM::set_id(int n) {
	id = n;
}

double ATM::get_money(){
	return money;
}

void ATM::set_money(double d) {
	money = d;
}

double ATM::get_sum() {
	return sum;
}

void ATM::set_sum(double s) {
	sum = s;
}

void ATM::show() {
	cout << "Id: " << id << endl;
	cout << "Your money: " << money << endl;
	cout << "Max sum to withdrawal: " << sum << endl;
}
