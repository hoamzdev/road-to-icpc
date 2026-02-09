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
const ll N=1e5+5;
const ll mod=2e9+7;
const ll modr=1e9+9;

ll a[N];
multiset<ll> T[N * 4];

void init(int node,int l,int r){
    if(l == r){
        T[node].insert(a[l]);
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node].insert(T[node * 2].begin(),T[node * 2].end());
    T[node].insert(T[node * 2 + 1].begin(),T[node * 2 + 1].end());

}

void update(int node, int l, int r, int idx, int oldVal, int Val) {
    if (idx < l || idx > r) return;//idx ko nam trong l,r 

    auto it = T[node].find(oldVal);
    if (it != T[node].end()) T[node].erase(it);
    T[node].insert(Val);

    if (l == r) return;

    int m = l + (r - l) / 2;
    if (idx <= m) update(node * 2, l, m, idx, oldVal, Val);
    else update(node * 2 + 1, m + 1, r, idx, oldVal, Val);
}

ll get(int node,int l,int r,int u,int v,ll k){
    if(v < l || u > r) return mod;

    if(u <= l && v >= r){
        auto it = T[node].lower_bound(k);
        if(it == T[node].end()) return mod;
        return *it;
    }

    int m = l + (r - l) / 2;

    ll le = get(node * 2, l, m, u, v, k);
    ll ri = get(node * 2 + 1, m + 1, r, u, v, k);
    return min(le,ri);
}

void solve(){
    int n,k;cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    init(1,1,n);
    while(k--){
        int t;cin >> t;
        if(t == 1){
            int i,v;cin >> i >> v;
            update(1,1,n,i,a[i],v);
            a[i] = v;
        }
        else{
            int l,r,k;cin >> l >> r >> k;
            ll ans = get(1,1,n,l,r,k);
            if(ans == mod) cout << -1 << endl;
            else cout << ans << endl;
        }
    }

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