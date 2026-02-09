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
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n,W;cin >> n >> W;
    //trong luong w
    //gia tri v
    vi w(n + 1,0),v(n + 1,0);

    rep(i,1,n){
        cin >> w[i] >> v[i];
    }

    ll dp[W + 1];//dp[i] : li nhuan lon nhat dat duoc khi khoi luong la i
    memset(dp,0,sizeof(dp));

    rep(i,1,n){
        for(int j = W;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
        }
    }
    
    ll ans = 0;
    rep(i,1,W) ans = max(ans,dp[i]);


    cout << ans << endl;

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