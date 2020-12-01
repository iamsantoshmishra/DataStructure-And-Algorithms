/*
    Given a value N, if we want to make change for N cents,
    and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
    how many ways can we make the change? The order of coins doesn’t matter.

	For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
	So output should be 4. For N = 10 and S = {2, 5, 3, 6},
	there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
	So the output should be 5.

*/


#include <bits/stdc++.h>

using namespace std;


int coinChangeBruteForceSolUtil(vector<int> &coins, int currCoinIdx, int amount) {
	if (amount == 0) {
		return 1;
	} 

	if ((currCoinIdx >= coins.size()) || (amount < 0)) {
		return 0;
	}

	return (coinChangeBruteForceSolUtil(coins, currCoinIdx, amount-coins[currCoinIdx]) +
		    coinChangeBruteForceSolUtil(coins, currCoinIdx+1, amount));   
}

int coinChangeBruteForceSol(vector<int> &coins, int amount) {
	return coinChangeBruteForceSolUtil(coins, 0, amount);
}

int coinChangeMemoizationDPUtil(vector<int> &coins, int currCoinIdx, int amount, vector<vector<int>> &cache) {
	if (amount == 0) {
		return 1;
	} 

	if ((currCoinIdx >= coins.size()) || (amount < 0)) {
		return 0;
	}

	if (cache[currCoinIdx][amount] != INT_MIN) {
		return cache[currCoinIdx][amount];
	}

	cache[currCoinIdx][amount] = (coinChangeMemoizationDPUtil(coins, currCoinIdx, amount-coins[currCoinIdx], cache) +
		    					  coinChangeMemoizationDPUtil(coins, currCoinIdx+1, amount, cache));

    return cache[currCoinIdx][amount];   
}

int coinChangeMemoizationDP(vector<int> &coins, int amount) {
	vector<vector<int>> cache(coins.size(), vector<int> (amount+1, INT_MIN));
	return coinChangeMemoizationDPUtil(coins, 0, amount, cache);
}

int coinChangeTabulationDP(vector<int> &coins, int amount) {
	vector<vector<int>> cache(coins.size()+1, vector<int> (amount+1, INT_MIN));
	
	for (int i=0; i<=coins.size(); ++i) {
		cache[i][0] = 1;
	}

	for (int j=0; j<= amount; ++j) {
		cache[0][j] = 0;
	}

	cache[0][0] = 1;

	for (int i=1; i<=coins.size(); ++i) {
		for (int j=1; j<=amount; ++j) {
			if (coins[i-1] > j) {
				cache[i][j] = cache[i-1][j];
			} else {
				cache[i][j] = cache[i-1][j] + cache[i][j-coins[i-1]];
			}
		}
	}
	return cache[coins.size()][amount];
}

int coinChange(vector<int> &coins, int amount) {
	int coinChangeBruteForceAns, coinChangeMemoizationDPAns, coinChangeTabulationDPAns;
	int defaultAns = INT_MIN;

	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	coinChangeBruteForceAns = coinChangeBruteForceSol(coins, amount); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	coinChangeMemoizationDPAns = coinChangeMemoizationDP(coins, amount);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	coinChangeTabulationDPAns = coinChangeTabulationDP(coins, amount);

	if ((coinChangeBruteForceAns == coinChangeMemoizationDPAns) &&
	    (coinChangeBruteForceAns == coinChangeTabulationDPAns)) {
		return coinChangeBruteForceAns;
	} else {
		return defaultAns; 
	} 
}

/* Driver program to test above functions */
int main() 
{ 
	vector<int> coins = {1, 2, 3};
	int amount = 5;
	cout<<coinChange(coins, amount);
    return 0; 
}