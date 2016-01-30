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

/************************************************
<<<<<<< HEAD
*Author: Sam Nelson                            *
*Date: 27 Jan 2016                             *
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
=======
 *Author: Sam Nelson                            *
 *Date: 27 Jan 2016                             *
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
>>>>>>> 1066f043d1fe6c4042aa531bcc68c20a68585ad8
int changeGreedy(std::vector<int> availableCoins, int makeChangeFrom)
{
	//number of coins needed
	int numOfCoins = 0;
	//vector to keep track of the coins needed to make change
<<<<<<< HEAD
	vector<int> madeChangeFrom = { 0,0,0,0,0 };

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

	 //Now spit it out!...the change that is!
	cout << "[";
	for (int i = 1; i <= madeChangeFrom.size(); i++)
	{
		if (i == madeChangeFrom.size())
		{
			cout << madeChangeFrom[i - 1];
		}
		else
		{
			cout << madeChangeFrom[i - 1] << ",";
		}
	}
	cout << "]\n";


	return numOfCoins;
}
=======
    vector<int> madeChangeFrom = {0,0,0,0,0};

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

    //Now spit it out!...the change that is!
    cout << "[";
    for(int i=1;i<=madeChangeFrom.size();i++)
    {
        if(i == madeChangeFrom.size())
        {
            cout << madeChangeFrom[i-1];
        }
        else
        {
            cout << madeChangeFrom[i-1] << ",";
        }
    }
    cout << "]\n";


	return numOfCoins;
}
>>>>>>> 1066f043d1fe6c4042aa531bcc68c20a68585ad8
