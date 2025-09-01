#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//void SaveVetorToFile(string FileName, const vector <string>& vFileContent)
void SaveVetorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);// Open file in write mode (overwrites if it exists)

	if (MyFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			// Skip empty strings
			if (Line != "") // I want to assume that , if the vector has an empty item (string) , don't store it in file
			{
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}

}

int main()
{
	vector <string> vFileContent{ "Ali" , "Shadi" , "Maher" , "Fadi" , "Lama" };

	SaveVetorToFile("MyFile.txt", vFileContent);

	return 0;
}
