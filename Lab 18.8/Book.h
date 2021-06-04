#pragma once
#include "Print.h"
#include <iostream>
using namespace std;

class Book : public Print
{
protected:
	int pages_count;

public:
	Book() : Print(), pages_count(0){
	
	}
	Book(string name, string author, int pages) : Print(name, author), pages_count(pages){
	}
	Book(const Book&);
	~Book();
	void Show();
	void Input();
};
