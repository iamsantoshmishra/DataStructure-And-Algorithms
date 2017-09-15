/*
 * main.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Santosh Kumar Mishra
 */

#include <iostream>

#include "MaxSegmnetTree.h"

#include "MinSegmentTree.h"

using namespace std;

int main(){


	int arr[] = {3,19,2,14,1,5,18,7,9,11};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout<<"\n\n<<----------- Array Element ------------>>\n\n";

	for(int i=0;i<size;++i)
		cout<<arr[i]<<" ";

	cout<<"\n\n<<--------- Query from Max Segment Tree ------------>>\n";

	MaxSegmnetTree maxSegmentTree(arr,size);

	cout<<"\nMaximum between 6 & 8 index :: "<<maxSegmentTree.rangeQuery(6,8);
	cout<<"\nMaximum between 2 & 3 index :: "<<maxSegmentTree.rangeQuery(2,3);
	cout<<"\nMaximum between 4 & 4 index :: "<<maxSegmentTree.rangeQuery(4,4);
	cout<<"\nMaximum between 3 & 7 index :: "<<maxSegmentTree.rangeQuery(3,7);
	cout<<"\nMaximum between 0 & 9 index :: "<<maxSegmentTree.rangeQuery(0,9);


	cout<<"\n\n<<----------- Array Element ------------>>\n\n";

	for(int i=0;i<size;++i)
		cout<<arr[i]<<" ";

	cout<<"\n\n<<--------- Query from Min Segment Tree ------------>>\n";

	MinSegmentTree minSegmentTree(arr,size);

	cout<<"\nMinimum between 6 & 8 index :: "<<minSegmentTree.rangeQuery(6,8);
	cout<<"\nMinimum between 2 & 3 index :: "<<minSegmentTree.rangeQuery(2,3);
	cout<<"\nMinimum between 4 & 4 index :: "<<minSegmentTree.rangeQuery(4,4);
	cout<<"\nMinimum between 3 & 7 index :: "<<minSegmentTree.rangeQuery(3,7);
	cout<<"\nMinimum between 0 & 9 index :: "<<minSegmentTree.rangeQuery(0,9);

	return 0;
}
