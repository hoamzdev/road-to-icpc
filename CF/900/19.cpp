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
    int n,q;cin >> n >> q;
    vll a(n + 3,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    for(int i=1;i<=n;i++) a[i] += a[i - 1];

    while(q--){
        int l,r,k;cin >> l >> r >> k;
        int sum_1 = a[l - 1];
        int sum_2 = a[n] - a[r];
        if((sum_1 + sum_2 + 1ll * (r - l + 1) * k) & 1) cout << "yes\n";
        else cout << "no\n";
    }

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