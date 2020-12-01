/*
	Given a sequence, find the length of the longest palindromic subsequence in it.

	As another example, if the given sequence is “BBABCBCAB”, then the output
	should be 7 as “BABCBAB” is the longest palindromic subsequence in it.
	“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence,
	but not the longest ones.
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

int lpsBruteForceSolUtil(string seq, int start, int end) {
	if (start > end) {
		return 0;
	}

	if (start == end) {
		return 1;
	}

	if (seq[start] == seq[end]) {
		return (2 + lpsBruteForceSolUtil(seq, start+1, end-1));
	} else {
		return max(lpsBruteForceSolUtil(seq, start+1, end),
			       lpsBruteForceSolUtil(seq, start, end-1));
	}
}

int lpsBruteForceSol(string seq) {
	return lpsBruteForceSolUtil(seq, 0, seq.size()-1);	
}

int lpsMemoizationDPUtil(string seq, int start, int end, vector<vector<int>> &cache) {
	if (start > end) {
		return 0;
	}

	if (start == end) {
		return 1;
	}

	if (cache[start][end] != INT_MIN) {
		return cache[start][end];
	}

	if (seq[start] == seq[end]) {
		cache[start][end] = 2 + lpsMemoizationDPUtil(seq, start+1, end-1, cache);
	} else {
		cache[start][end] = max(lpsMemoizationDPUtil(seq, start+1, end, cache),
			       				lpsMemoizationDPUtil(seq, start, end-1, cache));
	}
	return cache[start][end];
}

int lpsMemoizationDP(string seq) {
	vector<vector<int>> cache(seq.size(), vector<int> (seq.size(), INT_MIN));
	return lpsMemoizationDPUtil(seq, 0, seq.size()-1, cache);	
}

int lpsTabulationDP(string seq) {
	vector<vector<int>> cache(seq.size(), vector<int> (seq.size(), INT_MIN));
	
	for (int i=0; i<seq.size(); ++i) {
		cache[i][i] = 1;
	}

	for (int strLen=2; strLen<=seq.size(); ++strLen) {
		for (int i=0; i<seq.size()-strLen+1; ++i) {
			int j = i + strLen - 1;
			if (strLen == 2) {
				if (seq[i] == seq[j]) {
					cache[i][j] = 2;
				} else {
					cache[i][j] = 1;
				}	
			} else {
				if (seq[i] == seq[j]) {
					cache[i][j] = 2 + cache[i+1][j-1];
				} else {
					cache[i][j] = max(cache[i+1][j], cache[i][j-1]);
				} 
			}
		}
	}
	return cache[0][seq.size()-1];	
}

int lps(string seq) {
	int lpsBruteForceAns, lpsMemoizationDPAns, lpsTabulationDPAns;
	int defaultAns = INT_MIN;
	
	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	lpsBruteForceAns = lpsBruteForceSol(seq); 
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	lpsMemoizationDPAns = lpsMemoizationDP(seq);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N^2)
	lpsTabulationDPAns = lpsTabulationDP(seq);

	if ((lpsBruteForceAns == lpsMemoizationDPAns) &&
	    (lpsBruteForceAns == lpsTabulationDPAns)) {
		return lpsBruteForceAns;
	} else {
		return defaultAns; 
	}
}

/* Driver program to test above functions */
int main() 
{ 
    string seq = "GEEKSFORGEEKS";  
    cout << "The length of the LPS is " 
         << lps(seq); 
    return 0; 
}