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

//https://atcoder.jp/contests/dp/tasks/dp_a

//acc

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    int dp[n + 3];//chi phi nho nhat de nen dc hon do i = dp[i]

    rep(i,1,n) dp[i] = mod;

    dp[1] = 0;

    rep(i,1,n - 1){
        dp[i + 1] = min(dp[i + 1],dp[i] + abs(a[i] - a[i + 1]));
        dp[i + 2] = min(dp[i + 2],dp[i] + abs(a[i] - a[i + 2]));
    }

    cout << dp[n] << endl;
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