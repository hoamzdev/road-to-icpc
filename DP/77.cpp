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
    int n,w;cin >> n >> w;
    vi a(n + 1,0);
    vi c(n + 1,0);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> c[i];

    vi dp(w + 1,false);
    dp[0] = true;//khong chon gi

    rep(i,1,n){
        vi cnt(w + 1,0);//cnt[j] da dung bao nhieu lan a[i] vao tong j
        for(int j=a[i];j <= w;j++){
            if(dp[j]) continue;
            if(dp[j - a[i]] && cnt[j - a[i]] < c[i]){// -> them 1 lan dung a[i]
                //cnt[j - a[i]]: so luong a[i] da dc su dung
                cnt[j] = cnt[j - a[i]] + 1;
                dp[j] = true;
            }
        }
    }

    if(dp[w]) cout << "YES\n";
    else cout << "NO\n";

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