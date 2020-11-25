#include <iostream>
#include <string.h>
#include <array>
using namespace std;
class Integers
{
private:
	int* arr;
	int arrSize;
public:
	Integers(int s) : arr(new int[s - 1]), arrSize(s - 1) {
		for (int i = 0; i < s; i++)
		{
			cin >> this->arr[i];
		}
		cout << endl;
	}

	void changeInt(Integers a, int x, int y) {
		if (x <= 0 || x > this->arrSize + 1) return;
		a.arr[x - 1] = y;
	}


	int getInt(int x) {
		if (x <= 0 || x > this->arrSize + 1) return NULL;
		return this->arr[x - 1];
	}

	void getArr() {
		for (int i = 0; i <= this->arrSize; i++) {
			cout << this->arr[i] << ", " << endl << "array size: " << this->arrSize;
		};
	};


	int  deleteElementByNum(int x) {
		if (x <= 0 || x > this->arrSize + 1) return 0;
		if (x > this->arrSize) {
			this->arrSize--;
			return 1;
		};
		this->arr[x - 1] = this->arr[x];
		x++;
		deleteElementByNum(x);
	}


	void deleteElementByVal(int x) {
		for (int i = 0; i <= this->arrSize; i++) {
			if (this->arr[i] == x)
				this->deleteElementByNum(i + 1);
		};
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


	void getCross(Integers a, Integers b) {
		if (a.arrSize >= b.arrSize) {
			for (int j = 0; j < a.arrSize; j++) {
				for (int i = 0; i < b.arrSize; i++) {
					if (a.arr[j] == b.arr[i]) {
						cout << a.arr[j] << ", ";
						a.deleteElementByVal(b.arr[j]);
					};
				};
			};
		};
		if (b.arrSize > a.arrSize) {
			for (int j = 0; j < b.arrSize; j++) {
				for (int i = 0; i < a.arrSize; i++) {
					if (b.arr[j] == a.arr[i]) {
						cout << b.arr[j] << ", ";
						b.deleteElementByVal(b.arr[j]);
					};
				};
			};
		};
		cout << endl;
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



	void addElement(int x) {
		this->arr[this->arrSize + 1] = x;
	}


};


int operator==(Integers x, Integers y) {
	return x.equalCheck(x, y);
}


void operator||(Integers x, Integers y) {
	x.getUnion(x, y);
}


void operator&& (Integers x, Integers y) {
	x.getCross(x, y);
}


void operator+= (Integers x, int y) {
	x.addElement(y);
}


void operator-= (Integers x, int y) {
	x.deleteElementByNum(y);
}


void operator >> (Integers x, int y) {
	x.addElement(y);
}


void operator << (Integers x, int y) {
	x.getInt(y);
}


int main() {
	int e;
	cout << "array size:" << endl;
	cin >> e;
	Integers coco = Integers(e);
	cout << "array size:" << endl;
	cin >> e;
	Integers poco = Integers(e);
	coco == poco;
	poco.getCross(coco, poco);
	return 0;
}