#include "filter.h"
#include <iostream>

/*****************************************************************
* openFile()
* Parameters: readfile and filename(string)
* Description: This function opens a file with the name that
* the user gives and will give a message to the user if the file
* was opened or not.
*****************************************************************/
int openFile(ifstream& readFile, string fileName) {
	//opens file, puts .txt at the end of it
	readFile.open((fileName + ".txt").c_str());

	if (!readFile) {
		cout << fileName << ".txt could not be opened." << endl;
		cout << " " << endl;
		return 1;
	}
	else {
		cout << fileName << ".txt read!" << endl;

		return 0;
	}
}

/*********************************************************************
* extractLines()
* Parameters: readfile, filename and array to store integers from files
* Description: A function that extracts the lines from the file and
* ignores the three empty lines at the end of ther file.
************************************************************************/
void extractLines(ifstream& readFile, string fileName, vector<string> &myArrays) {
	//opens file
	openFile(readFile, fileName);

	string line;

	//don't know length of a line or how many lines before i start to parse it, so use a vector
	while (getline(readFile, line)) {
		if (line.size() != 0)
		{
			myArrays.push_back(line);
			// cout << line << endl;
		}
	}

	readFile.close();
}

/**********************************************************************************
* extractInts()
* Parameters: array, row number, array to store
* Description: A function that extracts the integers from the string  line,
* it then stores the array of numbers in the dynamic array.
********************************************************************************/
void extractInts(vector<string> &myArrays, int row, vector<int> &paArray) {//also can check if character is numeric
	string line = myArrays[row];
	//cout << "string: " << line << endl;
	string number;
	int num;
	int sign = 1; //negative or positive number

	if (row % 2 != 0) //get the value of A
	{
		//cout << "getting value of A" << endl;
		for (int place = 0; place<line.size(); place++)
		{
			number.push_back(line[place]);
		}
		num = atoi(number.c_str());
		paArray.push_back(num);

	}
	else //get the value of myCoins
	{
		//cout << "getting the array" << endl;
		//go one character at a time
		for (int place = 1; place < line.size(); place++) {
			if (line[place] == ',' || line[place] == ']') {
				num = atoi(number.c_str());
				if (sign == -1) {
					num *= -1;
				}
				paArray.push_back(num); //pop it into vector

				number.clear();
				sign = 1;
			}
			else if (line[place] == '-') {
				sign = -1;
			}
			else if (line[place] == ' ') { //skip over
			}
			else {
				number.push_back(line[place]);
			}
		}
	}

	//cout << "extracted ints" << endl;
	/* for (unsigned int place = 0; place < paArray.size(); place++) {
	cout << paArray[place] << " ";
	}
	cout << endl;*/
}

/**************************************************************************
* outputFile()
* Parameters: array, place, array and indeces
* Description: A function that outputs the solved arrays into file,
* writing them with the correct use of brackets and commas.
****************************************************************************/
void outputFile(vector<string> const &myArrays, int const row, vector<int> const &paArray, int const &leftIdx, int const &rightIdx, ofstream& writeFile) {
	writeFile << myArrays[row] << endl;
	writeFile << "[";													//cout << "outputting" << endl;
	for (int place = leftIdx; place<rightIdx + 1; place++) {
		if (place == rightIdx) {
			writeFile << paArray[place];
		}
		else {
			writeFile << paArray[place] << ", ";
		}
	}
	writeFile << "]" << endl;
}
