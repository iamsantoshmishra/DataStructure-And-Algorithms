/*
 * SegmentTree.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>

#include "SegmentTree.h"

using namespace std;

//default constructor
SegmentTree::SegmentTree() {

	buffer = NULL;
	_size = 0;
	_array_size = 0;

}

//take array and create segment tree
SegmentTree::SegmentTree(int *arr,int size) {

	buffer = NULL;
	_array_size = size;
	//if size of array is power of two
	if((size & (size-1)) == 0)
		_size = 2 * size - 1;

	//if size of array is not power of 2 then
	//calculate next power of 2
	else{
		int next = pow(2, ceil(log(size)/log(2)));
		_size = 2 * next - 1;
	}

	buffer = new int[_size];

}

//take vector object and create segment Tree
SegmentTree::SegmentTree(vector<int> v) {

	buffer = NULL;
	_array_size = v.size();

	int size = v.size();

	//if size of array is power of two
	if((size & (size-1)) == 0)
		_size = 2 * size - 1;

	//if size of array is not power of 2 then
	//calculate next power of 2
	else{
		int next = pow(2, ceil(log(size)/log(2)));
		_size = 2 * next - 1;
	}

	buffer = new int[_size];

}

//it return query  value of the given range
int SegmentTree::rangeQuery(int qlow,int qhigh){

	//calling rangeQueryUtil of desired class type
	return (rangeQueryUtil(qlow,qhigh,0,_array_size-1,0));
}

//update range value with delta
void SegmentTree::rangeUpdate(int qlow,int qhigh,int delta){

	//calling rangeUpdateUtil it will update the given range value with delta
	rangeUpdateUtil(qlow,qhigh,0,_array_size-1,0,delta);

}

// to get parent of node at index
int SegmentTree::parent(int index){

	return ((index-1)/2);
}

// to get index of left child of node at index
int SegmentTree::left(int index){

	return (2*index + 1);
}

// to get index of right child of node at index
int SegmentTree::right(int index){

	return (2*index + 2);
}

//destructor
SegmentTree::~SegmentTree() {

	delete []buffer;
}

