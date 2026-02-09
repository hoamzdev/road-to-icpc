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
    int dp[n + 1];
    memset(dp,0x3f,sizeof(dp));

    rep(i,1,9) dp[i] = 1;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        string x = to_string(i);
        for(int j=0;j<(int)x.size();j++){
            if(i >= x[j] - '0'){
                dp[i] = min(dp[i],dp[i - (x[j] - '0')] + 1);
            }
        }
    }

    cout << dp[n] << endl;
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