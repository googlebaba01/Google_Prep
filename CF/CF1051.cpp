// #include <bits/stdc++.h>
// using namespace std;

// A
// string solve(int n, vector<int>& p) {
//     vector<int> a(n);
//     for (int k = n; k>=1; k--) {
//         int pos = -1;
//         for (int s = 0; s <= n - k; s++) {
//             bool ok = true;
//             for (int i = s; i < s + k; i++) 
//                 if (a[i] + 1 > p[i]) { ok = false; break; }
//             if (ok) { pos = s; break; }
//         }
//         if (pos == -1) return "NO";
//         for (int i = pos; i < pos + k; i++) a[i]++;
//     }
//     return a == p ? "YES" : "NO";
// }

// B
// long long solve(int n, int k, vector<long long>& p, vector<int>& v) {
  
//     sort(p.rbegin(), p.rend()); 
//     sort(v.begin(), v.end());   
    
//     long long totSum = accumulate(p.begin(), p.end(), 0LL);
//     long long fre = 0;
//     int l = 0;

//     for (int x : v) {
//         if (l + x - 1 >= n) continue;
//         fre += p[l + x - 1];        
//         l += x;                       
//     }
//     return totSum - fre;
// }


// C

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin>>t;
    
//     while(t--){
//         int n;
//         cin>>n;
        
//         vector<vector<int>> g(n+1);
        
//         for(int i=0;i<n-1;i++){
          
//             int u,v;
//             long long x,y;
//             cin>>u>>v>>x>>y;
            
//             if(x>y) g[u].push_back(v);
//             else g[v].push_back(u);
//         }
        
//         vector<int> indeg(n+1),p(n+1);
        
//         for(int u=1;u<=n;u++) for(int v:g[u]) indeg[v]++;
        
//         queue<int> q;
        
//         for(int i=1;i<=n;i++) if(!indeg[i]) q.push(i);
        
//         vector<int> ord;
        
//         while(!q.empty()){
//             int u=q.front();
//             q.pop();
//             ord.push_back(u);
            
//             for(int v:g[u]) if(--indeg[v]==0) q.push(v);
//         }
        
//         for(int i=0;i<n;i++) p[ord[i]]=n-i;
        
//         for(int i=1;i<=n;i++) cout<<p[i]<<" ";
        
//         cout<<"\n";
//     }
// }

//  D

// const int MOD = 1e9+7;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t; 
//     cin >> t;
//     while (t--) {
//         int n; 
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) cin >> a[i];

//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         dp[0][0] = 1;

//         for (int v : a) {
//             vector<vector<int>> newdp = dp;

//             for (int la = 0; la <= n; la++) {
//                 for (int lb = 0; lb <= n; lb++) {
//                     int cur = dp[la][lb];
//                     if (!cur) continue;

//                     if (v >= la) {
//                         newdp[v][lb] = (newdp[v][lb] + cur) % MOD;
//                     }
//                     else if (v >= lb) {
//                         newdp[la][v] = (newdp[la][v] + cur) % MOD;
//                     }
//                 }
//             }
//             dp.swap(newdp);
//         }

//         long long ans = 0;
//         for (int la = 0; la <= n; la++) {
//             for (int lb = 0; lb <= n; lb++) {
//                 ans = (ans + dp[la][lb]) % MOD;
//             }
//         }
//         cout << ans << "\n";
//     }
// }

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;

        for (int v : a) {
            vector<vector<int>> newdp = dp;

            vector<int> preA(n+2,0), preB(n+2,0);

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    preA[i+1] = (preA[i+1] + dp[i][j]) % MOD;
                    preB[j+1] = (preB[j+1] + dp[i][j]) % MOD;
                }
            }

            for (int la = 0; la <= n; la++) {
                for (int lb = 0; lb <= n; lb++) {
                    int cur = dp[la][lb];
                    if (!cur) continue;

                    if (v >= la) newdp[v][lb] = (newdp[v][lb] + cur) % MOD;
                    
                    else if (v >= lb) newdp[la][v] = (newdp[la][v] + cur) % MOD;
                }
            }

            dp.swap(newdp);
        }

        long long ans = 0;
        for (int la = 0; la <= n; la++)
            for (int lb = 0; lb <= n; lb++)
                ans = (ans + dp[la][lb]) % MOD;

        cout << ans << "\n";
    }
}
