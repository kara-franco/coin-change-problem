#pragma once
/*
algos.h
Created by Rosa Tung on 1.20.16
Last Modified by Group: 1.31.16
*/

#ifndef ALGOS_H
#define ALGOS_H

#include <vector>
#include <fstream>
#include <limits.h>
#include <iostream>
using namespace std;

const signed int SMALL = -32767;
const signed int LARGE = 32767;
struct changeStruct {
	int amount;
	std::vector<int> coinsUsed;
};

int getChangeSlow(std::vector<int> &coins, int changeVal, std::vector<int> &ChangeCoinsUsed);
void changeSlow(int changeVal, std::vector<int> coins, changeStruct &bestSet, changeStruct curSet);

vector<int> changeGreedy(std::vector<int> availableCoins, int makeChangeFrom);
vector< vector<int> > changedp(vector<int> const &myCoins, vector<int> const &A); //bottom up dp
void getChangeDP(int numCoins, int change, vector<int> const &myCoins, vector< vector<int> > &table, ofstream& writeFile); //extract change
#endif // ALGOS_H_INCLUDED