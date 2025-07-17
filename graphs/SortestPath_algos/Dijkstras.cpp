#include<bits/stdc++.h>
using namespace std;

/*
	TC O(V+E)*logV
	PC O(V)

	Implementations wise its like BFS ( instead of queue we use priority queue)

	0-Is there are negetive edges but not in a cycle then we an use this algo
	1-If there are negetive edges in a cycle we cant use this also 
	2-for this we use bellman ford
	3-It there are negetive weight cycles then we cant use bellman ford too, we 
	can just detect negetive weight cycles using bellman ford

*/

class Solution {
public:
    #define ll long long
    void Djk(int src, unordered_map<ll, vector<pair<ll,ll>>>&graph, vector<ll>& dis){
        dis[src] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
        q.push({0,src});

        while(!q.empty()){
            auto ele = q.top();
            q.pop();

            ll w = ele.first;
            ll node = ele.second;
            if (dis[node] < w) continue;

           for (auto& [v, w1] : graph[node]) {
                if (dis[v] > dis[node] + w1) {
                    dis[v] = dis[node] + w1;
                    q.push({dis[v], v});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        unordered_map<ll, vector<pair<ll,ll>>>m,m1;

        for(auto &e :edges){
            m[e[0]].push_back({e[1],e[2]});
            m1[e[1]].push_back({e[0], e[2]});  
        }

        vector<ll>src1Dis(n, LLONG_MAX), src2Dis(n,LLONG_MAX),distDest(n,LLONG_MAX);

        ll ans = LLONG_MAX;
        Djk(src1,m,src1Dis);
        Djk(src2,m,src2Dis);
        Djk(dest,m1,distDest);

        for (int i = 0; i < n; ++i) {
            if (src1Dis[i] != LLONG_MAX && src2Dis[i] != LLONG_MAX && distDest[i] != LLONG_MAX) {
                ans = min(ans, src1Dis[i] + src2Dis[i] + distDest[i]);
            }
        }
        return ans==LLONG_MAX? -1 : ans;   
    }
};