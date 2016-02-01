#include "algos.h"
#include <iostream>
#include <algorithm>

/**********************************************************************************************
* Algorithm 1: changeSlow ()
* Parameters: integer amount to change, vector of denominations, structs of current/best coins
* Description: A function that demonstrates the Divide and Conquer implementation of the
* coin change problem. The function recursively evaluates each denomination to find the
* min number of coins needed to make change of A (amount).
* getChangeSlow is a helper function that prepares the struct that tracks the best coins
* used. getChangeSlow then calls changeSlow, were the recursion takes place to find the 
* best coins to make change for amount A.
***********************************************************************************************/
int getChangeSlow(std::vector<int> &coinArray, int changeVal, std::vector<int> &changeCoinsUsed){
	// minSet will hold the minimum coin amount and a vector of the coins used
	changeStruct minSet;
	// prepare the vector so that it can hold the coins used
	for (int i = 0; i < coinArray.size(); i++){
		minSet.coinsUsed.push_back(0);
	}
	// set the initial amount to "infinity"
	minSet.amount = INT_MAX;
	// currSet will hold the current coin amount and a vector of the coin set currently used
	changeStruct currSet;
	// prepare the vector so that it can hold the coins used
	for (int i = 0; i < coinArray.size(); i++){
		currSet.coinsUsed.push_back(0);
	}
	currSet.amount = 0;
	// call changeSlow, send in the denominations, A and the structs to track the coins used
	changeSlow(changeVal, coinArray, minSet, currSet);
	// place the best set of coins into the var changeCoinsUsed
	for (int i = 0; i < coinArray.size(); i++){
		changeCoinsUsed.push_back(minSet.coinsUsed[i]);
	}
	// return the amount
	return minSet.amount;
}

void changeSlow(int changeVal, std::vector<int> coins, changeStruct &minSet, changeStruct currSet){
	// base case 
	if (changeVal == 0){
		// copmpare minimum amount to the current amount of coins
		if (currSet.amount < minSet.amount){
			minSet.amount = currSet.amount;
			minSet.coinsUsed = currSet.coinsUsed;
		}
		return;
	}
	// if the current set of coins is greater than the minimum break out
	if (currSet.amount > minSet.amount){
		return;
	}
	// traverse through coins, if A is greater than or equal to the denomination at i
	// then recurse to find minimum coins needed
	for (int i = coins.size() - 1; i >= 0; i--){
		if (changeVal >= coins[i]){
			// create new struct that will track the current set of coins in recursion
			changeStruct newSet;
			newSet.amount = currSet.amount + 1;
			newSet.coinsUsed = currSet.coinsUsed;
			newSet.coinsUsed[i]++;
			// call changeSlow with the new A, coins and the structs to track 
			changeSlow(changeVal - coins[i], coins, minSet, newSet);
		}
	}
}

/************************************************
*Author: Sam Nelson                            *
*Date: 30 Jan 2016                             *
*File: greedy.cpp                              *
*params: array of coins(ints),an int to process*
*Description: File takes a sorted(small->large)*
*array and an amount to make change for and    *
*steps through the coins seeing if it can place*
*the largest coin in that amount if it can it  *
*puts as many of those in as it can before     *
*continuing on with the next and so on...its   *
*goal is to use as few coins as possible       *
***********************************************/


