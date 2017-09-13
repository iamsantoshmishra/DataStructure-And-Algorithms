/*
 * MinHeap.h
 *
 *  Created on: Sep 14, 2017
 *      Author: sm186114
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "Heap.h"

class MinHeap : public Heap {
public:
	MinHeap();
	virtual void insertKey(int key);
	virtual void heapify(int index);
	void decreaseKey(int index,int new_value);
	virtual void deleteKey(int index);
	virtual ~MinHeap();
};

#endif /* MINHEAP_H_ */
