#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void print_reversed_string(const string& str);

int main()
{
	ifstream inputFile;
	inputFile.open("input.txt");
	
	
	//error message for file open fail
	if (inputFile.fail())
		cout << "Error opening the file.\n";
	
	ifstream ifs("input.txt");
	// 
	string input((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

	if (!input.empty())
	{
		cout << "Original text: " << input << "\n";
		print_reversed_string(input);
	}
	inputFile.close();
	
	return 0;
}

void print_reversed_string(const string& str)
{
	ofstream outputFile;
	outputFile.open("output.txt");

	//error message for file open fail
	if (outputFile.fail())
		cout << "Error opening the file.\n";

	cout << "Reversed text: ";
	for (string::const_reverse_iterator it = str.rbegin(); it != str.rend(); ++it)
	{
		cout << *it;
		outputFile << *it;
	}
	cout << "\n";
	outputFile << "\n";

	outputFile.close();

}
