#include<bits/stdc++.h> 
using namespace std;

// soln 1 
class Solution {
    private:
    bool detect(int src,unordered_map<int,vector<int>>& adj, vector<int>&vis){
        
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto adjacentNode:adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(par != adjacentNode){
                    return true;
                }
            }
        }
        return false;
        
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int ,vector<int>>adj;
        for(auto edge:edges){
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(V,0);
        bool ans = false;
        for(int i=0;i<V;i++){
             if (!vis[i]) {         
            if (detect(i, adj, vis)) return true;
        }
        }
        return false;
    }
};
