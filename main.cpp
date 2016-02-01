/*
Author: Rosa Tung
Date Created: 1.19.16
Date Last Modified: 1.31.16
Overview:
Read in input file of format [x, ...z] on every other line, with an integer below each [x, ...z].
Output minimum coins used with minimum coin total into [inputfile name]change.txt
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

int main() {
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
	//cout << myLines.size() << endl;
	/**make result file**/
	writeFile.open(fileName + "change.txt");

	/*************	Algorithm 1 *******************/
	//extract integers from arrays, pass through function and write to output file
	writeFile << "Algorithm 1" << endl;
	for (int place = 0; place < myLines.size(); place += 2) {
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place + 1, A);
			for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it){
				int amount = *it;
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				std::vector<int> returnCoinsUsed;
				int min_coin = getChangeSlow(myCoins, amount, returnCoinsUsed);
				//cout << returnCoinsUsed[returnCoinsUsed.size()] << endl;
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
				//writeFile << time_span1.count() <<  endl;
				writeFile << "[";
				for (int k = 0; k<returnCoinsUsed.size(); k++) {
					if (k == returnCoinsUsed.size() - 1) {
						writeFile << returnCoinsUsed[k] << "]" << endl;
					}
					else {
						writeFile << returnCoinsUsed[k] << ", ";
					}
				}
				//cout << min_coin << endl;
				writeFile << min_coin << endl;
			}
		myCoins.clear();
		A.clear();
	}

	writeFile << "" << endl;
	/*************	Algorithm 2 *******************/
	//extract integers from arrays, pass through function and write to output file
	writeFile << "Algorithm 2" << endl;
	for (int place = 0; place < myLines.size(); place += 2) {
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place + 1, A);
		//cout << "feeding to alg" << endl;
		for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
			int amount = *it;
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			vector <int>  results = changeGreedy(myCoins, amount);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
			//writeFile << time_span1.count() << endl;
			writeFile << "[";
			for (int k = 0; k<results.size() - 1; k++) {
				if (k == results.size() - 2) {
					writeFile << results[k] << "]" << endl;
				}
				else {
					writeFile << results[k] << ", ";
				}
			}
			writeFile << results[results.size()-1] << endl; 
		}
	
		myCoins.clear();
		A.clear();
	}
	writeFile << "" << endl; 
	/*************	Algorithm 3 *******************/
	//extract integers from arrays, pass through function and write to output file
	writeFile << "Algorithm 3" << endl;
	for (int place = 0; place<myLines.size(); place += 2) {
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place + 1, A);
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		table = changedp(myCoins, A);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		//writeFile << time_span1.count() << endl;
		//writeFile << table[myCoins.size()-1][A[0]] << endl;
		getChangeDP(myCoins.size()-1, A[0], myCoins, table, writeFile);

		table.clear();
		myCoins.clear();
		A.clear();
	}

	/**close result file**/
	writeFile.close();

	return 0;
}
