#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool dfs(int i, int j , vector<vector<int>> &v , vector<vector<char>>&grid,char c, int pi, int pj, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != c) return false;

        if(v[i][j]) return true;
        v[i][j] = 1;
        vector<int> dir = {1, 0, -1, 0, 1};

        for(int k=0;k<4;k++){
            int ni = i + dir[k], nj = j + dir[k+1];

            if(ni == pi && nj == pj) continue;
            if(dfs(ni,nj,v,grid,c, i,j,n,m)) return true; 
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 0)
                if(dfs(i, j, v, grid, grid[i][j], -1, -1, n, m))return true;
            }
        }
        return false; 
        
    }
};