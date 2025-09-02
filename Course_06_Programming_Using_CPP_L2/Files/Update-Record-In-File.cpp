#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
		input -->
					Ali
					Maher
					Fadi
					Shadi
					Lama
					Ali
					Mohammad

		output -->
					Omar
					Maher
					Fadi
					Shadi
					Lama
					Omar
					Mohammad


*/

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);// read Mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();
	}
}

//void SaveVectorToFile(string FileName, const vector <string> & vFileContent)
void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);// Write Mode

	if (MyFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}
}

void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
	vector <string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	// don't forget the & (by ref), cuase we will edit on the vector's items
	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = UpdateTo;
		}
	}

	SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);// read Mode 


	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}

		MyFile.close();
	}
}

int main()
{
	cout << "File Content Before Delete.\n";
	PrintFileContent("MyFile.txt");

	UpdateRecordInFile("MyFile.txt", "Ali", "Omar");

	cout << "\n\nFile Content After Delete.\n";
	PrintFileContent("MyFile.txt");

	return 0;
}
