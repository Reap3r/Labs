#include <iostream>
using namespace std;
char a;


class Stack{
	public:
    	char data;              
    	Stack* prev;         
};

Stack* make_stack(int n)      
{
    if (n == 0) return NULL;
        Stack* top, * p;          
        top = NULL; 
        p = new Stack;       
        cin >> a;
        p->data = a;
        p->prev = NULL;        
        top = p;                  
        for (int i = 2; i <= n; i++) {
            Stack* h = new Stack;  
            cin >> a;
            h->data = a;
            h->prev = top;         
            top = h;            
        }
        return top;
    
}

void print_stack(Stack* top, int n)
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else {
        Stack* p = top;
		char *temp = new char[n];
		int i=0;
        while (p != NULL)    
        {
        	temp[i] = p->data;
			i++;
            p = p->prev; 
        }
		for(int i=n-1; i>=0; i--){
			cout << temp[i] << " ";
		}
		cout << endl;
		delete [] temp;
    }
}

char pop(Stack*& top) 
{
    Stack* p = top;      
    int k = 0;   
    while (p != NULL)   
    {
        k++;
        p = p->prev;
    }
    p = top;
    if (k == 1) 
    {
        char t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else
    {
        Stack* t = p->prev; 
        char u = p->data;
        top = t;
        delete p;
        return u;
    }
}

Stack* push(Stack*& top, char val)
{
    Stack* p = new Stack;
    p->data = val;
    p->prev = top;
    top = p;
    return top;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Enter amount of elements: ";
    int n;
    cin >> n;
    cout << "Enter your elements: ";
    Stack* st = make_stack(n); 
    cout << "Your stack: ";
    print_stack(st,n); 

    char b;
    cout << "Enter deleting key: ";
    cin >> b;
    int k;
    k = 0;
    Stack* st2 = make_stack(0);
    for (int i = 0; i < n; i++)
    {
        char t = pop(st);
        if (t != b)
        {
            push(st2, t);
        }
        else
        {
            k = k + 1;
        }
    }
    n = n - k;
    for (int i = 0; i < n; i++)
    {
        char t = pop(st2);
        push(st, t);
    }
    cout << "Stack after deleting: ";
    print_stack(st,n);

    k = 0;    
    cout << "Enter amount of adding elements: ";
    cin >> k;
    int s = 0;
    cout << "Enter the place where you want to place your new elements: ";
    cin >> s;
    for (int i = 0; i < n - s + 1; i++)
    {
        char t = pop(st);
        push(st2, t);
    }
    cout << "Enter new elements: ";
    for (int i = 0; i < k; i++)
    {
        cin >> a; 
        push(st, a);
    }
    for (int i = 0; i < n - s + 1; i++) 
    {
        char t = pop(st2);
        push(st, t);
    }
    n=n+k;
	cout << "Your new stack: ";
    print_stack(st,n);
    return 0;
}
