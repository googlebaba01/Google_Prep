#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int ,vector<int>>adj;
        for(auto edge:edges){
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            vector<int>dist(n,-1);
            vector<int>parent(n,-1);

            queue<int>q;
            q.push(i);
            dist[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v:adj[u]){
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if(parent[u] != v){
                         int cycleLength = dist[u] + dist[v] + 1;
                        ans = min(ans, cycleLength);
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;

    }
};