/*
 * MinSegmentTree.h
 *
 *  Created on: Sep 15, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef MINSEGMENTTREE_H_
#define MINSEGMENTTREE_H_

#include "SegmentTree.h"

//MinSegmentTree class extend SegmentTree base class
class MinSegmentTree : public SegmentTree {
public:
	MinSegmentTree();
	MinSegmentTree(int *arr,int size);
	MinSegmentTree(vector<int> v);
	virtual void build(int *arr,int low,int high,int pos);
	virtual void build(vector<int> v,int low,int high,int pos);
	virtual int rangeQueryUtil(int qlow,int qhigh,int low,int high,int pos);
	virtual ~MinSegmentTree();
};

#endif /* MINSEGMENTTREE_H_ */
