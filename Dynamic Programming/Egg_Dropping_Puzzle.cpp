/*
	The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
	Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from,
	and which will cause the eggs to break on landing. We make a few assumptions:

	--> An egg that survives a fall can be used again.
	--> A broken egg must be discarded.
	--> The effect of a fall is the same for all eggs.
	--> If an egg breaks when dropped, then it would break if dropped from a higher floor.
	--> If an egg survives a fall then it would survive a shorter fall.
	--> It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

	If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way.
	Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks.
	In the worst case, this method may require 36 droppings. Suppose 2 eggs are available.
	What is the least number of egg-droppings that is guaranteed to work in all cases?
	
	The problem is not actually to find the critical floor, but merely to decide floors
	from which eggs should be dropped so that total number of trials are minimized.
 */

#include <bits/stdc++.h>

using namespace std;

int eggDropBruteForceSol(int NoOfEggs, int NoOfFloors) {

	if (NoOfFloors == 1 || NoOfFloors == 0) {
		return NoOfFloors;
	}
	
	if (NoOfEggs == 1) {
		return NoOfFloors;
	}

	int minTrials = INT_MAX, res; 
  
    // Consider all droppings from 1st floor to kth floor and 
    // return the minimum of these values plus 1. 
    for (int x = 1; x <=NoOfFloors; x++) 
    { 
        res = max(eggDropBruteForceSol(NoOfEggs-1, x-1), eggDropBruteForceSol(NoOfEggs, NoOfFloors-x)); 
        minTrials = min(minTrials, res); 
    } 
  
    return minTrials + 1; 
}

int eggDropMemoizationDPUtil(int NoOfEggs, int NoOfFloors, vector<vector<int>>& cache) {

	if (NoOfFloors == 1 || NoOfFloors == 0) {
		return NoOfFloors;
	}
	
	if (NoOfEggs == 1) {
		return NoOfFloors;
	}

	if (cache[NoOfEggs][NoOfFloors] != INT_MAX) {
		return cache[NoOfEggs][NoOfFloors];
	}

	int minTrials = INT_MAX, res; 
  
    // Consider all droppings from 1st floor to kth floor and 
    // return the minimum of these values plus 1. 
    for (int x = 1; x <=NoOfFloors; x++) 
    { 
        res = max(eggDropMemoizationDPUtil(NoOfEggs-1, x-1, cache),
        	      eggDropMemoizationDPUtil(NoOfEggs, NoOfFloors-x, cache)); 
        minTrials = min(minTrials, res); 
    } 
  	
  	cache[NoOfEggs][NoOfFloors] = minTrials + 1;
    return cache[NoOfEggs][NoOfFloors]; 
}

int eggDropMemoizationDP(int NoOfEggs, int NoOfFloors) {
	vector<vector<int>> cache(NoOfEggs+1, vector<int> (NoOfFloors+1, INT_MAX));
	return eggDropMemoizationDPUtil(NoOfEggs, NoOfFloors, cache);
}


int eggDropTabulationDP(int NoOfEggs, int NoOfFloors) {
	vector<vector<int>> cache(NoOfEggs+1, vector<int> (NoOfFloors+1, INT_MAX));

	if (NoOfEggs == 0) {
		return INT_MAX;
	}

	for (int i=0; i<NoOfFloors; ++i) {
		cache[1][i] = i;
	}

	for (int e=2; e<=NoOfEggs; ++e) {
		for (int f=1; f<=NoOfFloors; ++f) {
			if (f < e) {
				cache[e][f] = cache[e-1][f];
			} else {
				int minTrials = INT_MAX, res;
				for (int k=1; k<=f; ++k) {
					res = max(cache[e-1][k-1], cache[e][f-k]);
					minTrials = min(minTrials, res);
				}
				cache[e][f] = minTrials + 1;
			}
		}
	}

	return cache[NoOfEggs][NoOfFloors];

}	

int eggDrop(int NoOfEggs, int NoOfFloors) {
	int eggDropBruteForceAns, eggDropMemoizationDPAns, eggDropTabulationDPAns;
	int defaultAns = INT_MAX;

	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	eggDropBruteForceAns = eggDropBruteForceSol(NoOfEggs, NoOfFloors); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
    eggDropMemoizationDPAns = eggDropMemoizationDP(NoOfEggs, NoOfFloors); 
	// Time Complexcity: O(N^3)
	// Space Complexcity: O(N^2)
	eggDropTabulationDPAns = eggDropTabulationDP(NoOfEggs, NoOfFloors);

	if ((eggDropBruteForceAns == eggDropMemoizationDPAns) &&
	    (eggDropBruteForceAns == eggDropTabulationDPAns)) {
		return eggDropBruteForceAns;
	} else {
		return defaultAns; 
	} 
	return defaultAns; 
}


/* Driver program to test to pront printDups*/
int main() 
{ 
    int NoOfEggs = 2, NoOfFloors = 10; 
    cout << "Minimum number of trials in worst case with "
         << NoOfEggs << " eggs and " << NoOfFloors << " floors is " 
         << eggDrop(NoOfEggs, NoOfFloors) << endl; 
    
    return 0; 
} 