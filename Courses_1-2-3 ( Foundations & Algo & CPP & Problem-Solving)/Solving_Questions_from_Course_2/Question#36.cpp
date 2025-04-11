#include <iostream>
using namespace std;

void ReadNumbers(float Numbers[2])
{
	cout << "Please Enter Number 1 : \n";
	cin >> Numbers[0];

	cout << "Please Enter Number 2 : \n";
	cin >> Numbers[1];
}

void ReadOperationType(char& OperationType)
{
	cout << "Please Enter one of these Operations ... ( \" + \" , \" - \" ,\" * \" , \" / \" ) : " << endl;
	cin >> OperationType;
}

float CalculateResult(float Numbers[2], char OperationType)
{
	if (OperationType == '+')
	{
		return Numbers[0] + Numbers[1];
	}
	else if (OperationType == '-')
	{
		return Numbers[0] - Numbers[1];
	}
	else if (OperationType == '*')
	{
		return Numbers[0] * Numbers[1];
	}
	else if (OperationType == '/')
	{
		return Numbers[0] / Numbers[1];
	}
}

int main()
{
	float Numbers[2];
	char OperationType;

	ReadNumbers(Numbers);
	ReadOperationType(OperationType);
	cout << "\nThe Result = " << CalculateResult(Numbers, OperationType) << endl;

	return 0;
}
