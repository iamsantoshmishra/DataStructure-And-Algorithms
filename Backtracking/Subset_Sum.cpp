#include <iostream>
#include <bits/stdc++.h>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0])) 

using namespace std;

void printSubset(vector<int> subset){
	for(int i=0;i<subset.size();++i){
		cout<<subset[i]<<" ";
	}
	cout<<endl;
}

void generateSubsetsUtil(int coins[], int index, int size, int sum, int targets, vector<int> &subset){
	
	// base case
	if(index >= size || sum > targets){
		return;
	}
	//base case
	if(sum == targets){
		printSubset(subset);
		return; 
	}
	
	subset.push_back(coins[index]);
	generateSubsetsUtil(coins, index+1, size, (sum + coins[index]), targets, subset);
	
	subset.pop_back();
	generateSubsetsUtil(coins, index+1, size, sum, targets, subset);
}

void generateSubsets(int coins[], int size, int targets){
	
	vector<int> subset;
	sort(coins, coins+size);
	generateSubsetsUtil(coins, 0, size, 0, targets, subset);
}

int main() 
{ 
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8}; 
    int target = 53; 
  
    int size = ARRAYSIZE(weights); 
    generateSubsets(weights, size, target); 
 
    return 0; 
} 
