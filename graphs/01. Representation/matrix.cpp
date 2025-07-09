#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes = 6;
    vector<vector<int>>edges = {{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};
    int adjmatrix[nodes][nodes];

    memset(adjmatrix,0,sizeof(adjmatrix));

    for(int i=0;i<edges.size();i++){
        adjmatrix[edges[i][0]][edges[i][1]] = 1;  
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}