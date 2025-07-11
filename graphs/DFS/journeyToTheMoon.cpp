#include<bits/stdc++.h>
using namespace std;

void dfs(int srcNode, vector<int>&vis, vector<int>g[], int & cnt){

    vis[srcNode] = 1;
    cnt ++;

    for(auto x:g[srcNode]){
        if(!vis[x]) dfs(x,vis,g,cnt);
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int>g[v];

    for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;

    g[x].push_back(y);
    g[y].push_back(x);
    }

    vector<int>solution;
    vector<int>vis(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            int cnt = 0;
            dfs(i,vis,g,cnt);
            solution.push_back(cnt);
        }
    }

    int totalWays = v*(v-1)/2;
    
    for(int i=0;i<solution.size();i++){
        int currWays = solution[i] * (solution[i] -1)/2;
        totalWays -= currWays;
    }
    cout << totalWays << endl;
return 0;
}