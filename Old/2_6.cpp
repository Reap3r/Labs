#include <iostream>
using namespace std;

int main() {
	int n;					//n - сторона катета из вводных данных
	cin >> n;				//Ввод стороны катета в переменную n
	for(int i=n; i>=1;i--){			//Кол-во строчек для вывода = n, следовательно в цикле идем от кол-ва строчек (n) до нуля, т.к треугольник должен быть справа сверху
		for(int j=1;j<=n-i;j++){	//Кол-во выводимых пробелов зависит от разницы между кол-вом строчек (n) и текущей строчке (i)
			cout << " ";
		}
		for(int j=1; j<=i; j++){	//Кол-во выводимых звезд наоборот равно номеру строки, т.к построение идет сверху вниз
			cout << "*";
		}
		cout << endl;			//Переход на новую строку по завершению построения предыдущей
	}
	return 0;
}