std::vector<int> changeGreedy(std::vector<int> availableCoins, int makeChangeFrom)
{
	//number of coins needed
	int numOfCoins = 0;
	//vector to keep track of the coins needed to make change
	int sizeOfvector = availableCoins.size();
	//setup vector of coins used
	vector<int> madeChangeFrom;
	for (int i = 0; i<sizeOfvector; i++)
	{
		madeChangeFrom.push_back(0);
	}

	//in greedy's algo we start with largest number's first to produce
	//minimum amount of coins.
	for (int index = availableCoins.size() - 1; index >= 0; index--)
	{
		//we compare the largest coin with the amount of make change from
		//if coins value is less than that amount then we subtract it
		//and store in an array and repeat as many times as we can.
		//if we were making change for 75 cents this would run 3 times for 3 quarters
		while (availableCoins[index] <= makeChangeFrom)
		{
			//now that we can use that next largest coin
			//we remove it from the amount, increase the counter
			//for that coin, and increase the number of coins used
			//we also update the amount to make change for.
			makeChangeFrom -= availableCoins[index];
			madeChangeFrom[index]++;
			numOfCoins += 1;
		}
	}//end for(int index = availableCoins.size()-1; index >= 0; index--)
	madeChangeFrom.push_back(numOfCoins);

	return madeChangeFrom;
}

/*****************************************************************************************
* changedp
* Parameters: coins, A
* Description: bottom up dynamic programming
******************************************************************************************/
vector< vector<int> > changedp(vector<int> const &myCoins, vector<int> const &A) {
	int change = A[0] + 1;
	int numCoins = myCoins.size();
	int coin = myCoins[0]; //start at the first row
	vector<vector<int>> table(numCoins, vector<int>(change));
	//take care of base row
	for (int y = 0; y<change; y++) {
		if (y<coin) {
			table[0][y] = 0; //exclude, take value from top or set to 0
		}
		else {
			table[0][y] = table[0][y - coin] + 1;//no need to do comparison yet
		}
	}
	//now do the rest starting at the second row
	for (int x = 1; x<numCoins; x++) {
		coin = myCoins[x]; //change coin value we're looking at
		for (int y = 0; y<change; y++) {
			if (y<coin) { //exclude
				table[x][y] = table[x - 1][y]; //take value from top
			}
			else { //include or not?
				if (((table[x][y - coin]) + 1)<(table[x - 1][y])) { //we found better number of coins
					table[x][y] = (table[x][y - coin]) + 1;
				}
				else {
					table[x][y] = table[x - 1][y]; //exclude, the top is better
				}
			}
		}
	}

	return table;
}

/*****************************************************************************************
* getChangeDP
* Parameters: number of coins, A, table
* Description: finding coins that make up change
******************************************************************************************/
void getChangeDP(int numCoins, int change, vector<int> const &myCoins, vector< vector<int> > &table, ofstream& writeFile) {
	int x = numCoins;
	int y = change;
	vector<int> numberMinCoins;
	int testChange;

	//compare left value and top values
	while (numCoins >= 0) {
		if (numCoins == 0) { //get rest of values, we're done
			for (int i = 0; i<table[numCoins][change]; i++) {
				numberMinCoins.push_back(myCoins[numCoins]);
			}
			break;
		}
		else { //we're not done
			if (table[numCoins][change - myCoins[numCoins]]<table[numCoins - 1][change]) { //move to left
				numberMinCoins.push_back(myCoins[numCoins]); //push that number back
				change = change - myCoins[numCoins];
				testChange = change - myCoins[numCoins];
				if (change == 0) {
					break;
				}
				while (testChange < 0) { //move up
					numCoins = numCoins - 1;
					testChange = change - myCoins[numCoins];
				}
			}
			else { //move up
				numCoins = numCoins - 1;
			}
		}
	}

	//tally up all the coins
	vector <int> tallyMinCoins;
	int tally = 0;
	for (int i = 0; i < myCoins.size(); i++) {
		for (int j = 0; j<numberMinCoins.size(); j++) {
			if (numberMinCoins[j] == myCoins[i]) {
				tally++;
			}
		}
		tallyMinCoins.push_back(tally);
		tally = 0;
	}
	writeFile << "[";
	for (int k = 0; k<tallyMinCoins.size(); k++) {
		if (k == tallyMinCoins.size() - 1) {
			writeFile << tallyMinCoins[k] << "]" << endl;
		}
		else {
			writeFile << tallyMinCoins[k] << ", ";
		}
	}
	writeFile << table[x][y] << endl;
	numberMinCoins.clear();
	table.clear();
}