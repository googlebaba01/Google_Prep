#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;

    void dfs(int srcNode, int currValue, int currTime, int maxTime,
             unordered_map<int, vector<pair<int, int>>> &adj,
             vector<int> &values) {

        if (currTime > maxTime) return;

        int tmp = values[srcNode];
        currValue += tmp;
        values[srcNode] = 0; // mark as visited for this path
        if (srcNode == 0)
            ans = max(ans, currValue);

        for (auto &neighbor : adj[srcNode]) {
            int nextNode = neighbor.first;
            int travelTime = neighbor.second;
            dfs(nextNode, currValue, currTime + travelTime, maxTime, adj, values);
        }

        values[srcNode] = tmp; // restore after DFS
    }

    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        dfs(0, 0, 0, maxTime, adj, values);
        return ans;
    }
};
