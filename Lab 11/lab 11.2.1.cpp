#include <iostream>
#include <list>			// Библиотека двунаправленных списков
#include <iterator> 	// Библиотека итераторов
using namespace std;

list<char> mylist;		// Создание двунаправленного списка 

void make(int n){		
	char tmp;
	for (int i = 0; i < n; i++) {
		cout << "Введите " << i+1 << " элемент: ";
		cin >> tmp;
		mylist.push_back(tmp);		// Вводим элементы (tmp) в список, начиная с конца
	}
}

void del() {
	char k; 
	cout << "Введите элемент, который необходимо удалить: " << endl;
	cin >> k;
	mylist.remove(k);								// Удаляем элементы = k
}

void add() {
	int k;
	cout << "Введите кол-во добавляемых элементов: " << endl;
	cin >> k;
	int x;
	cout << "Введите номер элемента перед которым необходимо добавить" << endl;
	cin >> x;
	list<char> :: iterator it;								// Создаем переменныую указателя
	it=mylist.begin();									// Приравниваем ее к указателю начала
	advance(it, x-1);									// Передвигаем ее на кол-во элементов до необходимого
	char tmp;
	list<char> additlist;									// Создаем список элементов которые хотим добавить
	for (int i = 0; i < k; i++) {
		cout << "Введите " << i+1 << " новый элемент: ";
		cin >> tmp;
		additlist.push_back(tmp); 							// Вводим элементы в новый список
	}
	mylist.insert(it,additlist.begin(),additlist.end());	// Добавляем новый список после позиции указателя it
} 

int main() {
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите размер списка" << endl;
	cin >> size;
	make(size);							// Вызов функции ввода элементов списка											
	cout << "Ваш список: " << endl;
	copy(mylist.begin(), mylist.end(), ostream_iterator<char>(cout, " "));	// Функция вывода списка
	cout << endl;
	del();								// Вызов функции удаления элемента с заданным ключом из списка
	cout << "Список после удаления: " << endl;
	copy(mylist.begin(), mylist.end(), ostream_iterator<char>(cout, " "));	// Функция вывода списка
	cout << endl;
	add();								// Вызов функции с добавлением k элементов перед элементом с заданным номером
	cout << "Cписок c добавлением: " << endl;
	copy(mylist.begin(), mylist.end(), ostream_iterator<char>(cout, " "));	// Функция вывода списка
	return 0;
}
