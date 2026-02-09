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
    int n;cin >> n;
    int a[n + 1][n + 1];
    rep(i,1,n)rep(j,1,n) cin >> a[i][j];

    int dp[1 << n][n + 1];

    rep(i,0,(1 << n) - 1)rep(j,1,n) dp[i][j] = INT_MAX;

    for(int i=0;i<n;i++) dp[1 << i][i + 1] = 0;//gia tri chi phi toi thieu tinh den khi di den dat nuoc thi i

    for(int mask = 0;mask < 1 << n;mask++){
        for(int i=1;i<=n;i++){
            if(dp[mask][i] == INT_MAX) continue;
            for(int j=0;j<n;j++){
                if(!((mask >> j) & 1)){
                    int newMask = mask | (1 << j);
                    dp[newMask][j + 1] = min(dp[newMask][j + 1],dp[mask][i] + a[i][j + 1]);
                }
            }
        }
    }

    int ans = INT_MAX;
    ///dp[n][i] : chi phi toi thieu khi di het n nuoc va ket thguc tai nuoc thu i

    for(int i=1;i<=n;i++) ans = min(ans,dp[(1 << n) - 1][i]);

    cout << ans << endl;

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