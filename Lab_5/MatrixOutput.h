#pragma once
#include <iostream>
using namespace std;
	void output(int* Arr[]) {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << Arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	};

