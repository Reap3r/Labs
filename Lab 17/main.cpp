#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

struct info{
	string FCs;
	string birthday;
	string address;
};

int GetValue(string str) {
	int value = 0;
	int j = 1;
	for (int i=0; i<str.length(); i++) {
		value += str[i] * j;
		j++;
	}
	return value;
}

int Hash(string str, int size)
{
	double f;
	return int(size * modf(GetValue(str) * 0.803523421, &f));
}

void MakeTable(int size, info* st2)
{
	int n=size;
	int* table = new int[size];
	int Hashsize = size;
	for (int i = 0; i < size; i++)
	{
		table[i] = 0;
	}
	int collis = 0;
	for (int k = 0; k < n; k++)
	{
		int num;
		int hash = Hash(st2[k].address, Hashsize);
		if (table[hash] == 0)
		{
			table[hash] = k;
		}
		else
		{
			num = hash;
			while (num < size && table[num] != 0)
			{
				collis++;
				num++;
			}
			if (num >= size)
			{
				size *= 2;
				int* temptable = new int[size];
				for (int i = 0; i < size / 2; i++)
				{
					temptable[i] = table[i];
				}
				for (int i = size / 2; i < size; i++)
				{
					temptable[i] = 0;
				}
				delete[]table;
				table = temptable;
			}
			if (table[num] == 0)
			{
				table[num] = k;
			}
		}
	}
	cout << "Collisions' amount: " << collis << endl;
	cout << "Enter key for searching: ";
	string key;
	cin.ignore();
	getline(cin, key);
	int hashkey = Hash(key, Hashsize);
	if (st2[table[hashkey]].address == key)
	{
		cout << "Element found: " << endl;
		cout << "	" << st2[table[hashkey]].FCs << endl;
		cout << "	" << st2[table[hashkey]].birthday << endl;
		cout << "	" << st2[table[hashkey]].address << endl;
	}
	else
	{
		while (st2[table[hashkey]].address != key && hashkey < size/2)
		{
			hashkey++;
		}
		if (st2[table[hashkey]].address == key)
		{
			cout << "Element found: " << endl;
			cout << "	" << st2[table[hashkey]].FCs << endl;
			cout << "	" << st2[table[hashkey]].birthday << endl;
			cout << "	" << st2[table[hashkey]].address << endl;
		}
		else
			cout << "There is no such element";
	}	
}

int main() {
	int size;
	string a;
	ifstream str("Struct.txt");
	cout << "Enter struct size: ";
	cin >> size;
	info *arr = new info[size];
	for(int i=0; i<size; i++){
		if(str.is_open()){
			if(getline(str, a)){
				arr[i].FCs = a;
			}
			if(getline(str, a)){
				arr[i].birthday = a;
			}
			if(getline(str, a)){
				arr[i].address = a;
			}
		}	
	}
	str.close();
	MakeTable(size, arr);
	return 0;
}
