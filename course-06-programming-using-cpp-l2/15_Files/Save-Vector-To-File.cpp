#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
    One flag (ios::out) means “I want to rewrite/replace.”
    Another flag (ios::app) means “I want to keep everything and just add more.”

    That function is supposed to rewrite the whole file after modifying the vector (removing records).
    If you opened with ios::app, it would just keep adding the updated lines at the end,
    and the old (deleted) records would still remain in the file.

    👉 So here ios::out (overwrite mode) is correct.
    You only use ios::app when you want to add new data without touching existing content.

    Because after deletion you need to replace the file’s old content with the updated vector.
    If you use append, the old lines stay in the file and the updated lines just get added at the end
    — the deleted record won’t actually be removed.
*/


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
