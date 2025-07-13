#include<bits/stdc++.h>
using namespace std;

 class Solution {
    private:
    void dfs(int node, vector<int>&vis, unordered_map<int, vector<int>>& adj
, stack<int>&s){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it, vis, adj, s);
        }
        s.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        stack<int>s;
        vector<int>vis(V,0);
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,s);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
            
        }
        return ans;
        
    }
};