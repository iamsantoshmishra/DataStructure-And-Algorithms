/*
	Given two strings str1 and str2 and below operations that can performed on str1.
	Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

	1) Insert
	2) Remove
	3) Replace
	All of the above operations are of equal cost. 

	Examples: 

	Input:   str1 = "geek", str2 = "gesek"
	Output:  1
	We can convert str1 into str2 by inserting a 's'.

	Input:   str1 = "cat", str2 = "cut"
	Output:  1
	We can convert str1 into str2 by replacing 'a' with 'u'.

	Input:   str1 = "sunday", str2 = "saturday"
	Output:  3
	Last three and first characters are same.  We basically
	need to convert "un" to "atur".  This can be done using
	below three operations. 
	Replace 'n' with 'r', insert t, insert a
*/

#include <bits/stdc++.h>
#include <string>
#include <cstdlib>

using namespace std;


int editDistBruteForceSolUtil(string src, string des, int srcIdx, int desIdx) {
	if ((srcIdx >= src.size()) && (desIdx >= des.size())) {
		return 0;
	}

	if ((srcIdx >= src.size()) || (desIdx >= des.size())) {
		if (srcIdx >= src.size()) {
			return (des.size() - desIdx);
		} else {
			return (src.size() - srcIdx);
		}
	}

	if (src[srcIdx] == des[desIdx]) {
		return editDistBruteForceSolUtil(src, des, srcIdx+1, desIdx+1); 
	} else {
		return 1 + min({editDistBruteForceSolUtil(src, des, srcIdx, desIdx+1),    // Insert 
					    editDistBruteForceSolUtil(src, des, srcIdx+1, desIdx),    // Remove
					    editDistBruteForceSolUtil(src, des, srcIdx+1, desIdx+1)   // Replace
				      });
	}
}

int editDistBruteForceSol(string src, string des) {
	return editDistBruteForceSolUtil(src, des, 0, 0);
}

int editDistMemoizationDPUtil(string src, string des, int srcIdx, int desIdx, vector<vector<int>> &cache) {
	if ((srcIdx >= src.size()) && (desIdx >= des.size())) {
		return 0;
	}

	if ((srcIdx >= src.size()) || (desIdx >= des.size())) {
		if (srcIdx >= src.size()) {
			return (des.size() - desIdx);
		} else {
			return (src.size() - srcIdx);
		}
	}

	if (cache[srcIdx][desIdx] != INT_MAX) {
		return cache[srcIdx][desIdx];
	}

	if (src[srcIdx] == des[desIdx]) {
		cache[srcIdx][desIdx] = editDistMemoizationDPUtil(src, des, srcIdx+1, desIdx+1, cache); 
	} else {
		cache[srcIdx][desIdx] =  1 + min({editDistMemoizationDPUtil(src, des, srcIdx, desIdx+1, cache),    // Insert 
					    				  editDistMemoizationDPUtil(src, des, srcIdx+1, desIdx, cache),    // Remove
					    				  editDistMemoizationDPUtil(src, des, srcIdx+1, desIdx+1, cache)   // Replace
				      					});
	}
	return cache[srcIdx][desIdx];
}

int editDistMemoizationDP(string src, string des) {
	vector<vector<int>> cache(src.size(), vector<int> (des.size(), INT_MAX));
	return editDistMemoizationDPUtil(src, des, 0, 0, cache);
}

int editDistTabulationDP(string src, string des) {
	vector<vector<int>> cache(src.size()+1, vector<int> (des.size()+1, INT_MAX));
	
	for (int i=0; i<=src.size(); ++i) {
		cache[i][0] = i;
	}

	for (int j=0; j<=des.size(); ++j) {
		cache[0][j] = j;
	}

	for (int i=1; i<=src.size(); ++i) {
		for (int j=1; j<=des.size(); ++j) {
			if (src[i-1] == des[j-1]) {
				cache[i][j] = cache[i-1][j-1];
			} else {
				cache[i][j] = 1 + min({cache[i][j-1],      // Insert
									   cache[i-1][j],      // Remove
									   cache[i-1][j-1]});  // Replace
			}
		}
	}
	return cache[src.size()][des.size()];
}

int editDist(string src, string des) {
	int editDistBruteForceAns, editDistMemoizationDPAns, editDistTabulationDPAns;
	int defaultAns = INT_MAX;
	
	// Time Complexcity: O(3^N)
	// Space Complexcity: O(0)
	editDistBruteForceAns = editDistBruteForceSol(src, des); 
	// Time Complexcity: O(N*M)
	// Space Complexcity: O(N*M)
	editDistMemoizationDPAns = editDistMemoizationDP(src, des);
	// Time Complexcity: O(N*M)
	// Space Complexcity: O(N*M)
	editDistTabulationDPAns = editDistTabulationDP(src, des);

	if ((editDistBruteForceAns == editDistMemoizationDPAns) &&
	    (editDistBruteForceAns == editDistTabulationDPAns)) {
		return editDistBruteForceAns;
	} else {
		return defaultAns; 
	} 
}

/* Driver program to test above functions */
int main() 
{ 
    // your code goes here 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDist(str1, str2); 
  
    return 0; 
}