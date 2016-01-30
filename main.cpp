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

int main() {
	ifstream readFile;
	ofstream writeFile;
	string fileName;

	vector <string> myLines;
	vector <int> myCoins;
	vector <int> A;
	vector<vector<int>> table;
<<<<<<< HEAD

=======
	
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
	//get filename
	cout << "Enter txt filename, don't put extension." << endl;
	cin >> fileName;

	//extract parent arrays from file
	extractLines(readFile, fileName, myLines);
	//cout << myLines.size() << endl;
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
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			int min_coin = changeSlow(amount, myCoins);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		    cout << "Time: " << time_span1.count() <<  endl;
			cout << "Algorithm 1 min_coins = " << min_coin << endl;
			writeFile << min_coin << endl;
			writeFile << endl;
		}

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
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			vector <int>  results = changeGreedy(myCoins, amount);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		    cout << "Time: " << time_span1.count() <<  endl;
			cout << "Algorithm 2 min_coins = " << results[results.size()-1] << endl;
			writeFile << results[results.size()-1] << endl;
			writeFile << endl;
		}

		myCoins.clear();
		A.clear();
	}

	cout << "" << endl;
	/*************	Algorithm 3 *******************/
	//extract integers from arrays, pass through function and write to output file
	for (int place = 0; place<myLines.size(); place+=2){
		extractInts(myLines, place, myCoins);
		extractInts(myLines, place+1, A);
<<<<<<< HEAD
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		table = changedp(myCoins, A);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		    cout << "Time: " << time_span1.count() <<  endl;
=======
		table = changedp(myCoins, A);
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
		cout << "Algorithm 3 min_coins = " << table[myCoins.size()-1][A[0]] << endl;
		//getChangeDP(myCoins.size()-1, A[0], myCoins, table, writeFile);

		table.clear();
		myCoins.clear();
		A.clear();
	}

	/**close result file**/
	writeFile.close();



	return 0;
}
