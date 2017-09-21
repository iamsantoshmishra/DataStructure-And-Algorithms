/*
 * Tri.h
 *
 *  Created on: Sep 21, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef TRI_H_
#define TRI_H_

#define ALPHABET_SIZE 26

#include <string>
using namespace std;

struct TriNode{
	struct TriNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

class Tri {

	struct TriNode *root;

public:
	Tri();
	TriNode* getNode();
	void insert(string word);
	bool search(string word);
	bool remove(string word);
	bool removeUtil(string word,int level,TriNode* root);
	bool isFreeNode(TriNode* root);
	virtual ~Tri();
};

#endif /* TRI_H_ */
