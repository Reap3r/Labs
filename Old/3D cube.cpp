#include <iostream>
using namespace std;
						//Задание на Куб, Не предстовляю как, но работает
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n/2;i++){
        for(int j=n/2;j>i;j--){
            cout << " ";
        }
        cout << "* ";
        if (i==0 || i==n/2){
            for (int j=0; j<n-2;j++){
                cout << "* ";
            }
        }else{
            for (int j=0; j<n-2;j++){
                cout << "  ";
            }
        }
        cout << "*";
        for (int j=1; j<i; j++){
            cout << " ";
        }
        if (i>0){
            cout << "*";
        }
        cout << endl;
    }						//Вывод верхней части, которая идет наискосок. Кол-во строк равно n/2
    for(int i=0;i<n;i++){
        cout << "* ";
        if (i==0 || i==n-1){
            for (int j=0; j<n-2;j++){
                cout << "* ";
            }
        }else{
            for (int j=0; j<n-2;j++){
                cout << "  ";
            }
        }
        cout << "*";
        if(n%2==0){
            if (i<=n/2-1){
                for(int j=0;j<n/2-1;j++){
                    cout << " ";
                }
                cout << "*";
            }else{
                for(int j=i;j<n-2;j++){
                    cout << " ";
                }
                if(i!=n-1){
                    cout << "*";
                }
            }
        }else{
            if (i<=n/2){
                for(int j=0;j<n/2-1;j++){
                    cout << " ";
                }
                cout << "*";
            }else{
                for(int j=i;j<n-2;j++){
                    cout << " ";
                }
                if(i!=n-1){
                    cout << "*";
                }
            }    
        }					//Вывод оставшейся части сам квадрат из 2_7_3 + недостающие звезды для объема
        cout << endl;
    }
    return 0;
}
		
