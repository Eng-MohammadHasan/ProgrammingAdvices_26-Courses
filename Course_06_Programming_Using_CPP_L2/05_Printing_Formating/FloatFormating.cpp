#include <iostream>
using namespace std;

int main()
{
	const float PI = 3.14159265;

	//Precision Specification
	printf("Precision specification of %.*f\n", 1, PI);
	printf("Precision specification of %.*f\n", 2, PI);
	printf("Precision specification of %.*f\n", 3, PI);
	printf("Precision specification of %.*f\n", 4, PI);

	float x = 7.0, y = 9.0;
	printf("\nThe float division is : %.3f / %.3f = %.3f \n\n", x, y, x / y);


	//This will be more complicated 
	float a = 10.97134, b = 9, c = 5.311135;

	printf("Number : %.*f \n", 3, a);
	printf("Result of %.*f / %.*f = %.*f \n\n", 3, a, 3, b, 2, a / b);

	//But this way is much easier
	double d = 12.45;
	printf("The double value is : %.3f \n", d);
	printf("The double value is : %.4f \n", d);

	return 0;
}
