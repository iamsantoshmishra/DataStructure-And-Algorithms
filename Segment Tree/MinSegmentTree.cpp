/*
 * MinSegmentTree.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: Santosh Kumar Mishra
 */



#include <climits>
#include <cstring>
#include <iostream>

#include "MinSegmentTree.h"

using namespace std;

//default constructor
MinSegmentTree::MinSegmentTree() {
	// TODO Auto-generated constructor stub

}

//parameterized constructor it will take array and call build function
MinSegmentTree::MinSegmentTree(int *arr,int size):SegmentTree(arr,size){
	memset(buffer,INT_MIN,sizeof(int)*_size);
	//Building segment tree from given array
	build(arr,0,size-1,0);
}

//parameterized constructor it will take vector and call build function
MinSegmentTree::MinSegmentTree(vector<int> v):SegmentTree(v){
	memset(buffer,INT_MAX,sizeof(int)*_size);
	//Building segment tree from given vextor
	build(v,0,v.size()-1,0);
}

//recursively build Min segment Tree from given array
void MinSegmentTree::build(int *arr,int low,int high,int pos){


	if(low == high){
		buffer[pos] = arr[low];
		return;
	}

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	build(arr,low,mid,l);
	build(arr,mid+1,high,r);

	buffer[pos] = min(buffer[l],buffer[r]);

}

//recursively build Min segment Tree from given vector
void MinSegmentTree::build(vector<int> v,int low,int high,int pos){

	if(low == high){
		buffer[pos] = v[low];
		return;
	}

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	build(v,low,mid,l);
	build(v,mid+1,high,r);

	buffer[pos] = min(buffer[l],buffer[r]);
}

//it will return minimum value of given range in O(logn) time
int MinSegmentTree::rangeQueryUtil(int qlow,int qhigh,int low,int high,int pos){

	//fully overlap
	if(qlow <= low && qhigh >= high)
		return buffer[pos];
	//no overlap
	if(qlow > high || qhigh < low)
		return INT_MAX;

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	int lmin = rangeQueryUtil(qlow,qhigh,low,mid,l);
	int rmin = rangeQueryUtil(qlow,qhigh,mid+1,high,r);

	return min(lmin,rmin);

}

//update range index with given delta
void MinSegmentTree::rangeUpdateUtil(int qlow,int qhigh,int low,int high,int pos,int delta){


	//no overlap
	if(qlow > high || qhigh < low)
		return;

	//overlap
	if(low == high){
		buffer[pos] = buffer[pos] + delta;
		return;
	}



	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	rangeUpdateUtil(qlow,qhigh,low,mid,l,delta);
	rangeUpdateUtil(qlow,qhigh,mid+1,high,r,delta);

	//update parent
	buffer[pos] = min(buffer[l], buffer[r]);

	return;
}

//MinSegmnet Tree destructor
MinSegmentTree::~MinSegmentTree() {
	// TODO Auto-generated destructor stub
}
