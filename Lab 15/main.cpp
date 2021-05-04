#include <iostream>
#include <string>
using namespace std;
const int NotUsed = system( "color F0" );

struct Books{ 
    string author;
    string name;
};

void Shell(Books* a, int n)
{
	int b = n / 2;
	while (b > 0)
	{
		for (int i = 0; i < n - b; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j].author > a[j + b].author)
				{
					string d = a[j].author;
					a[j].author = a[j + b].author;
					a[j + b].author = d;
					string f = a[j].name;
					a[j].name = a[j + b].name;
					a[j + b].name = f;
					j -= b;
				}
				else
					j = -1;
			}
		}
		b /= 2;
	}
}

void Hoar(Books* arr, int left, int right)
{
	string d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i].author > arr[(left + right) / 2].author && i < right)
			i++;
		while (arr[j].author < arr[(left + right) / 2].author && j > left)
			j--;
		if (i <= j)
		{
			d = arr[i].author;
			arr[i].author = arr[j].author;
			arr[j].author = d;
			f = arr[i].name;
			arr[i].name = arr[j].name;
			arr[j].name = f;
			i++;
			j--;
		}
		if (i < right)
		{
			Hoar(arr, i, right);
		}
		if (j > left)
		{
			Hoar(arr, left, j);
		}
	}
}

int main() {
	int size;
	cout << "Enter number of Books: ";
    cin >> size;
    cout << endl;
    Books *p = new Books[size];
	for (int i = 0; i < size; i++)
    {
        cout << "Enter the name of book: ";
        
        getline(cin,p[i].name);
		getline(cin,p[i].name);	
        cout << "Enter author FCs:";
        cin >> p[i].author;
        cout << endl;
    }
    cout << endl;
    int choice;
    cout << "Choose your sort method: " << endl;
    cout << "1 - Shell sort" << endl;
    cout << "2 - Hoar sort" << endl;
    cout << "Your desicion: ";
    cin >> choice;
    switch (choice){
    	case 1:
    		Shell(p,size);
    		cout << endl;
    		cout << "Your sorted struct: " << endl;
			for(int i=0; i<size; i++){
				cout << "Your " << i+1 << " book: " << endl;
				cout << "	Author: " << p[i].author << endl;
				cout << "	Book: " << p[i].name << endl;
			}
    		break;
    	case 2:
    		Hoar(p,0,size-1);
    		cout << endl;
    		cout << "Your sorted struct: " << endl;
			for(int i=size-1; i>=0; i--){
				cout << "Your " << size-i << " book: " << endl;
				cout << "	Author: " << p[i].author << endl;
				cout << "	Book: " << p[i].name << endl;
			}
    		break;
    	default:
    		cout << "There is no number with this operation" << endl;
    		break;
	}
	delete [] p;
	return 0;
}
