#include <iostream>
using namespace std;

int main() {
	int n;						//n - переменная для стороны квадрата
	cin >> n;					//Ввод стороны квадрата
	for(int i=0;i<n;i++){				//Кол-во строк = длине стороны квадрата, идем от 0 до длины стороны квадрата
		cout << "* ";				//В начале каждой строки будет звездочка, значит каждую строку выводим ее в начале
		if (i==0 || i==n-1){			//Проверям на то, какую строку мы делаем, т.к. в первой и последней строка будет состоять только из звезд
			for (int j=0; j<n-2;j++){	//Если условие выполняется выводим кол-во звезд = длине стороны - 2, т.к. одну звезду мы добавляли до цикла, и одну после циклов.
				cout << "* ";		//т.е выводим от 0 до n-2 звезды.
			}
		}else{
			for (int j=0; j<n-2;j++){	//Если условие не выполняется вывподим пробелы внутри квадрата, их кол-во равно длине стороны (n) - 2
				cout << "  ";		//Т.к. в начале и конце строки всегда есть по звезде
			}
		}
		cout << "*";				//В конце каждой строки будет звезда, выводи ее
		cout << endl;				//Переходим на следующую строку по завершению предыдущей
	}
	return 0;
}
