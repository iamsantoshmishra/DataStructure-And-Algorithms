/*
 * Graph.h
 *
 *  Created on: Sep 27, 2017
 *      Author: Santosh Kumar Mishra
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int start);
	void DFSUtil(int v,bool visited[]);
	void BFS(int start);
	void topologicalSort();
	void topologicalSortUtil(int v,bool visited[],stack<int> &st);
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
