/*
 * Heap.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: sm186114
 */

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>

#include "Heap.h"

using namespace std;

//this parent class for max and min Heap
Heap::Heap() {

	buffer = NULL;
	_size = 0;
	_capacity = 0;
	_log = 0;

}

// Returns key at root from heap
int Heap::topKey(){

	return(buffer[0]);

}

// Method to remove element (or root) from heap
int Heap::extractKey(){

	int top = buffer[0];
	buffer[0] = buffer[_size-1];
	_size--;
	heapify(0);
	return top;
}

// to get parent of node at index
int Heap::parent(int index){

	return ((index-1)/2);
}

// to get index of left child of node at index
int Heap::left(int index){

	return (2*index + 1);
}

// to get index of right child of node at index
int Heap::right(int index){

	return (2*index + 2);
}

//swap value
void Heap::swap(int& a,int& b){

	int temp = a;
	a = b;
	b = temp;
}

/*
It informs the heap of a planned change in size.
This enables the heap to manage the storage allocation accordingly.
reserve does not change the size of the heap and reallocation happens
if and only if the current capacity is less than the argument of reserve
*/
void Heap::reserve(int capacity){

	int *newBuffer = new int[capacity];

    memcpy(newBuffer,buffer,sizeof(int)*_size);
    _capacity = capacity;
    delete[] buffer;
    buffer = newBuffer;
}

//heap destructor
Heap::~Heap() {

	delete buffer;
}

/*
Heap::Heap(int size) {
	size = 0;
	_log = ceil(log((double) size) / log(2.0));
	_capacity = 1 << _log;
	buffer = new int[_capacity];

}
*/

/*
void Heap::insert(vector<int> v){

	int prev_size = _size;
	_size = _size + v.size();

	while(_size >= _capacity){
		//reserve space by double if buffer is full
		reserve(1 << _log);
		_log++;
	}

	//memcpy(buffer+size,*v,sizeof(int)*size);
	for(int i=prev_size+1,j=0;i<_size;++i,++j)
		buffer[i] = v[j];

	buildHeap();
}
*/

/*
void Heap::insert(int *arr,int size){

	int prev_size = _size;
	_size = _size + size;

	while(_size >= _capacity){
		//reserve space by double if buffer is full
		reserve(1 << _log);
		_log++;
	}

	//memcpy(buffer+size,*v,sizeof(int)*size);
	for(int i=prev_size+1,j=0;i<_size;++i,++j)
		buffer[i] = arr[j];

	buildHeap();
}
*/

/*
void Heap::buildHeap(){

	for(int i=_size/2;i>=0;--i)
		heapify(i);
}
*/



