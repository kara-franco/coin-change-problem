#include "algos.h"

#include <iostream>

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

/*****************************************************************************************
* getChangeDP
* Parameters: number of coins, A, table
* Description: finding coins that make up change
******************************************************************************************/
void getChangeDP(int numCoins, int change, vector<int> const &myCoins, vector< vector<int> > &table, ofstream& writeFile){
	int x = numCoins; 
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
				while(testChange < 0){ //move up 
					numCoins = numCoins-1; 
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
			writeFile << tallyMinCoins[k] << ", ";		
		}
	}
	writeFile << table[x][y] << endl;
	numberMinCoins.clear();
	table.clear();
}