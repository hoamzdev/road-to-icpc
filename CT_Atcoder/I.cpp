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
    vector<double> a(n + 1,0);
    for(int i=1;i<=n;i++) cin >> a[i];

    //dp[i][j] : xac xuat de co j mat ngua khi tung den dong xu thu i
    vector<vector<double>> dp(n + 1,vector<double> (n + 1,0));
    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j > 0) dp[i][j] = dp[i-1][j - 1] * a[i];
            dp[i][j] += dp[i-1][j] * (1 - a[i]);
        }
    }

    double ans = 0.0;

    for(int i=n/2 + 1;i<=n;i++){
        ans += dp[n][i];
    }

    printf("%.10lf\n",ans);

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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