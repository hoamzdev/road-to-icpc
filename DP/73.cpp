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
    int n,q;cin >> n >> q;
    char c[n + 1][n + 1];
    rep(i,1,n)rep(j,1,n) cin >> c[i][j];

    int dp[n + 1][n + 1];

    memset(dp,0,sizeof(dp));

    rep(i,1,n){
        rep(j,1,n){
            if(i == 1 && j == 1) dp[i][j] = (c[i][j] == '*');
            else if(i == 1) dp[i][j] = dp[i][j-1] + (c[i][j] == '*');
            else if(j == 1) dp[i][j] = dp[i-1][j] + (c[i][j] == '*');
            else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (c[i][j] == '*');
        }
    }

    while(q--){
        int a,b,c,d;cin >> a >> b >> c >> d;
        cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa