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



ll getMex(vll ve){
    // int n = (int)ve.size();
    ll start = 0;
    set<ll> s(all(ve));
    while(s.find(start) != s.end()){
        start++;
    }
    return start;
}


void solve(){
    int n;cin >> n;
    vll a(n);vll d(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        d[i] = a[i];
    }

    ll ans = 0;

    for(int i=0;i<n;i++){
        int x = a[i];
        for(int j=0;j<n;j++){
            d[j] -= x;
        }
        ans = max(ans,getMex(d));
        d = a;
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