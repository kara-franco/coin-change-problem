#include "stdafx.h"
#include "algos.h"
#include <vector>
#include <algorithm>

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