
#include <iostream>

#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;

int main(){


	cout<<"\n<<--------- Max Heap ------------>>\n";
	MaxHeap max_heap;
	max_heap.insertKey(45);
	max_heap.insertKey(22);
	max_heap.insertKey(32);
	cout<<max_heap.topKey()<<endl;
	max_heap.insertKey(55);
	cout<<max_heap.topKey()<<endl;
	max_heap.insertKey(65);
	cout<<max_heap.extractKey()<<endl;
	cout<<max_heap.topKey()<<endl;
	max_heap.deleteKey(2);
	cout<<max_heap.topKey()<<endl;

	cout<<"\n<<--------- Min Heap ------------>>\n";

	MinHeap min_heap;
	min_heap.insertKey(45);
	min_heap.insertKey(22);
	min_heap.insertKey(32);
	cout<<min_heap.topKey()<<endl;
	min_heap.insertKey(55);
	cout<<min_heap.topKey()<<endl;
	min_heap.insertKey(65);
	cout<<min_heap.extractKey()<<endl;
	cout<<min_heap.topKey()<<endl;
	min_heap.deleteKey(2);
	cout<<min_heap.topKey()<<endl;


	return 0;
}

