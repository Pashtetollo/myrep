#include <iostream>
#include <string.h>
#include <array>
using namespace std;
class Integers
{
public:
	int* arr;
	int arrSize;
	Integers(int s ): arr(new int[s-1]), arrSize(s-1) {
		for (int i = 0; i < s; i++)
		{
			cin >> this->arr[i];
		}
		cout << endl;
	}
};

void changeInt(Integers& a, int x, int y) {
	if (x <= 0 || x > a.arrSize + 1) return;
	a.arr[x - 1] = y;
}


int equalCheck(Integers a, Integers b) // 1 if true 0 if false 
{
	if (a.arrSize != b.arrSize) { cout << "NOT EQUAL!"; return 0; };
	for (int i = 0; i <= a.arrSize; i++) {
		for (int j = 0; j <= b.arrSize; j++) {
			if (a.arr[i] == b.arr[j]) {
				b.arr[j] = NULL;
				break;
			};
			if (j == b.arrSize) { cout << "NOT EQUAL!"; return 0; };
		};
	};
	cout << "EQUAL!!!!" << endl;
}
int operator==(Integers x, Integers y){
	return equalCheck(x, y);
}


void getUnion(Integers a, Integers b) {
	for (int i = 0; i <= a.arrSize; i++) {
		cout << a.arr[i] << ", ";
	};
	for (int i = 0; i <= b.arrSize; i++) {
		for (int j = 0; j <= a.arrSize; j++) {
			if (b.arr[i] == a.arr[j]) {
				a.arr[j] = NULL;
				break;
			}
			if (j == a.arrSize) {
				cout << b.arr[i] << ", ";
				b.arr[i] = NULL;
			};
		};
	};
	cout << endl;
}
void operator||(Integers x, Integers y){
	getUnion(x, y);
}



void getCross(Integers a, Integers b) {
	if (a.arrSize >= b.arrSize) {
		for (int j = 0; j < a.arrSize; j++) {
			for (int i = 0; i < b.arrSize; i++) {
				if (a.arr[j] == b.arr[i]) {
					cout << a.arr[j] << ", ";
					deleteElementByVal(a, b.arr[j]);
				};
			};
		};
	};
	if (b.arrSize > a.arrSize) {
		for (int j = 0; j < b.arrSize; j++) {
			for (int i = 0; i < a.arrSize; i++) {
				if (b.arr[j] == a.arr[i]) {
					cout << b.arr[j] << ", ";
					deleteElementByVal(a, b.arr[j]);
				};
			};
		};
	};
	cout << endl;
}
void operator&& (Integers x, Integers y) {
	getCross(x, y);
}


void operator+= (int y, Integers x ) {
	return;
}


void deleteElementByVal(Integers a, int x) {
	for (int i = 0; i <= a.arrSize; i++) {
		if (a.arr[i] == x)
			deleteElementByNum(a, i + 1);
	};
}


int  deleteElementByNum(Integers &a, int x) {
	if (x <= 0 || x > a.arrSize + 1) return 0;
	if (x > a.arrSize) {
		a.arrSize--;
		return 1;
	};
	a.arr[x - 1] = a.arr[x];
	x++;
	deleteElementByNum(a, x);
}
void operator-= (Integers x, int y) {
	deleteElementByNum(x, y);
}


void addElement(Integers& a, int x) {
	a.arr[a.arrSize + 1] = x;
}
void operator+= (Integers x, int y){
	addElement(x, y);
}


int getInt(Integers& a, int x) {
	if (x <= 0 || x > a.arrSize + 1) return NULL;
	return a.arr[x - 1];
}
void operator << (Integers x, int y) {
	cout << getInt(x, y);
}

void getArr(Integers a) {
	for (int i = 0; i <= a.arrSize; i++) {
		cout << a.arr[i] << ", " << endl << "array size: " << a.arrSize;
	};
};


int main() {
	int e;
	cout << "array size:" << endl;
	cin >> e;
	Integers coco = Integers(e);
	cout << "array size:" << endl;
	cin >> e;
	Integers poco = Integers(e);
	poco << e-2;

	return 0;
}