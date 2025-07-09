#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param graph: the graph
     * @return: the shortest path for all nodes
     */
    int shortestPathLength(vector<vector<int>> &graph) {
    int n = graph.size();
    int allStateMask = (1 << n) - 1;
    int result = 0;

    queue<pair<int, int>> q; // node, mask
    set<pair<int, int>> vis; // node, mask

    for (int i = 0; i < n; i++) {
        int maskVal = (1 << i);
        q.push({i, maskVal});
        vis.insert({i, maskVal});
    }

    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            auto [currNode, currMask] = q.front(); q.pop();

            if (currMask == allStateMask) return result;

            for (int adj : graph[currNode]) {
                int newMask = currMask | (1 << adj);
                if (vis.count({adj, newMask}) == 0) {
                    q.push({adj, newMask});
                    vis.insert({adj, newMask});
                }
            }
        }
        result++;
    }
    return -1;
}
};