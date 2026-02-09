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
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n,w;cin >> n >> w;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];
    int dp[w + 1];//dp[i]: so luong so tao ra tong i
    
    rep(i,1,w) dp[i] = 1e6 + 5;

    dp[0] = 0;

    for(int i=1;i<=w;i++){
        for(int j=1;j<=n;j++){
            if(i >= a[j]) dp[i] = min(dp[i],dp[i - a[j]] + 1);
        }
    }

    if(dp[w] == 1e6 + 5) cout << -1 << endl;
    else cout << dp[w] << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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