/*
Author: Rosa Tung
Date Created: 1.19.16
Date modified: 1.19.16
Overview:
Read in input file of format [x, ...z] on each line and output max sub array into MSS_Results.txt
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

#include "filter.h"
#include "algos.h"

int main(){
	ifstream readFile;
	ofstream writeFile;
	string fileName;

	vector <string> myLines;
	vector <int> myCoins;
	vector <int> A; 
	vector<vector<int>> table;
	//get filename
	cout << "Enter txt filename, don't put extension." << endl;
	cin >> fileName;

	//extract parent arrays from file
	extractLines(readFile, fileName, myLines);
	
	/**make result file**/
	writeFile.open("table.txt");
	//extract integers from arrays, pass through function and write to output file
	for (int place = 0; place<myLines.size(); place+=2){
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place+1, A);
		table = changedp(myCoins, A);
		getChangeDP(myCoins.size()-1, A[0], myCoins, table, writeFile);

		table.clear();
		myCoins.clear();
		A.clear();
	}
	/**close result file**/
	writeFile.close();

	

	return 0;
}
