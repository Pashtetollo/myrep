#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
private:
	int A[5][5];
public:
	Matrix()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				this->A[i][j] = i * 5 + j;
			}
		}
	};

	Matrix(char x)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> this->A[i][j];
			}
		}
	};

	void input()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> this->A[i][j];
			}
		}
	}



	int output() {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << this->A[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		return 0;
	};


	int  bubblesort(int i)
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
				if (this->A[k][j] < this->A[k + 1][j])
				{
					x = this->A[k][j];
					this->A[k][j] = this->A[k + 1][j];
					this->A[k + 1][j] = x;
				}
			}
		}
		this->bubblesort(i - 1);
	};


	float midArif(int i)
	{
		int j = 0;
		float sum = 0;
		while (j < i)
		{
			sum = sum + this->A[i][j];
			j++;
		}
		return sqrt(sum);
	};


	float midArifSum()
	{
		float sumOfsum = 0;
		for (int i = 0; i < 5; i++)
		{
			int j = 0;
			float sum = 0;
			while (j < i)
			{
				sum = sum + this->A[i][j];
				j++;
			}
			sumOfsum = sumOfsum + sqrt(sum);
		}
		return sumOfsum;
	};

};
int main()
{
	Matrix Array = Matrix();
	Array.output();
	Array.bubblesort(4);
	Array.output();
	cout << Array.midArifSum() << " is a sum of mid ariphmeticals" << "\n";
	Array.input();
	Array.output();
	Array.bubblesort(4);
	Array.output();
	cout << Array.midArifSum() << " is a sum of mid ariphmeticals" << "\n";
	return 0;
}