#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* The getline built in function ..
	//Streams have a bool conversion !!!!!!!!!!!!!
		 istream& getline(istream& in, string& str)
	{

		str.clear();
		char ch;

		while (in.get(ch))           // read one char at a time
		{
			if (ch == '\n')          // stop if newline
				break;
			str.push_back(ch);       // add char to string
		}

		// if nothing was read and we hit EOF → set failbit
		if (str.empty() && in.eof())
			in.setstate(ios::failbit);

		return in;   // allows using it directly in while(condition)

 		//If str isn’t empty but EOF is reached right after that line, here’s what happens:
		//The if (str.empty() && in.eof()) check does not run (because str isn’t empty).
		//The stream in still has eofbit set automatically by .get() when it hit EOF.
		//So in is returned with eofbit = true, but failbit is not set.

		//👉 Meaning: the line is returned correctly, but on the next call to getline, the stream will evaluate as false (because it’s already at EOF).

	}

*/

void PrintFileContent(string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);//read Mode

	if (MyFile.is_open())
	{
		string Line;

		// getline(MyFile, Line), automatically reads one full line at a time and moves the file pointer to the start of the next line.

		 // getline(MyFile, Line) simplified behavior:
			// 1. Reads characters from file until newline '\n' or EOF.
			// 2. Stores them in 'Line' (newline not included).
			// 3. Moves file pointer just after the newline,
			//    so next getline starts at the next line.
			// 4. If it cannot read (EOF or error), it sets failbit.

			// Important:
			// getline returns 'istream&' (a reference to the stream).
			// The stream has a built-in conversion to bool:
			//   true  → last read was successful.
			//   false → last read failed (EOF or error).
			// That’s why while(getline(...)) works:
			// the loop runs while reading is successful,
			// and stops automatically when EOF is reached.
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}

		MyFile << "hi" << endl;

		MyFile.close();
	}
}

int main()
{
	PrintFileContent("MyFile.txt");

	return 0;
}
