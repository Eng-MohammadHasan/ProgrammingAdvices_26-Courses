#include <iostream>
#include <string>

using namespace std;

string OneToNineteen[20] =
{
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string Tens[10] =
{
	"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string Scales[] = { "", "Thousand", "Million", "Billion" };
string Hundred = "Hundred";

// Reads a positive number from the user
unsigned long long ReadPositiveIntNumber()
{
	unsigned long long Number;
	cout << "Enter a Number? ";
	cin >> Number;
	return Number;
}

// Converts a number from 1 to 999 to text (single chunk)
string ConvertHundreds(unsigned long long Number)
{
	string result;

	if (Number >= 100)
	{
		int HundredsDigit = Number / 100;
		result += OneToNineteen[HundredsDigit] + " " + Hundred + " ";
		Number %= 100;
	}

	if (Number >= 20)
	{
		int TensDigit = Number / 10;
		result += Tens[TensDigit] + " ";
		Number %= 10;
	}

	if (Number > 0)
	{
		result += OneToNineteen[Number] + " ";
	}

	return result;
}

// Converts any number to text by splitting into chunks (Billion, Million, Thousand, Hundreds)
string ConvertNumberToText(unsigned long long Number)
{
	if (Number == 0) return "Zero";

	string result;

	unsigned long long Billions = Number / 1000000000;
	if (Billions > 0)
	{
		result += ConvertHundreds(Billions) + "Billion ";
		Number %= 1000000000;
	}

	unsigned long long Millions = Number / 1000000;
	if (Millions > 0)
	{
		result += ConvertHundreds(Millions) + "Million ";
		Number %= 1000000;
	}

	unsigned long long Thousands = Number / 1000;
	if (Thousands > 0)
	{
		result += ConvertHundreds(Thousands) + "Thousand ";
		Number %= 1000;
	}

	if (Number > 0)
	{
		result += ConvertHundreds(Number);
	}

	return result;
}

int main()
{
	unsigned long long Number = ReadPositiveIntNumber();

	string Text = ConvertNumberToText(Number);
	cout << Text << endl;

	system("pause>0");
	return 0;
}