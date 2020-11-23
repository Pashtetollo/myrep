// Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>;
#include <math.h>;

void case_1 (float* x)
	{
	printf("x = %f, equasion_1 result = %f\n", *x, log(fabs(log10(*x) + (log(*x) / log(3)))));
	}
void case_2(float* x)
	{
	printf("x = %f, equasion_2 result = %f\n", *x, cos(sin(pow(*x, 2))));
	}
void case_3(float* x)
{

	float k = 1.0 / 7;
	float x_pow = pow(*x, 3) + 0.5;
	float powka = pow(x_pow, k);
	printf("x = %f, equasion_3 result = %f\n",*x, powka);
}
int main()
{
	printf("which program to execute?\nPrint 1 for prog_1\nPrint 2 for prog_2\nPrint e  to exit\n");
	char decider;
	scanf_s("%c", &decider);
	switch (decider)
	{
	case '1':
	{
		float start = 0.3;
		float end = 0.9;
		float h = 0.05;
		for (float i = start; i <= end+0.01; i += h)
		{
			if (i <= 0)
			{
				printf("invalid boundaries");
			}
			else
			{
				if (i <= 0.4)
				{
					case_1(&i);
				}
				else
				{
					if (i < 0.6)
					{
						case_2(&i);
					}
					else
					{
						case_3(&i);
					}
				}
			}
		}
		printf("program_1 is finished\n");
		break;
	}
	case '2':
	{
		float d = 0.001;
		float h = 0.05;
		float start = 0;
		float end = 0.5;
		for (float i = start; i <= end; i += h)
		{
			float sum = 0;
			float n = 1;
			for (;;)
			{
				float sum_1 = 0;
				sum_1 = pow((-1), (n + 1)) * pow(i, n) / n;
				if (fabs(sum_1) < d)
				{
					break;
				}
				n++;
				sum += sum_1;
			}
			printf("x = %f\nequasion_sum = %f\n", i, sum);
		}
		printf("program_2 is finished\n");
		break;
	}
	case 'e':
	{
		printf("bye:(\n");
	}
	}
}