/*
 * TST.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef TST_H_
#define TST_H_

#include <iostream>

using namespace std;

//TST Node structure
struct TSTNode{

	char data; //character of given word
	struct TSTNode *left,*equal,*right; //pointer to next level
	bool isEndOfWord; //to indicates entry of a word
};

class TST {

protected:
	TSTNode *root;

public:
	TST();
	TSTNode* getNode(char data);
	void insert(string word);
	void traverse();
	void traverseUtil(TSTNode *root,char *buffer,int depth);
	TSTNode* insertUtil(TSTNode *root,string word,int pos);
	bool search(string word);
	bool searchUtil(TSTNode *root,string word,int pos);
	void remove(string word);
	TSTNode* removeUtil(TSTNode *root,string word,int pos);
	virtual ~TST();
};

#endif /* TST_H_ */
