#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void PrintFileContent(const string& FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);// read Mode 

	if (!MyFile.is_open())
	{
		cout << "Error : Could not open the file\n";
		return;
	}

	string Line;

	while (getline(MyFile, Line))
	{
		cout << Line << endl;
	}

	MyFile.close();
}

void LoadDataFromFileToVector(const string& FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);// read Mode

	if (!MyFile.is_open())
	{
		cout << "Error : Could not open the file\n";
		return;
	}

	string Line;

	while (getline(MyFile, Line))
	{
		vFileContent.push_back(Line);
	}

	MyFile.close();

}

void SaveVectorToFile(const string& FileName, const vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);// Write Mode

	if (!MyFile.is_open())
	{
		cout << "Error : Could not open the file\n";
		return;
	}

	for (const string& Line : vFileContent)
	{
		MyFile << Line << endl;
	}

	MyFile.close();

}

void DeleteRecordFromFile(const string& FileName, const string& Record)
{
	vector <string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	vector <string> vUpdatedFile;

	for (const string& Line : vFileContent)
	{
		if (Line != Record)
		{
			vUpdatedFile.push_back(Line);
		}
	}

	SaveVectorToFile(FileName, vUpdatedFile);
}

int main()
{
	cout << "File Content Before Delete.\n";
	PrintFileContent("MyFile.txt");

	DeleteRecordFromFile("MyFile.txt", "Lama");

	cout << "\n\nFile Content After Delete.\n";
	PrintFileContent("MyFile.txt");

	return 0;
}
