/*
 * MaxHeap.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: sm186114
 */

#include "MaxHeap.h"
#include <climits>

//constructor
MaxHeap::MaxHeap() {
	// TODO Auto-generated constructor stub

}

// Increase value of key at index to new_val.  It is assumed that
// new_val is greater than given index.
void MaxHeap::insertKey(int key){

	if(_size >= _capacity){
		//reserve space by double if buffer is full
		reserve(1 << _log);
		_log++;
    }
    buffer [_size++] = key;
    int i = _size - 1;

    while(i != 0 && buffer[parent(i)] < buffer[i]){
    	swap(buffer[parent(i)],buffer[i]);
    	i = parent(i);
    }
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::heapify(int index){

	int l = left(index);
	int r = right(index);

	int greatest = index;

	if(l < _size && buffer[greatest] < buffer[l])
		greatest = l;

	if(r < _size && buffer[greatest] < buffer[r])
		greatest = r;

	if(greatest != index)
	{
		swap(buffer[greatest],buffer[index]);
		heapify(greatest);
	}
}

// Increases value of key at index to new_val. It is assumed that
// new_val is greater than given index.
void MaxHeap::increaseKey(int index,int new_value){

	buffer[index] = new_value;

	while(index != 0 && buffer[parent(index)] < buffer[index]){
		swap(buffer[parent(index)],buffer[index]);
		index = parent(index);
	}

}

// This function deletes key at index. It first increase value to plus
// infinite, then calls extractKey()
void MaxHeap::deleteKey(int index){

	increaseKey(index,INT_MAX);
	extractKey();

}

//destructor
MaxHeap::~MaxHeap() {
	// TODO Auto-generated destructor stub

}
