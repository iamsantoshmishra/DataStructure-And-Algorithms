/*
	0-1 Knapsack Problem
	--------------------------
	Given weights and values of n items, put these items in a knapsack of capacity W to get
	the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1]
	and wt[0..n-1] which represent values and weights associated with n items respectively.
	Also given an integer W which represents knapsack capacity, find out the maximum value
	subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
	You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

*/

#include <bits/stdc++.h>

using namespace std;

int knapSackBruteForceSolUtil(vector<int> &weight, vector<int> &value, int currWeightIdx, int maxW) {
	if ((maxW < 0) || (currWeightIdx < 0)) {
		return 0;
	}

	int totalValueWith = 0, totalValueWithout = 0;

	if ((maxW - weight[currWeightIdx]) >= 0) {
		totalValueWith = value[currWeightIdx];
		totalValueWith += knapSackBruteForceSolUtil(weight, value, currWeightIdx-1, maxW-weight[currWeightIdx]);
	} 
	
	totalValueWithout = knapSackBruteForceSolUtil(weight, value, currWeightIdx-1, maxW);
	return max(totalValueWith, totalValueWithout);
}

int knapSackBruteForceSol(vector<int> &weight, vector<int> &value, int maxW) {
	return knapSackBruteForceSolUtil(weight, value, weight.size()-1, maxW);
}

int knapSackMemoizationDPUtil(vector<int> &weight, vector<int> &value, int currWeightIdx, int maxW, vector<vector<int>> &cache) {
	if ((maxW < 0) || (currWeightIdx < 0)) {
		return 0;
	}

	if (cache[currWeightIdx][maxW] != INT_MIN) {
		return cache[currWeightIdx][maxW];
	}

	int totalValueWith = 0, totalValueWithout = 0;

	if ((maxW - weight[currWeightIdx]) >= 0) {
		totalValueWith = value[currWeightIdx];
		totalValueWith += knapSackMemoizationDPUtil(weight, value, currWeightIdx-1, maxW-weight[currWeightIdx], cache);
	} 
	
	totalValueWithout = knapSackMemoizationDPUtil(weight, value, currWeightIdx-1, maxW, cache);
	
	cache[currWeightIdx][maxW] = max(totalValueWith, totalValueWithout);
	return cache[currWeightIdx][maxW];
}

int knapSackMemoizationDP(vector<int> &weight, vector<int> &value, int maxW) {
	vector<vector<int>> cache(weight.size(), vector<int> (maxW+1, INT_MIN));
	return knapSackMemoizationDPUtil(weight, value, weight.size()-1, maxW, cache);
}

int knapSackTabulationDP(vector<int> &weight, vector<int> &value, int maxW) {
	vector<vector<int>> cache(weight.size()+1, vector<int> (maxW+1, INT_MIN));

	for (int i=0; i<=weight.size(); ++i) {
		cache[i][0] = 0;
	}

	for (int j=0; j <= maxW; ++j) {
		cache[0][j] = 0;
	}

	for (int i=1; i <= weight.size(); ++i) {
		for(int j=1; j <= maxW; ++j) {
			if (j < weight[i-1]) {
				cache[i][j] = cache[i-1][j];
			} else {
				cache[i][j] = max(cache[i-1][j], value[i-1] + cache[i-1][j-weight[i-1]]);
			}
		}
	}
	return cache[weight.size()][maxW];
}

int knapSack(vector<int> &weight, vector<int> &value, int maxW) {
	int knapSackBruteForceAns, knapSackMemoizationDPAns, knapSackTabulationDPAns;
	int defaultAns = INT_MIN;

	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	knapSackBruteForceAns = knapSackBruteForceSol(weight, value, maxW); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	knapSackMemoizationDPAns = knapSackMemoizationDP(weight, value, maxW);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	knapSackTabulationDPAns = knapSackTabulationDP(weight, value, maxW);

	if ((knapSackBruteForceAns == knapSackMemoizationDPAns) &&
	    (knapSackBruteForceAns == knapSackTabulationDPAns)) {
		return knapSackBruteForceAns;
	} else {
		return defaultAns; 
	} 
}

/* Driver program to test above functions */
int main() 
{ 
    vector<int> value = {60, 100, 120};  
    vector<int> weight = {10, 20, 30};  
    int maxW = 50;    
    cout<<knapSack(weight, value, maxW);  
    return 0;  
}