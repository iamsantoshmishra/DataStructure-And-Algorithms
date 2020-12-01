/*
	Given an input string and a dictionary of words, find out if the input string
	can be segmented into a space-separated sequence of dictionary words.
	See following examples for more details.
	This is a famous Google interview question, also being asked by many other companies now a days.

	Consider the following dictionary 
	{ i, like, sam, sung, samsung, mobile, ice, 
  	cream, icecream, man, go, mango}

	Input:  ilike
	Output: Yes 
	The string can be segmented as "i like".

	Input:  ilikesamsung
	Output: Yes
	The string can be segmented as "i like samsung" 
	or "i like sam sung"
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not. 
  An array of strings is used for dictionary.  Using array of strings for 
  dictionary is definitely not a good idea. We have used for simplicity of 
  the program*/
int dictionaryContains(string word) 
{ 
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream"}; 
    int size = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < size; i++) 
        if (dictionary[i].compare(word) == 0) 
           return true; 
    return false; 
}


bool wordBreakBruteForceSolUtil(string word, int currIdx) {
	if (currIdx >= word.size()) {
		return true;
	}

	string s = "";
	for (int i = currIdx; i < word.size(); i++) {
		s += string(1, word[i]);

		if (dictionaryContains(s)) {
			if (wordBreakBruteForceSolUtil(word, i+1)) {
				return true;
			}
		}
	}
	return false;
}

bool wordBreakBruteForceSol(string word) {
	return wordBreakBruteForceSolUtil(word, 0);
}

bool wordBreakMemoizationDPUtil(string word, int currIdx, vector<int> &cache) {
	if (currIdx >= word.size()) {
		return true;
	}

	if (cache[currIdx] != -1) {
		return (cache[currIdx] == 1 ? true : false);
	}

	string s = "";
	for (int i = currIdx; i < word.size(); i++) {
		s += string(1, word[i]);

		if (dictionaryContains(s)) {
			if (wordBreakMemoizationDPUtil(word, i+1, cache)) {
				cache[i+1] = 1;
				return true;
			} else {
				cache[i+1] = 0;
			}
		}
	}
	cache[currIdx] = 0;
	return false;
}

bool wordBreakMemoizationDP(string word) {
	vector<int> cache(word.size()+1, -1);
	return wordBreakMemoizationDPUtil(word, 0, cache);
}

bool wordBreakTabulationDP(string word) {
	vector<bool> cache(word.size()+1, false);

	cache[0] = true;

	for (int i=1; i<= word.size(); i++) {
		for (int j=0; j<i; ++j) {
			if (cache[j] && dictionaryContains(word.substr(j, i-j))) {
				cache[i] = true;
			}
		}
	}
	return cache[word.size()];
}

int wordBreak(string word) {
	bool wordBreakBruteForceAns, wordBreakMemoizationDPAns, wordBreakTabulationDPAns;
	bool defaultAns = false;
	
	// Time Complexcity: O(2^N)
	// Space Complexcity: O(0)
	wordBreakBruteForceAns = wordBreakBruteForceSol(word); 

	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N)
	wordBreakMemoizationDPAns = wordBreakMemoizationDP(word);
	// Time Complexcity: O(N^2)
	// Space Complexcity: O(N)
	wordBreakTabulationDPAns = wordBreakTabulationDP(word);

	if ((wordBreakBruteForceAns == wordBreakMemoizationDPAns) &&
	    (wordBreakBruteForceAns == wordBreakTabulationDPAns)) {
		return wordBreakBruteForceAns;
	} else {
		return defaultAns; 
	}
}

int main(int argc, char *argv[]) {

	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
}