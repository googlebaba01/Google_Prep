#include<bits/stdc++.h>
using namespace std;


/*

    TC O(E*V)
    SC O(V)
    
    relax for n-1 times 
    relax one more time to detect -ve cycle
    
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,6000);
        dist[k] = 0;

        for(int i=0;i<n-1;i++){
            for(auto &t:times){
                if(dist[t[1]] > dist[t[0]] + t[2]){
                    dist[t[1]] = dist[t[0]] + t[2];
                }
            }
        }
        int ans = INT_MIN;
         for(int i=1;i<=n;i++) {
            ans=max(ans,dist[i]);
        }
        return ans==6000?-1:ans;  
    }
};