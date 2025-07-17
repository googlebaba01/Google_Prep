#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int *p,*r;
    int find(int x){
        if(x == p[x]) return x;
        return p[x] = find(p[x]); 
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y) ;

        if(x == y) return ;

        if(r[x] > r[y]){
            p[y] = x;
            r[x]++;
        }
        else {
            p[x] = y;
            r[y]++;
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int>inDegree(n+1,-1);

        int rem1 = -1, rem2 = -1;

        for(int i =0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(inDegree[edges[i][1]] != -1){
                rem2 = i;
                rem1 = inDegree[edges[i][1]];
            }
            inDegree[edges[i][1]] = i;
        }

        p = new int[n+1];
        r = new int[n+1];

        for(int i=0;i<=n;i++){
            p[i] = i;
            r[i] = 0;
        }
        for(int i =0;i<n;i++){
            if(i == rem2) continue;
            vector<int>v = edges[i];

            if(find(v[0]) == find(v[1])){
                if(rem1 != -1) return edges[rem1]; // cycle  + 2 inDegree
                else return edges[i]; // remove cycle
            }
            unite(v[0],v[1]);
        }
        return edges[rem2];

    }
};