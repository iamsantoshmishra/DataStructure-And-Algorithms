/*
 * TST.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "TST.h"

//constructor
TST::TST() {
	root = NULL;
}

//get new TST node
TSTNode* TST::getNode(char data){

	TSTNode *node = new TSTNode;
	node->data = data;
	node->left = node->equal = node->right = NULL;
	node->isEndOfWord = false;

	return node;
}

//insert new word into TST it will call insert helper function
void TST::insert(string word){
	//calling insert helper function
	root = insertUtil(root,word,0);
}

//insert new word into TST and update root
TSTNode* TST::insertUtil(TSTNode *root,string word,int pos){

	//base case
	if(root == NULL){
		root = getNode(word[pos]);
	}
	//if charAt pos is less than root data
	if(root->data > word[pos]){
		root->left = insertUtil(root->left,word,pos);
	}
	//if charAt pos is greated than root data
	else if(root->data < word[pos]){
		root->right =  insertUtil(root->right,word,pos);
	}
	//if charAt pos is equal to root data
	else{
		//if it is not last char
		if(word[pos+1] != '\0')
			root->equal = insertUtil(root->equal,word,pos+1);
		//if it is end of word mark it
		else
			root->isEndOfWord = true;
	}
	//return root to update TST
	return root;

}

//traverse whole TST
void TST::traverse(){

	char buffer[50];
	//call traverse helper
	traverseUtil(root,buffer,0);
}

//traverse TST and print all TSTS
void TST::traverseUtil(TSTNode *root,char *buffer,int depth){

	//if word in TSTS
	if(root){

		//first go to left
		traverseUtil(root->left,buffer,depth);

		//store current data
		buffer[depth] = root->data;
		//if end of word print it
		if(root->isEndOfWord){
			buffer[depth+1] = '\0';
			cout<<buffer<<endl;
		}
		//if data is equal go down level
		traverseUtil(root->equal,buffer,depth+1);
		//traverse to right TST
		traverseUtil(root->right,buffer,depth);
	}

}

//search given word into TST it will call search help function
bool TST::search(string word){
	//calling search helper function
	return(searchUtil(this->root,word,0));
}

//it will search given word into TST and return true if present otherwise return false
bool TST::searchUtil(TSTNode *root,string word,int pos){

	//base case
	if(root == NULL)
		return false;

	//if charAt pos is less than root data
	if(root->data > word[pos])
		return searchUtil(root->left,word,pos);
	//if charAt pos is greater than root data
	else if(root->data < word[pos])
		return searchUtil(root->right,word,pos);

	//if charAt pos is equal to root data
	else{

		//if end of word return true if word is present otherwise return false
		if(word[pos+1] == '\0')
			return root->isEndOfWord;
		//if not end of word go to down level
		else
			return searchUtil(root->equal,word,pos+1);
	}
}

//remove given word from TST it will call remove help function
void TST::remove(string word){
	//calling remove helper function
	root = removeUtil(root,word,0);
}

//it will remove given word from TST if it is already present in TST
TSTNode* TST::removeUtil(TSTNode *root,string word,int pos){
	//base case
	if(root == NULL)
		return NULL;

	//if charAt pos is less than root data
	if(root->data > word[pos])
		root->left = removeUtil(root->left,word,pos);

	//if charAt pos is greater than root data
	else if(root->data < word[pos])
		root->right = removeUtil(root->right,word,pos);

	//if charAt pos is less than root data
	else{
		//word is present and it is end of word
		if(root->isEndOfWord && word[pos+1] == '\0'){
			root->isEndOfWord = false;
			//delete leaf if there are not any common node
			if(!root->left && !root->right && !root->equal){
				delete root;
				return NULL;
			}
			//if common node then simply mark un mark entry of word and return root
			else
				return root;
		}
		//if word is not present
		else if(!root->isEndOfWord && word[pos+1] == '\0')
			return root;
		//if charAt pos is equal to root data then go to next level
		else
			root->equal = removeUtil(root->equal,word,pos+1);
	}
	//return root to its parents
	return root;
}

//destructor
TST::~TST() {
	root = NULL;
}

