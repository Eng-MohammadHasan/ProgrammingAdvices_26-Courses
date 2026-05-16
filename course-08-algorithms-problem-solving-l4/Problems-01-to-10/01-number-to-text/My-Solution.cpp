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
	"", "",
	"Twenty",
	"Thirty",
	"Forty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety"
};

string Scales[] = { "", "Thousand", "Million", "Billion" };
string Hundred = "Hundred";

unsigned long long ReadPositiveIntNumber()
{
	unsigned long long Number;
	cout << "Enter a Number? ";
	cin >> Number;
	return Number;
}

void PrintNumberAtPlace(string NumberValue)
{
	if (!NumberValue.empty())
		cout << NumberValue << " ";
}

void ConvertNumberToText(unsigned long long Number)
{
	if (Number == 0)
	{
		cout << "Zero";
		return;
	}

	if (Number <= 19)
	{
		PrintNumberAtPlace(OneToNineteen[Number]);
	}
	else if (Number >= 20 && Number <= 99)
	{
		int FirstDigit = static_cast<int>(Number / 10);
		PrintNumberAtPlace(Tens[FirstDigit]);

		unsigned long long Remainder = Number % 10;
		if (Remainder != 0)
		{
			ConvertNumberToText(Remainder);
		}
	}
	else if (Number >= 100 && Number <= 999)
	{
		int FirstDigit = static_cast<int>(Number / 100);
		PrintNumberAtPlace(OneToNineteen[FirstDigit] + " " + Hundred);

		unsigned long long Remainder = Number % 100;
		if (Remainder != 0)
		{
			ConvertNumberToText(Remainder);
		}
	}
	else if (Number >= 1000 && Number <= 999999)
	{
		// Determine thousands part
		unsigned long long Thousands = Number / 1000;
		unsigned long long Remainder = Number % 1000;

		if (Thousands <= 19)
		{
			PrintNumberAtPlace(OneToNineteen[Thousands] + " " + Scales[1]);
		}
		else if (Thousands >= 20 && Thousands <= 99)
		{
			int TensDigit = static_cast<int>(Thousands / 10);
			PrintNumberAtPlace(Tens[TensDigit]);

			int Units = static_cast<int>(Thousands % 10);
			if (Units != 0)
				PrintNumberAtPlace(OneToNineteen[Units]);

			PrintNumberAtPlace(Scales[1]);
		}
		else if (Thousands >= 100 && Thousands <= 999)
		{
			int HundredsDigit = static_cast<int>(Thousands / 100);
			PrintNumberAtPlace(OneToNineteen[HundredsDigit] + " " + Hundred);

			int TensUnits = static_cast<int>(Thousands % 100);
			if (TensUnits != 0)
				ConvertNumberToText(TensUnits);

			PrintNumberAtPlace(Scales[1]);
		}

		if (Remainder != 0)
			ConvertNumberToText(Remainder);
	}
	else if (Number >= 1000000 && Number <= 999999999)
	{
		unsigned long long Millions = Number / 1000000;
		unsigned long long Remainder = Number % 1000000;

		if (Millions <= 19)
			PrintNumberAtPlace(OneToNineteen[Millions] + " " + Scales[2]);
		else
		{
			int TensDigit = static_cast<int>(Millions / 10);
			PrintNumberAtPlace(Tens[TensDigit]);

			int Units = static_cast<int>(Millions % 10);
			if (Units != 0)
				PrintNumberAtPlace(OneToNineteen[Units]);

			PrintNumberAtPlace(Scales[2]);
		}

		if (Remainder != 0)
			ConvertNumberToText(Remainder);
	}
	else if (Number >= 1000000000 && Number <= 999999999999)
	{
		unsigned long long Billions = Number / 1000000000;
		unsigned long long Remainder = Number % 1000000000;

		if (Billions <= 19)
			PrintNumberAtPlace(OneToNineteen[Billions] + " " + Scales[3]);
		else
		{
			int TensDigit = static_cast<int>(Billions / 10);
			PrintNumberAtPlace(Tens[TensDigit]);

			int Units = static_cast<int>(Billions % 10);
			if (Units != 0)
				PrintNumberAtPlace(OneToNineteen[Units]);

			PrintNumberAtPlace(Scales[3]);
		}

		if (Remainder != 0)
			ConvertNumberToText(Remainder);
	}
}

int main()
{
	unsigned long long Number = ReadPositiveIntNumber();
	ConvertNumberToText(Number);
	cout << endl;
	system("pause>0");
	return 0;
}