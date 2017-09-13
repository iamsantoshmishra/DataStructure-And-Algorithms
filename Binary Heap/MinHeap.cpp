/*
 * MinHeap.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "MinHeap.h"
#include <climits>

MinHeap::MinHeap() {
	// TODO Auto-generated constructor stub

}

// Decrease value of key at index to new_val. it is assumed that
// new_val is smaller than given index.
void MinHeap::insertKey(int key){

	if(_size >= _capacity){
		//reserve space by double if buffer is full
		reserve(1 << _log);
		_log++;
    }

	buffer [_size++] = key;
    int i = _size - 1;

    while(i != 0 && buffer[parent(i)] > buffer[i]){
    	swap(buffer[parent(i)],buffer[i]);
    	i = parent(i);
    }
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::heapify(int index){

	int l = left(index);
	int r = right(index);

	int smallest = index;

	if(l < _size && buffer[smallest] > buffer[l])
		smallest = l;

	if(r < _size && buffer[smallest] > buffer[r])
		smallest = r;

	if(smallest != index)
	{
		swap(buffer[smallest],buffer[index]);
		heapify(smallest);
	}
}

// Decreases value of key at index to new_val.  It is assumed that
// new_val is smaller than given index.
void MinHeap::decreaseKey(int index,int new_value){

	buffer[index] = new_value;

	while(index != 0 && buffer[parent(index)] > buffer[index]){
		swap(buffer[parent(index)],buffer[index]);
		index = parent(index);
	}

}

// This function deletes key at index. It first decrease value to minus
// infinite, then calls extractKey()
void MinHeap::deleteKey(int index){

	decreaseKey(index,INT_MIN);
	extractKey();

}

MinHeap::~MinHeap() {
	// TODO Auto-generated destructor stub
}

