/*
 * MaxSegmnetTree.h
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef MAXSEGMNETTREE_H_
#define MAXSEGMNETTREE_H_

#include "SegmentTree.h"

//MaxSegmentTree class will extend SegmentTree base class
class MaxSegmnetTree : public SegmentTree{
public:
	MaxSegmnetTree();
	MaxSegmnetTree(int *arr,int size);
	MaxSegmnetTree(vector<int> v);
	virtual void build(int *arr,int low,int high,int pos);
	virtual void build(vector<int> v,int low,int high,int pos);
	virtual int rangeQueryUtil(int qlow,int qhigh,int low,int high,int pos);
	virtual void rangeUpdateUtil(int qlow,int qhigh,int low,int high,int pos,int delta);
	virtual ~MaxSegmnetTree();
};

#endif /* MAXSEGMNETTREE_H_ */
