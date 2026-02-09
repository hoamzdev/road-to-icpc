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
    int n;cin >> n;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];
    // int dp[i][j]; so ngay nghi it nhat tinh den ngay i khi ngay i chon vc j de lam
    int dp[103][5];
    rep(i,0,100) rep(j,0,4) dp[i][j] = mod;

    dp[0][0] = 0;//ngay 0, mon 0 -> co 0 ngay nghi

    rep(i,1,n){
        //nghi ngay hom nay
        dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;//nghi ngay hom nay -< so ngay nghi + 1
        if(a[i] == 1 || a[i] == 3){
            //CT ngay hom nay
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }
        if(a[i] == 2 || a[i] == 3){
            //gym ngay hom nay
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }
    }

    int ans = mod;
    rep(i,0,2) ans = min(ans,dp[n][i]);

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