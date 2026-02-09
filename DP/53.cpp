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



void solve(){
    int n,W;cin >> n >> W;
    ll dp[N + 3];//dp[i] : khoi luong nho nhat de -> tong gia tri i
    rep(i,1,N) dp[i] = mod;

    dp[0] = 0;

    rep(i,1,n){
        int w,v;cin >> w >> v;
        for(int j = N;j>=v;j--){
            dp[j] = min(dp[j],dp[j - v] + w);
        }
    }

    int ans = 0;

    for(int gt = 0;gt <= N;gt++){
        if(dp[gt] <= W){
            ans = gt;
        }
    }

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