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
    vi a(n,0);
    int max_a = INT_MIN;
    int min_a = INT_MAX;
    rep(i,0,n-1) {
        cin >> a[i];
        max_a = max(max_a,a[i]);
        min_a = min(min_a,a[i]);
    }

    vi b = a;
    sort(all(b));
    if(a == b){
        cout << -1 << endl;
        return;
    }

    ll ans = LLONG_MAX;

    rep(i,0,n-1){
        if(a[i] == b[i]) continue;
        ans = min(ans,1ll * max(a[i] - min_a,max_a - a[i]));
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