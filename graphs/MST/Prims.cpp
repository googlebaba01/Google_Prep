
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>vis(V,0);
        
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto i:adj[node]){
                int currWt = i[1];
                int curNode = i[0];
                
                if(!vis[curNode]){
                    pq.push({currWt, curNode});
                }
                
            }
        }
        return sum;
        
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        int NodesCount = 0;
        int n = points.size();
        vector<int>vis(n,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,0}); // cost,index : 0,1,2,3,4 ..... 

        while(NodesCount < n){
            int currCost = pq.top().first;
            int CurrNode = pq.top().second;
            pq.pop();

            if(vis[CurrNode]) continue;

            vis[CurrNode] = 1;
            cost += currCost;
            NodesCount++;
            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int dist = abs(points[CurrNode][0] - points[v][0]) + abs(points[CurrNode][1]-points[v][1]);
                    pq.push({dist, v});
                }
            }
        }
        return cost;  
    }
};