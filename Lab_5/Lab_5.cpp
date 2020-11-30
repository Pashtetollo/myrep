#include <iostream>
#include <math.h>
#include "MatrixSum.h"
#include "SortMatrix.h"
#include "MatrixInit.h"
#include "MatrixOutput.h"
using namespace std;
int main()
{
	MatrixInit Myarray = MatrixInit('y');
	output(&Myarray.Arr);
	bubblesort(4, &Myarray.Arr);
	Array.output();
	cout << Array.midArifSum() << " is a sum of mid ariphmeticals" << "\n";
	Array.input();
	Array.output();
	Array.bubblesort(4);
	Array.output();	
	return 0;
	}
	