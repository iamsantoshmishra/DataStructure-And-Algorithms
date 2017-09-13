/*
 * MaxHeap.h
 *
 *  Created on: Sep 13, 2017
 *      Author: sm186114
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "Heap.h"

using namespace std;

class MaxHeap : public Heap {
public:
	MaxHeap();
	virtual void insertKey(int key);
	virtual void heapify(int index);
	void increaseKey(int index,int new_value);
	virtual void deleteKey(int index);
	virtual ~MaxHeap();
};

#endif /* MAXHEAP_H_ */
