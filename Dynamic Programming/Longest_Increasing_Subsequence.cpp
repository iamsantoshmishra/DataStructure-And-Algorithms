/*
	The Longest Increasing Subsequence (LIS) problem is to
	find the length of the longest subsequence of a given sequence
	such that all elements of the subsequence are sorted in increasing order.

	For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6
	and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lisBruteForceSolUtil(int arr[], int size, int currIndex, int prevElement) {

	if (currIndex >= size) {
		return 0;
	}
	
	if (arr[currIndex] > prevElement) {
		return max(1 + 
				   lisBruteForceSolUtil(arr, size, currIndex+1, arr[currIndex]),
				   lisBruteForceSolUtil(arr, size, currIndex+1, prevElement));
	} else {
		return lisBruteForceSolUtil(arr, size, currIndex+1, prevElement);
	}	
}

int lisBruteForceSol(int arr[], int size) {

	return (lisBruteForceSolUtil(arr, size, 0, INT_MIN));

}

int lisMemoizationDPUtil(int arr[], int size, int currIndex, int prevIndex, vector<vector<int> > &aux) {

	if (currIndex >= size) {
		return 0;
	}
	
	if (aux[prevIndex+1][currIndex] != INT_MIN) {
		return aux[prevIndex+1][currIndex];
	}
	
	int include = 0, exclude = 0;
	
	if (prevIndex < 0 || arr[currIndex] > arr[prevIndex]) {
		include =  1 + lisMemoizationDPUtil(arr, size, currIndex+1, currIndex, aux);
	} 
	
	exclude = lisMemoizationDPUtil(arr, size, currIndex+1, prevIndex, aux);
	
	aux[prevIndex+1][currIndex] = max(include, exclude);
	
	return aux[prevIndex+1][currIndex];	
}

int lisMemoizationDP(int arr[], int size) {

	vector<vector<int> > aux(size+1, vector<int> (size, INT_MIN));

	return lisMemoizationDPUtil(arr, size, 0, -1, aux);
}


int lisTabulationDP(int arr[], int size) {

	vector<int> aux(size, 1);
	int lis = INT_MIN;
	
	for(int i=1; i<size; ++i) {
		for(int j=0; j<i; ++j) {
			if (arr[i] > arr[j]) {
				aux[i] = max(aux[i], 1+aux[j]);
				lis = max(lis, aux[i]);
			}
		}
	}
	return lis;
}

int lis(int arr[], int size) {
	int lisBruteForceAns, lisMemoizationDPAns, lisTabulationDPAns;
	int defaultAns = -1;
	
	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	lisBruteForceAns = lisBruteForceSol(arr, size); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	lisMemoizationDPAns = lisMemoizationDP(arr, size);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N)
	lisTabulationDPAns = lisTabulationDP(arr, size);

	if ((lisBruteForceAns == lisMemoizationDPAns) &&
	    (lisBruteForceAns == lisTabulationDPAns)) {
		return lisBruteForceAns;
	} else {
		return defaultAns; 
	}
}

/* Driver program to test above function */
int main() 
{ 
    int arr[] = { 10, 22, 9, 33, 21, 38, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Length of lis is %d \n", lis( arr, n )); 
    return 0; 
} 
