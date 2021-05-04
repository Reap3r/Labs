#pragma once
using namespace std;

class ATM {
	int id;
	double money;
	double sum;
public:
	ATM();
	ATM(int, double, double);
	ATM(const ATM&);
	~ATM();
	int get_id();
	void set_id(int);
	double get_money();
	void set_money(double);
	double get_sum();
	void set_sum(double);
	void show();
};
