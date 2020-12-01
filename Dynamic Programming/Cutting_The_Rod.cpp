/*
	Given a rod of length n inches and an array of prices that contains prices
	of all pieces of size smaller than n. Determine the maximum value obtainable
	by cutting up the rod and selling the pieces. For example,
	if length of the rod is 8 and the values of different pieces are given as following,
	then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

	length   | 1   2   3   4   5   6   7   8  
	--------------------------------------------
	price    | 1   5   8   9  10  17  17  20
	And if the prices are as following, then the maximum obtainable
	value is 24 (by cutting in eight pieces of length 1) 

	length   | 1   2   3   4   5   6   7   8  
	--------------------------------------------
	price    | 3   5   8   9  10  17  17  20
*/

#include <bits/stdc++.h>
#include <climits>

using namespace std;

bool cutRodUtil(int arr[], int size, int pieces, int *sum, int *maxSum) {
	
	if (pieces > size) { 
		return false;
	}
	
	if(pieces == size) {
		return true;
	}
	bool flag = false;
	for(int i=0; i<size; ++i) {
		*sum = *sum + arr[i];
		if (cutRodUtil(arr, size, pieces+i+1, sum, maxSum)){
			*maxSum = max(*sum, *maxSum);
			flag = true;
		}
		*sum = *sum - arr[i];
	}
	if(flag){
		return true;
	}
	*sum = 0;
	return false;
}

int cutRod(int arr[], int size) {
	int maxSum = 0, sum = 0;
	
	if (cutRodUtil(arr, size, 0, &sum, &maxSum)) { 
		return maxSum;
	} else {
		return INT_MIN;
	}
}

int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d \n", cutRod(arr, size));  
    return 0; 
} 
