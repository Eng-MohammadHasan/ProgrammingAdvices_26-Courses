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

// Converts any number recursively
string ConvertNumberToTextRecursive(unsigned long long Number)
{
	if (Number == 0)
		return "";

	if (Number < 20)
		return OneToNineteen[Number] + " ";

	if (Number < 100)
		return Tens[Number / 10] + " " + ConvertNumberToTextRecursive(Number % 10);

	if (Number < 1000)
		return OneToNineteen[Number / 100] + " " + Hundred + " " + ConvertNumberToTextRecursive(Number % 100);

	// Find the largest scale
	unsigned long long scaleValue;
	string scaleName;
	if (Number < 1000000) { scaleValue = 1000; scaleName = "Thousand "; }
	else if (Number < 1000000000) { scaleValue = 1000000; scaleName = "Million "; }
	else { scaleValue = 1000000000; scaleName = "Billion "; }

	return ConvertNumberToTextRecursive(Number / scaleValue) + scaleName + ConvertNumberToTextRecursive(Number % scaleValue);
}

int main()
{
	unsigned long long Number = ReadPositiveIntNumber();

	if (Number == 0)
		cout << "Zero" << endl;
	else
		cout << ConvertNumberToTextRecursive(Number) << endl;

	system("pause>0");
	return 0;
}