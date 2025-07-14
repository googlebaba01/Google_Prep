#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int *rank, *parent;
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);

        if(u == v) return ;
        if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u]++;
        } 
        else {
            parent[u] = v;
            rank[v]++;
        }
    }

    int mstWtCalculator(int n, vector<vector<int>>& edges, int skipEdge, int compulsoryEdge){
        rank = new int[n];
        parent = new int[n];

        for(int i=0;i<n;i++){
            rank[i] = 0;
            parent[i]=i;
        }

        int EdgeCount = 0;
        int ans = 0;

        if(compulsoryEdge != -1){
            unite(edges[compulsoryEdge][0],edges[compulsoryEdge][1]);
            ans += edges[compulsoryEdge][2];
            EdgeCount++;
        }

        for(int i=0;i<edges.size();i++){
            if(i == skipEdge ) continue;

            if(find(edges[i][0]) != find(edges[i][1])){
                unite(edges[i][0],edges[i][1]);
                ans += edges[i][2];
                EdgeCount++;
            }
        }
        if(EdgeCount != n-1) return INT_MAX;
        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }

        sort(edges.begin(),edges.end(),[](vector<int>&a, vector<int>&b) -> bool {return a[2] < b[2];});

        int originalMstWt = mstWtCalculator(n, edges,-1,-1);

        vector<int>critical, psudo_critical;

        for(int i=0;i<edges.size();i++){
            if(mstWtCalculator(n,edges,i,-1) > originalMstWt) critical.push_back(edges[i][3]);
            else if(mstWtCalculator(n,edges,-1,i) == originalMstWt){
                psudo_critical.push_back(edges[i][3]); 
            }
        }
         return {critical, psudo_critical};
    }
};