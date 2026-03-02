/*
===========================================
            PRIM'S ALGORITHM
===========================================

Problem:
Find the Minimum Spanning Tree (MST) of a 
connected, weighted, undirected graph.

What is MST?
- Connects all vertices
- No cycles
- Minimum total edge weight

-------------------------------------------
GREEDY IDEA:
-------------------------------------------
At every step, select the minimum weight
edge that connects:
    visited vertex → unvisited vertex

This is based on the CUT PROPERTY of MST.

-------------------------------------------
APPROACH (Adjacency Matrix Version):
-------------------------------------------

1. Create:
   - key[] array:
       key[i] = minimum weight edge needed 
                to connect vertex i
   - visited[] array:
       track vertices included in MST

2. Initialize:
   - key[0] = 0 (start from vertex 0)
   - All other keys = INT_MAX
   - visited[] = false
   - totalCost = 0

3. Repeat V times:
   a) Pick vertex 'u' with:
         minimum key value
         and not visited

   b) Mark 'u' as visited

   c) Add key[u] to totalCost

   d) Update neighbors:
         For each vertex v:
            If edge (u, v) exists
            AND v not visited
            AND weight < key[v]
            → update key[v]

4. After V iterations:
   totalCost = weight of MST

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
O(V^2)  (because we scan all vertices
         to find minimum key each time)

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
O(V)

-------------------------------------------
When to Use:
-------------------------------------------
- Graph is dense
- Adjacency matrix is given
- V is small

===========================================
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int v;
	cin>>v;

	vector<vector<int>> graph(v,vector<int>(v));

	for(int i = 0; i<v; i++){
		for(int j= 0; j<v; j++){
			cin>>graph[i][j];
		}
	}
	vector<int> key(v, INT_MAX);    // key[i] = min weight edge to connect vertex i
	vector<bool>visited(v,false);    // visited[i] = true if vertex i is included in MST

	key[0] = 0;                  // Start from vertex 0
	int total = 0;                // total = weight of MST

	for(int i = 0; i<v; i++){
		int index = -1;               // index of vertex with minimum key value
		int minKey = INT_MAX;        // minimum key value found

		for(int j = 0; j<v; j++){               // Find vertex with minimum key value
			if(!visited[j] && key[j] < minKey){
				minKey = key[j];                       // Update minimum key value
				index = j;              // Update index of vertex with minimum key value
			}
		}
		visited[index] = true;          // Mark vertex as included in MST
		total += key[index];              // Add key value to total cost of MST

		for(int j = 0; j< v; j++){       // Update key values of adjacent vertices of the picked vertex
			if(graph[index][j] != 0 && !visited[j] && graph[index][j] < key[j]){    // If edge exists and vertex is not visited and weight is less than current key value
				key[j] = graph[index][j];               // Update key value of vertex j
			}
		}
	}
	cout<<total<<endl;
	return 0;
}