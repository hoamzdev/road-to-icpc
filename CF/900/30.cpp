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
    vll arr(n + 1,0);
    ll sum = 0;
    rep(i,1,n) cin >> arr[i];
    rep(i,1,n){
        sum += arr[i];
    }

    ll a = sum;
    ll b = sum - 1;
    if(a & 1) b/=2;
    else a/=2;

    ll res = (a % mod) * (b % mod) % mod;

    ll thua = 0;

    rep(i,1,n){
        ll tmp = (arr[i] * (arr[i] - 1) / 2) % mod;
        thua = (thua + tmp) % mod;
    }

    cout << (res - thua + mod) % mod << endl;

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