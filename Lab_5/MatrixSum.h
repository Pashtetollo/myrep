
#include <iostream>
#include <math.h>
using namespace std;
	float midArif(int i, int *Arr[])
	{
		int j = 0;
		float sum = 0;
		while (j < i)
		{
			sum = sum + Arr[i][j];
			j++;
		}
		return sqrt(sum);
	};


	float midArifSum(int *Arr[])
	{
		float sumOfsum = 0;
		for (int i = 0; i < 5; i++)
		{
			int j = 0;
			float sum = 0;
			while (j < i)
			{
				sum = sum + Arr[i][j];
				j++;
			}
			sumOfsum = sumOfsum + sqrt(sum);
		}
		return sumOfsum;
	};

