/*
	Given a set of non-negative integers, and a value sum, determine
	if there is a subset of the given set with sum equal to given sum. 

	Example: 

	Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
	Output: True  
	There is a subset (4, 5) with sum 9.

	Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
	Output: False
	There is no subset that add up to 30.
*/

#include <bits/stdc++.h>
#include <climits>

using namespace std;

bool isSubSetSum(int set[], int size, int sum) {
	if (sum < 0 || size < 0) {
		return false;
	}
	
	if(sum == 0) {
		return true;
	}
	
	return isSubSetSum(set, size-1, sum-set[size-1]) || 
		   isSubSetSum(set, size-1, sum);	
}

bool isSubSetSumDP(int set[], int size, int sum) {
	bool mat[size+1][sum+1];
	
	memset(mat, false, sizeof(mat[0][0]) * size * sum);
	
	for(int i=0; i<=size; ++i){
		mat[i][0] = true;
	}
	
	for(int i=0; i<=sum; ++i){
		mat[0][i] = false;
	}
	
	mat[0][0] = true;
	
	for(int i=1; i<=size; ++i) {
		for(int j=1; j<=sum; ++j) {
			if(j < set[i-1]) {
				mat[i][j] = mat[i-1][j];
				continue;	
			} 
			if(set[i-1] == j) {
				mat[i][j] = true;
			} else if(mat[i-1][j] == true || mat[i-1][j-set[i-1]] == true) {
				mat[i][j] == true;
			}
		}
	}
	return mat[size][sum];
}


int main() {
  	int set[] = {3, 34, 4, 12, 5, 2}; 
  	int sum = 9; 
  	int n = sizeof(set)/sizeof(set[0]); 
	
	if (isSubSetSum(set, n, sum)) {
		cout<<"Solution is possible"<<endl;
	} else {
		cout<<"Solution is not possible"<<endl;
	}
	
	if (isSubSetSumDP(set, n, sum)) {
		cout<<"Solution is possible"<<endl;
	} else {
		cout<<"Solution is not possible"<<endl;
	}
	
}
