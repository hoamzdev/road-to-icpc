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

//LCS

void solve(){
    string s,t;cin >> s >> t;
    int n = s.size();
    int m = t.size();

    int dp[n + 1][m + 1];//dp[i][j] : la chieu dai xau con chung dia nhat tinh den index i cua s va index j cua t

    memset(dp,0,sizeof(dp));

    rep(i,1,n){
        rep(j,1,m){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    // cout << dp[n][m] << endl;

    string ans = "";

    int i = n,j = m;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]) {
            ans.push_back(s[i - 1]);
            --i;--j;
        }
        else if(dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }
    reverse(all(ans));
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