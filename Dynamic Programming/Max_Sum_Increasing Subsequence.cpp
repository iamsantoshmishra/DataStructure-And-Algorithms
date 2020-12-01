/*
	Given an array of n positive integers. Write a program to find the
	sum of maximum sum subsequence of the given array such that
	the integers in the subsequence are sorted in increasing order.

	For example, if input is {1, 101, 2, 3, 100, 4, 5},
	then output should be 106 (1 + 2 + 3 + 100),
	
	if the input array is {3, 4, 5, 10},
	then output should be 22 (3 + 4 + 5 + 10) and
	if the input array is {10, 5, 4, 3},
	then output should be 10
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxSumISBruteForceSolUtil(int arr[], int size, int currIndex, int prevElement) {

	if (currIndex >= size) {
		return 0;
	}
	
	if (arr[currIndex] > prevElement) {
		return max(arr[currIndex] + 
				   maxSumISBruteForceSolUtil(arr, size, currIndex+1, arr[currIndex]),
				   maxSumISBruteForceSolUtil(arr, size, currIndex+1, prevElement));
	} else {
		return maxSumISBruteForceSolUtil(arr, size, currIndex+1, prevElement);
	}	
}

int maxSumISBruteForceSol(int arr[], int size) {

	return (maxSumISBruteForceSolUtil(arr, size, 0, INT_MIN));

}

int maxSumISMemoizationDPUtil(int arr[], int size, int currIndex, int prevIndex, vector<vector<int> > &aux) {

	if (currIndex >= size) {
		return 0;
	}
	
	if (aux[prevIndex+1][currIndex] != INT_MIN) {
		return aux[prevIndex+1][currIndex];
	}
	
	int include = 0, exclude = 0;
	
	if (prevIndex < 0 || arr[currIndex] > arr[prevIndex]) {
		include =  arr[currIndex] + maxSumISMemoizationDPUtil(arr, size, currIndex+1, currIndex, aux);
	} 
	
	exclude = maxSumISMemoizationDPUtil(arr, size, currIndex+1, prevIndex, aux);
	
	aux[prevIndex+1][currIndex] = max(include, exclude);
	
	return aux[prevIndex+1][currIndex];	
}

int maxSumISMemoizationDP(int arr[], int size) {

	vector<vector<int> > aux(size+1, vector<int> (size, INT_MIN));

	return maxSumISMemoizationDPUtil(arr, size, 0, -1, aux);
}


int maxSumISTabulationDP(int arr[], int size) {

	vector<int> aux(size, 1);
	int lis = INT_MIN;
	
	for(int i=0; i<size; ++i){
		aux[i] = arr[i];
	}
	
	for(int i=1; i<size; ++i) {
		for(int j=0; j<i; ++j) {
			if (arr[i] > arr[j]) {
				aux[i] = max(aux[i], arr[i]+aux[j]);
				lis = max(lis, aux[i]);
			}
		}
	}
	return lis;
}

int maxSumIS(int arr[], int size) {
	int maxSumISBruteForceAns, maxSumISMemoizationDPAns, maxSumISTabulationDPAns;
	int defaultAns = -1;
	
	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	maxSumISBruteForceAns = maxSumISBruteForceSol(arr, size); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	maxSumISMemoizationDPAns = maxSumISMemoizationDP(arr, size);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N)
	maxSumISTabulationDPAns = maxSumISTabulationDP(arr, size);

	if ((maxSumISBruteForceAns == maxSumISMemoizationDPAns) &&
	    (maxSumISBruteForceAns == maxSumISTabulationDPAns)) {
		return maxSumISBruteForceAns;
	} else {
		return defaultAns; 
	}
}

/* Driver program to test above function */
int main() 
{ 
    int arr[] = {1, 101, 2, 3, 100, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Sum of max IS is %d \n", maxSumIS( arr, n )); 
    return 0; 
} 
