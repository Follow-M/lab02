#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void print_reversed_string(const string& str);

int main()
{
	ifstream inputFile;
	inputFile.open("input.txt");
	
	
	//error message for file open fail
	if (inputFile.fail())
	{
		cout << "Error opening the file.\n";
		_getch();
		return 1;
	}
	
	ifstream ifs("input.txt");
	
	string input((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

	if (input.empty())
	{
		cout << "File is empty\n";
		_getch();
		return 1;
	}
	else
	{
		cout << "Original text: " << input << "\n";
		print_reversed_string(input);
	}
	inputFile.close();

	_getch();
	return 0;
}

void print_reversed_string(const string& str)
{
	ofstream outputFile;
	outputFile.open("output.txt");

	//error message for file open fail
	if (outputFile.fail())
	{
		cout << "Error opening the file.\n";
		_getch();
	}
	else {

		cout << "\n\nReversed text: ";
		for (string::const_reverse_iterator it = str.rbegin(); it != str.rend(); ++it)
		{
			cout << *it;
			outputFile << *it;
		}
		cout << "\n";
		outputFile << "\n";

		outputFile.close();
	}

}
