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


ll _pow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (a * res) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


ll getApple(ll a){
    int cnt = 0;
    int lastVal = 0;
    ll res = 0;
    while(a){
        int r = a % 10;
        if(r != lastVal){
            //tinh trc
            res += (lastVal * _pow(cnt,2));
            lastVal = r;
            cnt = 1;
        }
        else cnt++;
        a /= 10;
    }
    res += (lastVal * _pow(cnt,2));
    return res;
}

// pass 3/10 test (TLE)

void solve(){
    ll l,r;cin >> l >> r;
    ll ans = 0;
    rep(i,l,r){
        ll x = getApple(i);
        ans += x;
    }
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