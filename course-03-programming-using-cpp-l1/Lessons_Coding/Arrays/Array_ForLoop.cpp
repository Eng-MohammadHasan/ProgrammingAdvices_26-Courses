#include <iostream>
using namespace std;

void ReadArrayData(int Arr1[100], unsigned int& Length)
{
	cout << "How many numbers do you want to enter ? 1 to 100 ?\n";
	cin >> Length; // Here the length is the number of elements in the array ! (size :> )...

	for (int i = 0; i <= Length - 1; i++)
	{
		cout << "Please enter Number " << (i + 1) << " : " << endl;
		cin >> Arr1[i];
	}

}

void PrintArrayData(int Arr1[100], unsigned int Length)
{
	for (int i = 0; i <= Length - 1; i++)
	{
		cout << "Number [" << (i + 1) << "] : " << Arr1[i] << endl;
	}
}

int CalculateArraySum(int Arr1[100], unsigned int Length)
{
	int Sum = 0;

	for (int i = 0; i <= Length - 1; i++)
	{
		Sum += Arr1[i];
	}

	return Sum;
}

float CalculateArrayAverage(int Arr1[100], unsigned int Length)
{
	return (float)CalculateArraySum(Arr1, Length) / Length;
}

int main()
{
	int Arr1[100];
	unsigned int Length = 0;

	ReadArrayData(Arr1, Length);
	PrintArrayData(Arr1, Length);

	cout << "\n*******************************\n";
	/*cout << "Sum = " << CalculateArraySum(Arr1, Length) << endl;
	cout << "Average = " << CalculateArrayAverage(Arr1, Length) << endl;*/


	/* More optimized way (to make the program faster! ) ... ( instead of calling the function to get the average ) ,
	   calling the function means doing more loops to calculate the summation ... :) so we're gonna optimize our program by ---> */

	   // Firstly remove the function ( CalculateArrayAverage() :> )  .... But Becarefull We keep this function , maybe if we wanna use it later on in the program! 
	   // Secondly ... 

	int Summation = CalculateArraySum(Arr1, Length);
	cout << "Sum = " << Summation << endl;
	cout << "Average = " << (float)Summation / Length << endl;

	return 0;
}
