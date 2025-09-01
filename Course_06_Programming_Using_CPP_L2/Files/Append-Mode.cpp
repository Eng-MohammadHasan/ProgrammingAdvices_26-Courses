#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream MyFile;

	// MyFile.open("MyFile.txt", ios::app);
	// Opens in append mode only , ( does NOT create the file if it doesn't exist) 


	//Better approach:
	// ios::out | ios::app -> appends if file exist, creates the file if it doesn't
	MyFile.open("MyFile.txt", ios::out | ios::app); // append Mode
	if (MyFile.is_open())
	{
		MyFile << "Hi, this is a new line\n";
		MyFile << "Hi, this is another new line\n";
		MyFile.close();
	}

	/*
		The | symbol in C++ is the bitwise OR operator. When used between two operands,
		it performs a bitwise OR operation on their individual bits.

		In the context of file opening flags like ios::out | ios::app, the | operator combines the flags bitwise.
		Let's break it down:

		ios::out is typically represented by the bit pattern 0001.
		ios::app is typically represented by the bit pattern 1000.

		When you perform the bitwise OR operation (|) between ios::out and ios::app, it combines these bit patterns:

		ios::out (0001)
		| ios::app (1000)
		-------------
		Result   (1001)
		Save to grepper
		So, the resulting flag indicates both ios::out and ios::app are enabled,
		which means the file is opened for output and any output operations will append to the end of the file.

	*/

	return 0;
}
