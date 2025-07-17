#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent, size;

public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]); // Path compression
    }

    void UnionByRank(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    bool sameComponent(int u, int v) {
        return findUParent(u) == findUParent(v);
    }

    void printState(int n) {
        cout << "Node : Parent | Rank | Size\n";
        for (int i = 0; i <= n; i++) {
            cout << "  " << i << "   :   " << parent[i] << "     |  " << rank[i] << "   |  " << size[i] << "\n";
        }
        cout << "----------------------\n";
    }
};

int main() {
    int n = 7;
    DSU dsu(n);

    // Sample operations
    cout << "UnionByRank operations:\n";
    dsu.UnionByRank(1, 2);
    dsu.UnionByRank(2, 3);
    dsu.printState(n);

    cout << "Are 1 and 3 in the same component? ";
    cout << (dsu.sameComponent(1, 3) ? "Yes\n" : "No\n");

    cout << "UnionBySize operations:\n";
    dsu.UnionBySize(4, 5);
    dsu.UnionBySize(5, 6);
    dsu.printState(n);

    cout << "Are 4 and 6 in the same component? ";
    cout << (dsu.sameComponent(4, 6) ? "Yes\n" : "No\n");

    cout << "Are 1 and 6 in the same component? ";
    cout << (dsu.sameComponent(1, 6) ? "Yes\n" : "No\n");

    cout << "Merging 3 and 4 using UnionBySize...\n";
    dsu.UnionBySize(3, 4);
    dsu.printState(n);

    cout << "Now, are 1 and 6 in the same component? ";
    cout << (dsu.sameComponent(1, 6) ? "Yes\n" : "No\n");

    return 0;
}


//  sort Cut

class UnionFind {
    int * parent;
    int * rank;
    
    public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        
        for(int i = 0; i < n; i++) {
            parent[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int ele) {
        if(parent[ele] == ele) {
            return ele;
        } else return parent[ele] = find(parent[ele]);
    }
    
    void _union(int ele1, int ele2) {
        ele1 = find(ele1);
        ele2 = find(ele2);
        if(ele1 == ele2) return ;
        if(rank[ele1] > rank[ele2]) {
            parent[ele2] = ele1;
            rank[ele1] += rank[ele2];
        } else {
            parent[ele1] = ele2;
            rank[ele2] += rank[ele1];
        }
    }
};