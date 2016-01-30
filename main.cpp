/*
Author: Rosa Tung
Date Created: 1.19.16
Date modified: 1.19.16
Overview:
Read in input file of format [x, ...z] on each line and output max sub array into MSS_Results.txt
*/

#include "stdafx.h"

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

	//get filename
	cout << "Enter txt filename, don't put extension." << endl;
	cin >> fileName;

	//extract parent arrays from file
	extractLines(readFile, fileName, myLines);
	cout << myLines.size() << endl;
	/**make result file**/
	writeFile.open("Change.txt");

	/*************	Algorithm 1 *******************/
	//extract integers from arrays, pass through function and write to output file
	//cout << "before extract" << endl;
	for (int place = 0; place < myLines.size(); place += 2) {
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place + 1, A);
		//cout << "feeding to alg" << endl;
		for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it){
			int amount = *it;
			int min_coin = changeSlow(amount, myCoins);
			cout << "Algorithm 1 min_coins = " << min_coin << endl;
			writeFile << min_coin << endl;
			writeFile << endl;
		}
		
		/* * * * * * * * * * * * * * * * clock * * * * * * * * * * * * * * * *
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		cout << "Time: " << time_span1.count() <<  endl;
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
		myCoins.clear();
		A.clear();
	}

	cout << "" << endl;

	/*************	Algorithm 2 *******************/
	//extract integers from arrays, pass through function and write to output file
	//cout << "before extract" << endl;
	for (int place = 0; place < myLines.size(); place += 2) {
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place + 1, A);
		//cout << "feeding to alg" << endl;
		for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
			int amount = *it;
			int min_coin = changeGreedy(myCoins, amount);
			cout << "Algorithm 2 min_coins = " << min_coin << endl;
			writeFile << min_coin << endl;
			writeFile << endl;
		}

		/* * * * * * * * * * * * * * * * clock * * * * * * * * * * * * * * * *
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		cout << "Time: " << time_span1.count() <<  endl;
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
		myCoins.clear();
		A.clear();
	}

	cout << "" << endl;


	/**close result file**/
	writeFile.close();



	return 0;
}