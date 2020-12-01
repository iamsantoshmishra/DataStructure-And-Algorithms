/*
	Partition problem
	---------------------
	Partition problem is to determine whether a given set can be partitioned into two subsets such that
	the sum of elements in both subsets is same.
	
	Examples:

	arr[] = {1, 5, 11, 5}
	Output: true 
	The array can be partitioned as {1, 5, 5} and {11}

	arr[] = {1, 5, 3}
	Output: false 
	The array cannot be partitioned into equal sum sets.
 */

#include <bits/stdc++.h>

using namespace std;

bool canPartitionBruteForceSolUtil(vector<int> &set, int currIdx, int sum) {
	if ((currIdx < 0) && (sum != 0)) {
		return false;
	}

	if (sum < 0) {
		return false;
	}

	if (sum == 0) {
		return true;
	}

	return (canPartitionBruteForceSolUtil(set, currIdx-1, sum-set[currIdx]) ||
	        canPartitionBruteForceSolUtil(set, currIdx-1, sum));
}

bool canPartitionBruteForceSol(vector<int> &set) {
	int totalSum = 0;

    sort(set.begin(), set.end());

	for (int i=0; i<set.size(); ++i) {
		totalSum += set[i];
	}
  
  	// if the total sum is odd then equal divide is not possible
    if (totalSum&1) {
    	return false;
    } else {
    	// Find if there is subset with sum equal to  
    	// half of total sum 
		return canPartitionBruteForceSolUtil(set, set.size()-1, totalSum/2);
	}	
}


bool canPartitionMemoizationDPUtil(vector<int> &set, int currIdx, int sum, vector<vector<int>> &cache) {
	if ((currIdx < 0) && (sum != 0)) {
		return false;
	}

	if (sum < 0) {
		return false;
	}

	if (sum == 0) {
		return true;
	}

	if (cache[currIdx][sum] != INT_MIN) {
		return (cache[currIdx][sum] == 1 ? true : false);
	}

	if ( canPartitionMemoizationDPUtil(set, currIdx-1, sum-set[currIdx], cache) ||
	     canPartitionMemoizationDPUtil(set, currIdx-1, sum, cache)) {
		cache[currIdx][sum] = 1;	
	} else {
		cache[currIdx][sum] = 0;
	}

	return (cache[currIdx][sum] == 1 ? true : false); 
}

bool canPartitionMemoizationDP(vector<int> &set) {
	int totalSum = 0;
    
    sort(set.begin(), set.end());

	for (int i=0; i<set.size(); ++i) {
		totalSum += set[i];
	}

	// if the total sum is odd then equal divide is not possible
	if (totalSum&1) {
		return false;
	}

	vector<vector<int>> cache(set.size(), vector<int> (totalSum/2+1, INT_MIN));
	// Find if there is subset with sum equal to  
    // half of total sum 
	return canPartitionMemoizationDPUtil(set, set.size()-1, totalSum/2, cache);
}


bool canPartitionTabulationDP(vector<int> &set) {
	int totalSum = 0;
    
    sort(set.begin(), set.end());

	for (int i=0; i<set.size(); ++i) {
		totalSum += set[i];
	}

	// if the total sum is odd then equal divide is not possible
    if (totalSum&1) {
    	return false;
	}

	// Find if there is subset with sum equal to  
    // half of total sum 
	vector<vector<bool>> cache(set.size()+1, vector<bool> (totalSum/2 + 1, false));

	for (int i=0; i<=set.size(); ++i) {
		cache[i][0] = true;
	}

	for (int i=1; i<=set.size(); ++i) {
		for (int j=1; j<=totalSum/2; ++j) {
			if (j < set[i-1]) {
				cache[i][j] = cache[i-1][j];
			} else {
				cache[i][j] = cache[i-1][j] || cache[i-1][j-set[i-1]];
			}
		}
	}
	return cache[set.size()][totalSum/2];
}

bool canPartition(vector<int> &set) {
	bool canPartitionBruteForceAns, canPartitionMemoizationDPAns, canPartitionTabulationDPAns;
	bool defaultAns = false;

	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	canPartitionBruteForceAns = canPartitionBruteForceSol(set); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	canPartitionMemoizationDPAns = canPartitionMemoizationDP(set);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	canPartitionTabulationDPAns = canPartitionTabulationDP(set);

	if ((canPartitionBruteForceAns == canPartitionMemoizationDPAns) &&
	    (canPartitionBruteForceAns == canPartitionTabulationDPAns)) {
		return canPartitionBruteForceAns;
	} else {
		return defaultAns; 
	}
}

/* Driver program to test above functions */
int main() 
{ 
    vector<int> set = {3, 1, 1, 2, 2, 1};    
    if (canPartition(set) == true)  
        cout << "Can be divided into two subsets of equal sum";  
    else
        cout << "Can not be divided into" 
             << " two subsets of equal sum";  
    return 0;
}