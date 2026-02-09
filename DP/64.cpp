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
    
    int dp[n+1][1 << n];

    memset(dp,-0x3f,sizeof(dp));

    dp[0][0] = 0;

    rep(i,1,n){
        for(int mask=0;mask < (1 << n);mask++){
            for(int j=1;j<=n;j++){
                //neu nhu cot j chua dc dung (tuc la bit j - 1 cua mask = 0)
                if(!((mask >> (j - 1)) & 1)){
                    //-> bat bit j - 1 nen (chon cot j)
                    int newMask = mask | (1 << (j - 1));
                    dp[i][newMask] = max(dp[i][newMask],dp[i-1][mask] + a[i][j]);
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << endl;

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
    int n = t;
    while(t--){
        cout << "Case " << n - t << ": ";
        solve();
    }
}
//Road to ICPC 2026 - by hwa