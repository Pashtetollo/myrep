#include <stdio.h>
#include <math.h>
//Хомяков Олександр
int main()
{
    float x = 4.123;
    float y = 2.395;
    printf("result is %f", log(pow(x, 3) + tan(y) + (pow(x + y, 3)) - (x * sin(y + 1.6) / (177 * pow(x, 2)))));
    return 0;
}