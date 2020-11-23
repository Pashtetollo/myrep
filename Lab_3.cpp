#define poryadok (int) 9
#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,b;
	int arr[poryadok][poryadok] = { 0 };
	if (poryadok % 2 != 0)
	{
		i = poryadok / 2; // Знаходження точки відліку для непарного порядку
		j = poryadok / 2;
	}
	else
	{
		i = ceil(poryadok / 2) - 1;  // знаходження для парного порядку
		j = ceil(poryadok / 2);
	}
	int n = -1;
	int m = 1;
	scanf_s("%i", &arr[i][j]);
	for (int it_2 = 0; it_2 < poryadok - 1; it_2++)	    // цикл для збільшення кількості виведення елементів в ряд чи стовпець, зміна напряму руху спіралі
	{
		int k, l = 0;
		for (int iterate = 1; iterate <= m; iterate++) // задання елемегтів по вертикалі
		{
			k = pow(-1, m) * iterate;
			scanf_s ("%i", &b);
			arr[i - k][j] = b;
		}
		i = i - n; //перенесення точки відліку
		for (int iterate_2 = 1; iterate_2 <= m; iterate_2++) // задання по горизонталі
		{
			k = pow(-1, m) * iterate_2;
			scanf_s("%i", &b);
			arr[i][j + k] = b;
		}
		j = j + n; //перенесення точки відліку
		m++;
		n = pow(-1, m) * m;  // зміна знаку та довжини виводу
	}
	if (poryadok % 2 == 0)					// виправлення останнього стовпчика
	{
		for (i = poryadok - 1; i > 0; i--)
		{
			scanf_s("%i", &arr[i - 1][0]);
		}
	}
	else
	{
		for (i = 1; i < poryadok; i++)
		{
			scanf_s("%i", &arr[i][poryadok - 1]);
		}
	}

	i, j = 0;
	int k = 0;

	for (i = 0; i < poryadok; i++) // вивід
	{
		for (j = 0; j < poryadok; j++)
		{
			printf("%3i ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}