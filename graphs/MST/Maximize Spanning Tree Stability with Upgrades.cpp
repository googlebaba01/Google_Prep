#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);  // path compression
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    bool canBuildST(int n, vector<vector<int>>& edges, int k , int minEdWT) {
        DSU dsu(n);
        int upgradeCount = 0;
        vector<tuple<int, int, int , bool>> edgeList;

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) {
                if (s < minEdWT) return false;
                dsu.unite(u, v);
            } else {
                if (s >= minEdWT) {
                    dsu.unite(u, v);
                } else if (2 * s >= minEdWT) {
                    edgeList.emplace_back(2 * s, u, v, true);
                }
            }
        }

        for (auto &[s, u, v, upgraded] : edgeList) {
            if (dsu.find(u) != dsu.find(v)) {
                if (upgradeCount >= k) return false;
                dsu.unite(u, v);
                upgradeCount++;
            }
        }

        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 1, hi = 0, ans = -1;

        DSU dsu(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) {
                if (!dsu.unite(u, v)) return -1;
                hi = max(hi, s);
            } else {
                hi = max(hi, 2 * s);
            }
        }

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canBuildST(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};