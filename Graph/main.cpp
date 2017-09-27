/*
 * main.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "Graph.h"

int main(){

	// Create a graph with 4 vertices
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "\nFollowing is Depth First Traversal "
	     << "(starting from vertex 2) \n";

	g.DFS(2);

	cout << "\nFollowing is Breath First Traversal "
	     << "(starting from vertex 2) \n";

	g.BFS(2);

	cout << "\nFollowing is a Topological Sort of the given graph \n";

	g.topologicalSort();

	return 0;
}


