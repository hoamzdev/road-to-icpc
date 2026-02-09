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
    int n,W;cin >> n >> W;
    
    vi w(n + 1,0);
    vi v(n + 1,0);

    ll sumV = 0;
    rep(i,1,n){
        cin >> w[i] >> v[i];
        sumV += v[i];
    }


    vll dp(sumV + 1,mod * 2);//dp[i]: trong luong nho nhat de dat dc chi phi la i

    dp[0] = 0;

    rep(i,1,n){
        for(int j = sumV;j>=v[i];j--){
            dp[j] = min(dp[j],dp[j - v[i]] + w[i]);
        }
    }


    ll ans = 0;

    rep(i,1,sumV){
        if(dp[i] <= W){
            ans = i;
        }
    }

    cout << ans << endl;

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