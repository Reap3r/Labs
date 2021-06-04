#include "Book.h"
#include <iostream>


Book::Book(const Book& temp){
	this->_author = temp._author;
	this->_name = temp._name;
	this->pages_count = temp.pages_count;
}
Book::~Book(){
	
}
void Book::Show(){
	cout << "Book name: " << _name << endl;
	cout << "Author: " << _author << endl;
	cout << "Pages: " << pages_count << endl;
}
void Book::Input(){
	cout << "Book name: ";
	cin >> _name;
	cout << "Author: ";
	cin >> _author;
	cout << "Pages: ";
	cin >> pages_count;
}
