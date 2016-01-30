#pragma once
/*
algos.h
Created by Rosa Tung on 1.20.16
*/

#ifndef ALGOS_H
#define ALGOS_H

#include <vector>
#include <fstream>
#include <limits.h>
using namespace std;

const signed int SMALL = -32767;
const signed int LARGE = 32767;

int changeSlow(int amount, vector<int> const coinArray);
int changeGreedy(std::vector<int> availableCoins, int makeChangeFrom);
vector< vector<int> > changedp(vector<int> const &myCoins, vector<int> const &A); //bottom up dp
void getChangeDP(int numCoins, int change, vector<int> const &myCoins, vector< vector<int> > &table, ofstream& writeFile); //extract change 

#endif // ALGOS_H_INCLUDED