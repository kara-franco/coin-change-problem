#include "algos.h"

#include <iostream>

/*****************************************************************************************
* Algorithm 1: changeSlow ()
* Parameters: integer amount to change, vector of denominations
* Description: A function that demonstrates the Divide and Conquer implementation of the
* coin change problem. The function recursively evaluates each denomination to find the
* min number of coins needed to make change of A (amount).
******************************************************************************************/
int changeSlow(int amount, vector<int> const coinArray)
{
	//cout << "in alg" << endl;
	if (amount <= 0) {
		return 0;
	}
	int min_coins = (int)INT_MAX;

	for (int i = 0; i < coinArray.size(); i++) {
		//cout << coinArray.size() << endl;
		//cout << "in alg for" << endl;
		if (coinArray[i] <= amount) {
			min_coins = min(min_coins, changeSlow(amount - coinArray[i], coinArray) + 1);
		}
	}
	return min_coins;
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
	for(int i=0;i<sizeOfvector;i++)
    {
        madeChangeFrom.push_back(0);
    }

	//in greedy's algo we start with largest number's first to produce
	//minimum amount of coins.
	for(int index = availableCoins.size()-1; index >= 0; index--)
	{
	    //we compare the largest coin with the amount of make change from
	    //if coins value is less than that amount then we subtract it
	    //and store in an array and repeat as many times as we can.
	    //if we were making change for 75 cents this would run 3 times for 3 quarters
		while(availableCoins[index] <= makeChangeFrom)
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
vector< vector<int> > changedp(vector<int> const &myCoins, vector<int> const &A){
	int change = A[0] + 1;
	int numCoins = myCoins.size();
	int coin = myCoins[0]; //start at the first row
	vector<vector<int>> table(numCoins, vector<int>(change));
	//take care of base row
	for(int y = 0; y<change; y++){
		if(y<coin){
			table[0][y] = 0; //exclude, take value from top or set to 0
		}
		else{
			table[0][y] = table[0][y-coin] + 1;//no need to do comparison yet
		}
	}
	//now do the rest starting at the second row
	for(int x = 1; x<numCoins; x++){
		coin = myCoins[x]; //change coin value we're looking at
		for(int y = 0; y<change; y++){
			if(y<coin){ //exclude
				table[x][y] = table[x-1][y]; //take value from top
			}
			else{ //include or not?
				if(((table[x][y-coin])+1)<(table[x-1][y])){ //we found better number of coins
					table[x][y] = (table[x][y-coin])+1;
				}
				else{
					table[x][y] = table[x-1][y]; //exclude, the top is better
				}
			}
		}
	}

	return table;
}

<<<<<<< HEAD
=======
	return numOfCoins;
}

/*****************************************************************************************
* changedp
* Parameters: coins, A
* Description: bottom up dynamic programming
******************************************************************************************/
vector< vector<int> > changedp(vector<int> const &myCoins, vector<int> const &A){ 
	int change = A[0] + 1;
	int numCoins = myCoins.size();
	int coin = myCoins[0]; //start at the first row
	vector<vector<int>> table(numCoins, vector<int>(change)); 
	//take care of base row
	for(int y = 0; y<change; y++){
		if(y<coin){
			table[0][y] = 0; //exclude, take value from top or set to 0
		}
		else{
			table[0][y] = table[0][y-coin] + 1;//no need to do comparison yet
		}
	}
	//now do the rest starting at the second row  
	for(int x = 1; x<numCoins; x++){
		coin = myCoins[x]; //change coin value we're looking at
		for(int y = 0; y<change; y++){
			if(y<coin){ //exclude
				table[x][y] = table[x-1][y]; //take value from top
			}
			else{ //include or not?
				if(((table[x][y-coin])+1)<(table[x-1][y])){ //we found better number of coins
					table[x][y] = (table[x][y-coin])+1;
				}
				else{
					table[x][y] = table[x-1][y]; //exclude, the top is better
				}
			}
		}
	}		

	return table;
}

>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
/*****************************************************************************************
* getChangeDP
* Parameters: number of coins, A, table
* Description: finding coins that make up change
******************************************************************************************/
void getChangeDP(int numCoins, int change, vector<int> const &myCoins, vector< vector<int> > &table, ofstream& writeFile){
<<<<<<< HEAD
	int x = numCoins;
=======
	int x = numCoins; 
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
	int y = change;
	vector<int> numberMinCoins;
	int testChange;

	//compare left value and top values
	while(numCoins>=0){
		if(numCoins == 0){ //get rest of values, we're done
			for(int i = 0; i<table[numCoins][change]; i++){
				numberMinCoins.push_back(myCoins[numCoins]);
			}
			break;
		}
		else{ //we're not done
			if(table[numCoins][change-myCoins[numCoins]]<table[numCoins-1][change]){ //move to left
				numberMinCoins.push_back(myCoins[numCoins]); //push that number back
				change = change-myCoins[numCoins];
				testChange = change-myCoins[numCoins];
				if(change == 0){
					break;
				}
<<<<<<< HEAD
				while(testChange < 0){ //move up
					numCoins = numCoins-1;
=======
				while(testChange < 0){ //move up 
					numCoins = numCoins-1; 
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
					testChange = change-myCoins[numCoins];
				}
			}
			else{ //move up
				numCoins = numCoins-1;
			}
		}
	}

	//tally up all the coins
	vector <int> tallyMinCoins;
	int tally = 0;
	for(int i = 0; i < myCoins.size(); i++){
		for(int j = 0; j<numberMinCoins.size(); j++){
			if(numberMinCoins[j] == myCoins[i]){
				tally++;
			}
		}
		tallyMinCoins.push_back(tally);
		tally = 0;
	}
	writeFile << "[";
	for(int k = 0; k<tallyMinCoins.size(); k++){
		if(k == tallyMinCoins.size()-1){
			writeFile << tallyMinCoins[k] << "]" << endl;
		}
		else{
<<<<<<< HEAD
			writeFile << tallyMinCoins[k] << ", ";
=======
			writeFile << tallyMinCoins[k] << ", ";		
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
		}
	}
	writeFile << table[x][y] << endl;
	numberMinCoins.clear();
	table.clear();
<<<<<<< HEAD
}
=======
}
>>>>>>> 890e2da46204b0712e0a6b84f3896cc402cc345c
