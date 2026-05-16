#include <iostream>
#include <string>

using namespace std;

const unsigned short Ten = 10;
const unsigned short Hundred = 100;
const unsigned short Thousand = 1000;
const unsigned int Million = 1000000;
const unsigned int Billion = 1000000000;
const unsigned long long Trillion = 1000000000000;
const unsigned long long Quadrillion = 1000000000000000;

const string UNITS[] =
{
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

const string Tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety" };

string NumberToText(long long  Number)
{
	if (Number < 20) // 0 - 19
	{
		return UNITS[Number];
	}

	if (Number < Hundred) // min: 20 , max: 99
	{
		return Tens[Number / Ten] + " " + NumberToText(Number % Ten);
	}

	if (Number < Thousand) //Section of Hundreds, min: 100 , max: 999
	{
		return UNITS[Number / Hundred] + " Hundred " + NumberToText(Number % Hundred);
	}

	if (Number < Million) // Section of Thousands, min: 1000 , max: 999,999
	{
		return NumberToText(Number / Thousand) + " Thousand, " + NumberToText(Number % Thousand);
	}

	if (Number < Billion) // Section of Millions
	{
		return NumberToText(Number / Million) + " Million, " + NumberToText(Number % Million);
	}

	if (Number < Trillion) // Section of Billions
	{
		return NumberToText(Number / Billion) + " Billion, " + NumberToText(Number % Billion);
	}

	if (Number < Quadrillion) // Section of Trillions
	{
		return NumberToText(Number / Trillion) + " Trillion, " + NumberToText(Number % Trillion);
	}

	else
	{
		return NumberToText(Number / Quadrillion) + " Quadrillion, " + NumberToText(Number % Quadrillion);
	}
}

long long  ReadNumber()
{
	long long  Number;

	cout << "Please Enter a number : ";
	cin >> Number;

	return Number;
}

int main()
{
	long long  Number = ReadNumber();
	cout << NumberToText(Number);

	system("pause>0");
	return 0;
}
