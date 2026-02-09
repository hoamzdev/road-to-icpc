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
    string s,t;cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1];
    memset(dp,0,sizeof(dp));
    //dp[i][j] : lan  do dai day con chung da nhat ket thuc tai i cua s va ket thuc tai j cuart t

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
            }
            else dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }

    // cout << dp[n][m] << endl;

    int i = n,j = m;
    string ans = "";
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            ans.push_back(s[i - 1]);
            --i;
            --j;
        }
        else if(dp[i][j - 1] < dp[i-1][j]) --i;
        else --j;
    }

    reverse(all(ans));
    
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
    // cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa