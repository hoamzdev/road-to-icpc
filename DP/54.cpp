#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

vi adj[N];
vi dp(N,0);//do dai duong di dai nhat ket thuc tai i
int in[N];

void solve(){
    int n,m;cin >> n >> m;
    rep(i,1,m){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }    

    queue<int> q;
    rep(i,1,n){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]){
            in[v]--;
            if(in[v] == 0) q.push(v);
            dp[v] = max(dp[v],dp[u] + 1);
        }
    }

    int ans = 0;

    rep(i,1,n){
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;

    //acc
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa