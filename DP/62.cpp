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
    vector<double> a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    vector<vector<double>> dp(n + 1,vector<double> (n + 1,0));

    //dp[i][j] : la xac xuat de co duoc j lan xuat hien mat ngua khi tung den dong xu thu i
    dp[0][0] = 1.0;//100% 
    rep(i,1,n){
        //if a[i] la xac xuat xh mat ngua dp[i][j] = dp[i-1][j-1] * a[i]
        //if a[i] la xac xuat xh mat xap dp[i][j] = dp[i-1][j] * (1 - a[i])
        for(int j=0;j<=n;j++){
            if(j > 0){
                dp[i][j] = dp[i-1][j-1] * a[i];
            }
            dp[i][j] += dp[i-1][j] * (1.0 - a[i]);
        }
    }

    double ans = 0;

    for(int i = n/2 + 1;i<=n;i++){
        ans += dp[n][i];
    }

    printf("%.10lf\n",ans);

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