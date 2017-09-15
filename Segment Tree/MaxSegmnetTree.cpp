/*
 * MaxSegmnetTree.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#include <climits>
#include <cstring>
#include <iostream>

#include "MaxSegmnetTree.h"

using namespace std;

//default constructor
MaxSegmnetTree::MaxSegmnetTree() {
	// TODO Auto-generated constructor stub

}

//parameterized constructor it will take array and call build function
MaxSegmnetTree::MaxSegmnetTree(int *arr,int size):SegmentTree(arr,size){
	memset(buffer,INT_MIN,sizeof(int)*_size);
	//Building segment tree from given array
	build(arr,0,size-1,0);
}

//parameterized constructor it will take vector and call build function
MaxSegmnetTree::MaxSegmnetTree(vector<int> v):SegmentTree(v){
	memset(buffer,INT_MIN,sizeof(int)*_size);
	//Building segment tree from given vextor
	build(v,0,v.size()-1,0);
}

//recursively build segment Tree from given array
void MaxSegmnetTree::build(int *arr,int low,int high,int pos){


	if(low == high){
		buffer[pos] = arr[low];
		return;
	}

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	build(arr,low,mid,l);
	build(arr,mid+1,high,r);

	buffer[pos] = max(buffer[l],buffer[r]);

}

//recursively build segment Tree from given vector
void MaxSegmnetTree::build(vector<int> v,int low,int high,int pos){

	if(low == high){
		buffer[pos] = v[low];
		return;
	}

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	build(v,low,mid,l);
	build(v,mid+1,high,r);

	buffer[pos] = max(buffer[l],buffer[r]);
}

//it will return maximum value of given range in O(logn) time
int MaxSegmnetTree::rangeQueryUtil(int qlow,int qhigh,int low,int high,int pos){

	//fully overlap
	if(qlow <= low && qhigh >= high)
		return buffer[pos];
	//no overlap
	if(qlow > high || qhigh < low)
		return INT_MIN;

	int mid = (low + high) / 2;

	int l = left(pos);
	int r = right(pos);

	int lmax = rangeQueryUtil(qlow,qhigh,low,mid,l);
	int rmax = rangeQueryUtil(qlow,qhigh,mid+1,high,r);

	return max(lmax,rmax);

}

//destructor
MaxSegmnetTree::~MaxSegmnetTree() {
	// TODO Auto-generated destructor stub
}

