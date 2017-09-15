/*
 * SegmentTree.h
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef SEGMENTTREE_H_
#define SEGMENTTREE_H_

#include <vector>

using namespace std;

//Segment Tree abstract class
class SegmentTree {
protected:
	int *buffer; //contains data after constructing segment tree
	int _size; //contains size of the segment tree
	int _array_size; //contains size of the array
public:
	SegmentTree();
	SegmentTree(int *arr,int size);
	SegmentTree(vector<int> v);
	virtual void build(int *arr,int low,int high,int pos) = 0;
	virtual void build(vector<int> v,int low,int high,int pos) = 0;
	int rangeQuery(int qlow,int qhigh);
	virtual int rangeQueryUtil(int qlow,int qhigh,int low,int high,int pos) = 0;
	int parent(int index);
	int left(int index);
	int right(int index);
	virtual ~SegmentTree();
};

#endif /* SEGMENTTREE_H_ */
