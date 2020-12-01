/*

	Consider a situation with a number of persons and following tasks to be performed on them.

	Add a new friendship relation, i.e., a person x becomes friend of another person y.
	Find whether individual x is a friend of individual y (direct or indirect friend)

	Example:

	We are given 10 individuals say,
	a, b, c, d, e, f, g, h, i, j

	Following are relationships to be added.
	a <-> b  
	b <-> d
	c <-> f
	c <-> i
	j <-> e
	g <-> j

	And given queries like whether a is a friend of d
	or not.

	We basically need to create following 4 groups
	and maintain a quickly accessible connection
	among group items:
	G1 = {a, b, d}
	G2 = {c, f, i}
	G3 = {e, g, j}
	G4 = {h}
*/


#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
	int *set;
	int size;

	public:
		DisjointSet(int V) {
			set = new int[V];
			size = V;
			memset(set, -1, sizeof(int));
		}

		int find(int node) {
			while(set[node] > 0) {
				node = set[node];
			}
			return node;
		}

		bool merge(int r1, int r2) {
			int p1 = find(r1);
			int p2 = find(r2);

			if (p1 == p2) {
				return false;
			} 

			if (abs(set[p1]) >= abs(set[p2])) {
				set[p1] = set[p1] + set[p2];
				set[p2] = p1;
			} else {
				set[p2] = set[p2] + set[p1];
				set[p1] = p2;
			}
			return true;
		}

		bool addEdge(int src, int des) {
			return merge(src, des);
		}
};

int main() {
	DisjointSet g(5);
	bool isCycle = false;

	if (!isCycle && (g.addEdge(1, 0) == false)) {
		isCycle = true;
	} 

	if (!isCycle && (g.addEdge(0, 2) == false)) {
		isCycle = true;
	}

	if (!isCycle && (g.addEdge(2, 1) == false)) {
		isCycle = true;
	}

	if (!isCycle && (g.addEdge(0, 3) == false)) {
		isCycle = true;
	}

	if (!isCycle && (g.addEdge(3, 4) == false)) {
		isCycle = true;
	}

	if (isCycle) {
		cout<<"There is a cycle in the graph";
	} else {
		cout<<"There is not a cycle in the graph";
	}	

}
