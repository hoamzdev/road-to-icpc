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
    ll a,b;cin >> a >> b;
    if(a > b) swap(a,b);

    ll gcd = b - a;

    if(gcd == 0){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    
    if(gcd == 1){
        cout << 1 << ' ' << 0 << endl;
        return;
    }

    ll ans = min(a % gcd,gcd - a % gcd);

    cout << gcd << ' ' << ans << endl;
    
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