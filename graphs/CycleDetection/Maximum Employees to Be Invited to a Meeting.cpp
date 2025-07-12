#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size() , longestCycle = 0, twoCycleInventions = 0;
        vector<int>inDegree(n,0),depth(n,1);

        for(int person=0;person<n;person++){
            inDegree[fav[person]]++;
        } 
        queue<int>q;
        for(int person=0;person<n;person++){
            if(inDegree[person] == 0) {
                q.push(person);
            }
        } 

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int next = fav[curr];
            depth[next] = max(depth[next],depth[curr]+1);
            if(--inDegree[next] == 0){
                q.push(next);
            }
        }

        for(int person=0;person<n;person++){
            if(inDegree[person] == 0) continue;
            int cycleLenth = 0, curr = person;

            while(inDegree[curr] != 0){
                inDegree[curr] = 0;
                cycleLenth++;
                curr = fav[curr];
            }
            if(cycleLenth == 2){
                twoCycleInventions += depth[person] + depth[fav[person]];
            }
            else {
                longestCycle = max(longestCycle, cycleLenth);
            }
        }
        return max(longestCycle,twoCycleInventions);  
    }
};