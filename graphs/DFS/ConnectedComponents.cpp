#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int src, vector<int>&vis, unordered_map<int, vector<int>>&adj){
        vis[src] = 1;
        for(auto x:adj[src]){
            if(!vis[x]) dfs(x,vis,adj);
        }
    }

    int minSwapsCouples(vector<int>& row) {
        map<int,int> mp;
        for(int i = 0; i < row.size(); i++){
            mp[row[i]] = i;  // map person to index
        }

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < row.size(); i++){
            int CA = row[i];          // ✅ actual person
            int CB = CA ^ 1;          // ✅ their partner
            int nodeA = i / 2;        // seat-pair index of person A
            int nodeB = mp[CB] / 2;   // seat-pair index of partner

            adj[nodeA].push_back(nodeB);
            adj[nodeB].push_back(nodeA);
        }

        int c = 0;
        int N = row.size() / 2;
        vector<int> vis(N, 0);
        for(int i = 0; i < N; i++){
            if(!vis[i]) {
                dfs(i, vis, adj);
                c++;
            }
        }
        return N - c;
    }
};
