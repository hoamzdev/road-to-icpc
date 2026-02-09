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
    ll n,x;cin >> n >> x;
    vll a(n + 1),b(n + 1),c(n + 1);
    rep(i,1,n){
        cin >> a[i] >> b[i] >> c[i];
    }

    ll _0k = 0;
    rep(i,1,n){
        _0k += (b[i] - 1) * a[i];
    }

    if(_0k >= x){
        cout << 0 << endl;
        return;
    }

    ll M = LLONG_MIN;

    rep(i,1,n){
        M = max(M,(b[i] * a[i]) - c[i]);
    }

    if(M <= 0){
        cout << -1 << endl;
        return;
    }

    x -= _0k;

    cout << (x + M - 1) / M << endl;

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