/*
===========================================
      DISJOINT SET (UNION-FIND)
      USING UNION BY SIZE
===========================================

Problem:
Maintain disjoint sets and support:

1) find(x)   → Find representative (root)
2) union(x,y) → Merge two sets

-------------------------------------------
WHY UNION BY SIZE?
-------------------------------------------
Instead of tracking tree height (rank),
we track how many nodes are in each set.

We always attach:
    Smaller set → under larger set

This keeps the tree shallow.

-------------------------------------------
DATA STRUCTURES USED:
-------------------------------------------
parent[i] → stores parent of node i
size[i]   → stores size of set whose root is i

-------------------------------------------
FIND OPERATION (with Path Compression):
-------------------------------------------
Find the ultimate parent of a node.
While returning, compress path
so future finds are faster.

-------------------------------------------
UNION OPERATION (Union by Size):
-------------------------------------------
1) Find parent of both nodes.
2) If same → already connected.
3) Compare sizes:
      Smaller root attaches to larger root.
4) Update size of new root.

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
With:
- Path Compression
- Union by Size

Each operation runs in:
    O(α(n))  ~ almost constant time

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
O(n)

===========================================
*/

#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    // Constructor
    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;   // Each node is its own parent
            size[i] = 1;     // Each set initially has size 1
        }
    }

    // Find with Path Compression
    int findParent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union by Size
    void unionSet(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;  // already in same set

        // Attach smaller set under larger set
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main(){
    int n = 5;
    DSU dsu(n);

    dsu.unionSet(0,1);
    dsu.unionSet(1,2);
    dsu.unionSet(3,4);

    cout << "Parent of 2: " << dsu.findParent(2) << endl;
    cout << "Parent of 4: " << dsu.findParent(4) << endl;

    return 0;
}