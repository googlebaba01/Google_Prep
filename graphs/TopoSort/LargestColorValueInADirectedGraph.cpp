#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(n,0);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<vector<int>>count(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            count[i][colors[i]-'a']++;
        }

        int max_count = 0;
        int visited = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;
            for(int v:adj[curr]){
               for(int i=0;i<26;i++){
                count[v][i] = max(count[v][i],count[curr][i] + (colors[v] - 'a' == i?1:0));
               }
               if(--inDegree[v] == 0) q.push(v);
            }

            max_count = max(max_count,*max_element(count[curr].begin(),count[curr].end()));

        }
        return (visited == n) ? max_count : -1;
        
    }
};