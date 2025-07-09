#include<bits/stdc++.h>
using namespace std;

int main(){
    // int nodes = 6;
    vector<vector<int>>edges = {{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};

    map<int,vector<int>>graph;

    for(int i=0;i<edges.size();i++){
        int node = edges[i][0];
        int val = edges[i][1];

        graph[node].push_back(val);
    }

    for(auto graphComponent : graph){
        cout<<graphComponent.first<<"==>";
        for(int i=0;i<graphComponent.second.size();i++){
            cout<<graphComponent.second[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
