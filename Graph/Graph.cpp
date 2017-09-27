/*
 * Graph.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Santosh Kumar Mishra
 */

#include "Graph.h"

//constructor it will created as many vertices given by user
Graph::Graph(int V) {

	this->V = V;
	adj = new list<int>[V];

}

//add new edge to graph
void Graph::addEdge(int v,int w){

	adj[v].push_back(w);

}

//depth first traversal of the graph it will first visit start vertex
//then visit each vertex one by one
void Graph::DFS(int start){

	bool visited[V] = {false};

	DFSUtil(start,visited);

	for(int i=0;i<V;++i){
		if(!visited[i])
			DFSUtil(i,visited);
	}
}

//dfs of graph reachable from given vertex
void Graph::DFSUtil(int v,bool visited[]){

	if(visited[v])
		return;

	cout<<v<<" ";
	visited[v] = true;
	list<int>::iterator it;

	for(it = adj[v].begin();it != adj[v].end();++it){
		if(!visited[*it])
			DFSUtil(*it,visited);
	}

}

//BFS traversal of the graph
void Graph::BFS(int start){

	queue<int> q;
	bool visited[V] = {false};

	q.push(start);

	list<int>::iterator it;

	while(!q.empty()){

		int top = q.front();

		cout<<top<<" ";
		visited[top] = true;

		q.pop();

		for(it = adj[top].begin();it != adj[top].end();++it){
			if(!visited[*it])
				q.push(*it);
		}
	}

}

// A recursive function used by topologicalSort
void Graph::topologicalSort(){

	bool visited[V] = {false};

	stack<int> st;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for(int i=0;i<V;++i){
		if(!visited[i])
			topologicalSortUtil(i,visited,st);
	}

	// Print contents of stack
	while(!st.empty()){

		cout<<st.top()<<" ";
		st.pop();
	}

}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v,bool visited[],stack<int> &st){

	// Mark the current node as visited.
	visited[v] = true;

	list<int>::iterator it;
	// Recur for all the vertices adjacent to this vertex
	for(it = adj[v].begin();it != adj[v].end();++it){
		if(!visited[*it])
			topologicalSortUtil(*it,visited,st);
	}

	// Push current vertex to stack which stores result
	st.push(v);
}

//destructor
Graph::~Graph() {

	delete[] adj;
}

