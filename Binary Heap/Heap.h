/*
 * Heap.h
 *
 *  Created on: Sep 13, 2017
 *      Author: sm186114
 */

#ifndef HEAP_H_
#define HEAP_H_

using namespace std;

class Heap {

protected:
	int *buffer;
	int _size;
	int _capacity;
	int _log;
public:
	Heap();
	//Heap(int size);
	virtual void insertKey(int key) = 0;
	//void insert(vector<int> v);
	//void insert(int *arr,int size);
	//virtual void buildHeap();
	//void buildHeap(int *arr,int size);
	virtual void heapify(int index) = 0;
	int topKey();
	int extractKey();
	virtual void deleteKey(int index) = 0;
	int parent(int index);
	int left(int index);
	int right(int index);
	void swap(int&,int&);
	void reserve(int capacity);
	virtual ~Heap();

};

#endif /* HEAP_H_ */
