#include<bits/stdc++.h>
using namespace std;

// Bipartite means : The cyclic graph with odd len cycle 
class Solution {
    private:
    bool dfs(int start, vector<int>&color,vector<vector<int>>&graph, int req_color){
        if(color[start] == -1){
            color[start] = req_color;
            int ans = 1;
            for(auto x:graph[start]){
                ans &= dfs(x,color,graph,1-req_color);
            }
            return ans;
        }
        else {
            return color[start] == req_color;
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!dfs(i,color,graph,0)) return false;
            }
        }
        return true; 
    }
};