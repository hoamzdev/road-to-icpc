#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n,x;cin >> n >> x;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++) cin >> a[i];

    int dp[x + 1];//dp[i] : so cach de co duoc tong = i
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j = a[i];j<=x;j++){
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x];
}

//acc

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa