
#include <iostream>
using namespace std;
	int  bubblesort(int i, int** Arr)
	{
		for (int j = 0;j < 5; j++)
		{
			int x = 0;
			if (i < 1)
			{
				return 0;
			}
			for (int k = 0; k < i; k++)
			{
				if (Arr[k][j] < Arr[k + 1][j])
				{
					x = Arr[k][j];
					Arr[k][j] = Arr[k+1][j];
					Arr[k + 1][j]      = x;
				}
			}
		}
		bubblesort(i - 1, Arr);
}

