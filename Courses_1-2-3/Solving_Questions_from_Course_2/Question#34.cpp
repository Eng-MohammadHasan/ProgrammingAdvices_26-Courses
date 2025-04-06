#include <iostream>
using namespace std;

void ReadTotalSales(unsigned int& TotalSales)
{
	cout << "Please Enter Total Sales : " << endl;
	cin >> TotalSales;
}

float CalculateCommission(unsigned int TotalSales)
{
	if (TotalSales >= 1000000)
	{
		return TotalSales * 0.01;
	}
	else if (TotalSales >= 500000 )
	{
		return TotalSales * 0.02;
	}
	else if (TotalSales >= 100000 )
	{
		return TotalSales * 0.03;
	}
	else if (TotalSales >= 50000 )
	{
		return TotalSales * 0.05;
	}
	else
	{
		return TotalSales;
	}
}

int main()
{
	unsigned int TotalSales;

	ReadTotalSales(TotalSales);
	cout << "The total value = " << CalculateCommission(TotalSales);

	return 0;

}
