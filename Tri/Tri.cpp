/*
 * Tri.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "Tri.h"

//tri constructor
Tri::Tri() {

	root = NULL;

}

//create new tri node and return it
TriNode* Tri::getNode(){

	TriNode *node = new TriNode;

	for(int i=0;i<ALPHABET_SIZE;++i)
		node->children[i] = NULL;

	node->isEndOfWord = false;

	return node;
}

//insert word into tri
void Tri::insert(string word){

	if(root == NULL)
		root = getNode();

	TriNode *current = root;

	for(int i=0;word[i];++i){

		int index = word[i] - 'a';

		if(current->children[index] == NULL)
			current->children[index] = getNode();
		
		current = current->children[index];
	}

	current->isEndOfWord = true;
}

//search word entry into try
bool Tri::search(string word){

	TriNode *current = root;

	for(int i=0;word[i];++i){

		if(current == NULL)
			return false;

		int index = word[i] - 'a';
		current = current->children[index];

	}

	if(current->isEndOfWord == false)
		return false;

	return true;
}

//check all node is free or not
bool Tri::isFreeNode(TriNode *root){
	
	
	for(int i=0;i<ALPHABET_SIZE;++i){
		if(root->children[i])
			return false;
	}
	
	return true;	
}

//remove word entry from tri
bool Tri::remove(string word){

	//calling tri util that will remove given word from tri
	return (removeUtil(word,0,root));

}

//it will remove word and un necessary nodes from tri
bool Tri::removeUtil(string word,int level,TriNode* root){
	
	//base case
	if(root){
	
		//word is completed
		if(word[level] == '\0'){
			
			//is last node of word then unmark word entry
			if(root->isEndOfWord){
			
				root->isEndOfWord = false;
				//not any share path then delete this node
			
				if(isFreeNode(root)){
					return true;
				}
				
			}
			return false;	
		}
		//call recursivelly for next letter of the word 
		else{
		
			int index = word[level] - 'a';
			//call recursivelly
			if( removeUtil(word,level+1,root->children[index]) ){
				
				delete root->children[index];
				root->children[index] = NULL;
				
				//check for free node, if free then delete it
				return(!root->isEndOfWord && isFreeNode(root));
			}
		 
		}
	}
	//if word is not available in tri
	return false;
}

//destructor
Tri::~Tri() {
	root = NULL;
}

