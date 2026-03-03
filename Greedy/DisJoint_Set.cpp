/*
===========================================
      DISJOINT SET (UNION-FIND)
      USING UNION BY RANK
===========================================

Problem:
Maintain a collection of disjoint (separate)
sets and support two operations efficiently:

1) find(x)   → Find representative (root)
               of the set containing x
2) union(x,y) → Merge two sets

-------------------------------------------
WHY WE USE DISJOINT SET?
-------------------------------------------
- Detect cycle in graph (Kruskal's Algorithm)
- Check if two nodes are connected
- Count connected components
- Dynamic connectivity problems

-------------------------------------------
CORE IDEA:
-------------------------------------------
Each element initially belongs to its
own set.

We maintain:
    parent[i] → stores parent of i
    rank[i]   → approximate height of tree

If:
    parent[i] == i
Then:
    i is the root (leader) of its set.

-------------------------------------------
FIND OPERATION (with Path Compression):
-------------------------------------------
Goal:
    Find ultimate parent (root) of node.

While finding root,
we compress the path by directly
attaching nodes to the root.

This makes future queries faster.

-------------------------------------------
UNION OPERATION (Union by Rank):
-------------------------------------------
Goal:
    Merge two different sets.

Steps:
1) Find parents of both nodes.
2) If parents are same → already connected.
3) Attach smaller rank tree under larger one.
4) If ranks are equal → attach one and
   increase its rank.

Why Rank?
To keep tree height small.

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
With:
- Path Compression
- Union by Rank

Each operation runs in:
    O(α(n))  (almost constant time)

(α = inverse Ackermann function,
 extremely slow growing)

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
O(n)

===========================================
*/

#include<bits/stdc++.h>
using namespace std;

class DSU{             // Disjoint Set Union (Union-Find)
    vector<int>parent;
    vector<int> rank;
public:
    DSU(int n){             // constructor to initialize DSU for n elements
        rank.resize(n+1,0);    // Initialize rank of all elements to 0
        parent.resize(n+1);       

        for(int i = 0; i<n;i++){    // Initially, each element is its own parent (root of its own set)
            parent[i] = i;
        }
    }

    int UltimateParent(int node){   // Find operation with path compression 
        if( node == parent[node])     // path compression: if node is not its own parent, recursively find the ultimate parent and compress the path so that all nodes directly point to the ultimate parent and complexity is reduced for future queries
            return node;               // If node is not its own parent, find the ultimate parent and compress the path
        return parent[node] = UltimateParent(parent[node]);      // path compression: recursively find the ultimate parent and compress the path so that all nodes directly point to the ultimate parent and complexity is reduced for future queries
    }

    void unionByRank(int u, int v){   // Union operation by rank: merge two sets based on rank to keep tree height small and optimize future operations
        int ultiP_u = UltimateParent(u);    // Find ultimate parent of u
        int ultiP_v = UltimateParent(v);     // Find ultimate parent of v
        if(ultiP_u == ultiP_v) return;       // If both nodes have the same ultimate parent, they are already in the same set, so we return without doing anything
        if(rank[ultiP_u] < rank[ultiP_v]){    // If rank of ultimate parent of u is less than rank of ultimate parent of v, we attach the tree of u under v and update the parent of ultiP_u to ultiP_v
            parent[ultiP_u] = ultiP_v;
        }
        else if(rank[ultiP_u] > rank[ultiP_v]){   // If rank of ultimate parent of u is greater than rank of ultimate parent of v, we attach the tree of v under u and update the parent of ultiP_v to ultiP_u
            parent[ultiP_v] = ultiP_u;
        }
        else{                                   // If ranks are equal, we can choose either one to be the new parent. Here, we attach the tree of v under u and update the parent of ultiP_v to ultiP_u and increase the rank of ultiP_u by 1 since it becomes the new root of the merged tree
            parent[ultiP_u] = ultiP_v;
            rank[ultiP_v]++; 
        }
    }
};

int main(){
    int n = 5;
    DSU dsu(n);

    dsu.unionByRank(0,1);
    dsu.unionByRank(1,2);
    dsu.unionByRank(3,4);

    cout << "Parent of 2: " << dsu.UltimateParent(2) << endl;
    cout << "Parent of 4: " << dsu.UltimateParent(4) << endl;

    return 0;
}