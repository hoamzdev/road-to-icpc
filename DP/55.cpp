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
    int n,m;cin >> n >> m;//n hang ,m cot
    char a[n + 1][m + 1];
    rep(i,1,n)rep(j,1,m) cin >> a[i][j];
    
    int dp[n + 1][m + 1];//dp[i][j] : so duong di den op i,j

    memset(dp,0,sizeof(dp));

    dp[1][1] = 1;

    rep(i,1,n){
        rep(j,1,m){
            if(i == 1 && j == 1) continue;
            //so duong di den o i,j
            if(a[i][j] != '.') dp[i][j] = 0;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n][m] << endl;

}

//acc

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