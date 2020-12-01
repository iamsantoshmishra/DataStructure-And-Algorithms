/*
	Given two sequences, find the length of longest subsequence present in both of them.
	A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
	For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

	Examples:
	LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
	LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lcsButeForceSol(string X, string Y, int Xi, int Yi) {
	if (Xi == 0 || Yi == 0) {
		return 0;
	}
	
	if (X[Xi-1] == Y[Yi-1]) {
		return (1 + lcsButeForceSol(X, Y, Xi-1, Yi-1));
	} else {
		return max(lcsButeForceSol(X, Y, Xi-1, Yi), lcsButeForceSol(X, Y, Xi, Yi-1));
	}
}

int lcsMemoizationDPUtil(string X, string Y, int Xi, int Yi, vector<vector<int> > &aux) {
	if(Xi == 0 || Yi == 0) {
		return 0;
	}
	
	if(aux[Xi-1][Yi-1] != INT_MIN) {
		return aux[Xi-1][Yi-1];
	}
	
	if (X[Xi-1] == Y[Yi-1]) {
		aux[Xi-1][Yi-1] = 1 + lcsMemoizationDPUtil(X, Y, Xi-1, Yi-1, aux);
	} else {
		aux[Xi-1][Yi-1] = max(lcsMemoizationDPUtil(X, Y, Xi-1, Yi, aux),
							  lcsMemoizationDPUtil(X, Y, Xi, Yi-1, aux));
	}
	return aux[Xi-1][Yi-1];	
}

int lcsMemoizationDP(string X, string Y, int Xi, int Yi) {

	vector<vector<int> > aux(Xi, vector<int> (Yi, INT_MIN));

	return lcsMemoizationDPUtil(X, Y, Xi, Yi, aux);
}

int lcsTabulationDP(string X, string Y, int Xi, int Yi) {

	vector<vector<int> > aux(Xi+1, vector<int> (Yi+1, 0));
	
	for(int i=0; i<=Xi; ++i) {
		aux[i][0] = 0;
	}
	
	for(int j=0; j<=Yi; ++j) {
		aux[0][j] = 0;
	}

	for(int i=1; i<=Xi; ++i) {
		for(int j=1; j<=Yi; ++j) {
			if(X[i-1] == Y[j-1]) {
				aux[i][j] = 1 + aux[i-1][j-1];
			} else {
				aux[i][j] = max(aux[i-1][j], aux[i][j-1]);
			}
		}
	}
	return (aux[Xi][Yi]);
}

int lcs(string X, string Y, int Xi, int Yi) {
	int lcsButeForceAns, lcsMemoizationDPAns, lcsTabulationDPAns;
	int defaultAns = -1;
	
	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	lcsButeForceAns = lcsButeForceSol(X, Y, Xi, Yi); 
	// Time Complexcity: O(Xi*Yi)
	// Space Complexcity: O(Xi*Yi)
	lcsMemoizationDPAns = lcsMemoizationDP(X, Y, Xi, Yi);
	// Time Complexcity: O(Xi*Yi)
	// Space Complexcity: O(Xi*Yi)
	lcsTabulationDPAns = lcsTabulationDP(X, Y, Xi, Yi);
	
	if (lcsButeForceAns == lcsMemoizationDPAns == lcsTabulationDPAns){
		return lcsButeForceAns;
	} else {
		return defaultAns; 
	}		
}

/* Driver code */
int main()  
{  
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
      
    int m = strlen(X);  
    int n = strlen(Y);  
      
	cout<<"Length of LCS is "<< lcsTabulationDP( X, Y, m, n ); 
    /* Pending list
	 * 1) Print lcs
	 * 2) find lcs through Tabulation DP method in 1-d array
	 */  
    return 0;  
}
