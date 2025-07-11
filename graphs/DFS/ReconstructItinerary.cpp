#include<bits/stdc++.h>
using namespace std;

//  in the graphs all the game about adj list how will you make it 

// soln 1 = > Hierholzer's Algorithm 

/*The input graph is a directed graph.

You are guaranteed an Eulerian Path (i.e., a path that uses every edge exactly once).

Start from "JFK" and always go as deep as possible along the smallest lexical edge.

When stuck, backtrack and build the final path in reverse order.*/

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> itinerary;

    void dfs(string node) {
        auto& pq = adj[node];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }
        itinerary.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph (min-heap for lexical order)
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end()); // Hierholzer gives reverse path
        return itinerary;
    }
};


// soln 2 => 
/*
     Now in this question we just have to keep removing the edges 1 by 1
     Better to use multiset 
*/
void dfs( map<string,multiset<string>> &m,string node,vector<string>&ans) {
        vector<string> temp;
        for(auto a:m[node]) {
            temp.push_back(a);
        }
        for(auto a:temp) {
            if(m[node].find(a)!=m[node].end()) {
                m[node].erase(m[node].find(a));
                dfs(m,a,ans);
            }  
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> m;
        for(auto a : tickets) {
            m[a[0]].insert(a[1]);
        }
        vector<string> ans;
        dfs(m,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }