#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:
    int gameRoutes(int n, vector<vector<int>>&edges){
        unordered_map<int ,vector<int>>adj;
        vector<int>inDegree(n+1,0),dp(n+1);
        dp[1] = 1;
        for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
        }

        queue<int>q;
        for(int i=1;i<=n;i++){
        if(inDegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
         int curr = q.front();
         q.pop();

         for(auto nbr:adj[curr]){
            if(--inDegree[nbr] == 0) q.push(nbr);

            dp[nbr] += dp[curr];
            dp[nbr]%=1000000007;
            } 
        }
        return dp[n];
    }
};

int main(){

    Solution sol;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    cout<<"Answer "<<sol.gameRoutes(n,edges)<<endl;

    return 0;

}



// DFS 

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<int> dp;
vector<bool> visited;
int n;

int dfs(int node) {
    if (node == n) return 1;
    if (visited[node]) return dp[node];
    
    visited[node] = true;
    int totalPaths = 0;
    
    for (int neighbor : adj[node]) {
        totalPaths = (totalPaths + dfs(neighbor)) % MOD;
    }

    return dp[node] = totalPaths;
}

int main() {
    int m;
    cin >> n >> m;

    adj.resize(n + 1);
    dp.resize(n + 1, 0);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << dfs(1) << endl;
    return 0;
}
