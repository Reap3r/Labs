#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Book.h"
using namespace std;

Vector::Vector()
{
	_begin = NULL;
	_current = 0;
	_size = 0;
}

Vector::Vector(int count)
{
	_begin = new Object * [count];
	_current = 0;
	_size = count;
}

Vector::~Vector()
{
	if (_begin != NULL)
		delete[] _begin;
	_begin = NULL;
}

void Vector::Add()
{
	if (_size == 0)
	{
		cout << "Empty" << endl;
		return;
	}

	Object* p;
	cout << "Choose your class: " << endl;
	cout << "1 - Print" << endl;
	cout << "2 - Book" << endl;
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		Print* t = new Print;
		t->Input();
		p = t;
	}
	else
	{
		Book* t = new Book;
		t->Input();
		p = t;
	}

	if (_current < _size)
	{
		_begin[_current] = p;
		_current++;
	}
}

void Vector::Show1(int x)
{
	if (_current == 0)
	{
		cout << "Empty" << endl;
	}
	else
	{
		Object** p = _begin;
		for (int i = 0; i < _current; i++)
		{
			if(i==x){
				(*p)->Show();
				p++;
				cout << endl;
			}
		}
	}
}

void Vector::Show()
{
	if (_current == 0)
	{
		cout << "Empty" << endl;
	}
	else
	{
		Object** p = _begin;
		for (int i = 0; i < _current; i++)
		{
			(*p)->Show();
			p++;
			cout << endl;
		}
	}
}

void Vector::Del()
{
	if (_size == 0)
	{
		cout << "Empty" << endl;
	}
	if (_current > 0)
		_current--;
}

int Vector::operator ()()
{
	return _current;
}

void Vector::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		Object** p = _begin;
		for (int i = 0; i < _current; i++)
		{
			(*p)->HandleEvent(event);
			p++;
		}
	}
}
