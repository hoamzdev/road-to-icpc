#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
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


void solve(){
    int n,m;cin >> n >> m;
    vi adj[n + 1];
    vi in(n + 1,0);
    for(int i=1;i<=m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    queue<int> que;

    for(int i=1;i<=n;i++){
        if(in[i] == 0) que.push(i);
    }

    vi dp(n + 1,0);//dp[i]: khoang cach dai nhat ket thuc tai dinh i

    while(!que.empty()){
        int u = que.front();que.pop();
        // cout << u << ' ';
        for(int v : adj[u]){
            // cout << v << ' ';
            dp[v] = max(dp[v],dp[u] + 1);
            in[v]--;
            if(in[v] == 0) que.push(v);
        }
        cout << endl;
    }

    int ans = 0;

    for(int i=1;i<=n;i++) ans = max(ans,dp[i]);

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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