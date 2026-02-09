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

//gan [L,R] cac a[i] = x -> tinh tong [L,R]

ll a[N],T[4 * N],lazy[4 * N],hashGan[4 * N];

void init(ll node, ll l, ll r){
    if(l == r){
        T[node] = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;
}

void push(ll node,ll l, ll r){
    if(hashGan[node] == 0) return;

    int m = l + (r - l) / 2;
    T[node * 2] = (m - l + 1) * lazy[node] % mod;

    T[node * 2 + 1] = (r - m) * lazy[node] % mod;

    lazy[node * 2] = lazy[node] % mod;
    lazy[node * 2 + 1] = lazy[node] % mod;

    hashGan[node * 2] = true;
    hashGan[node * 2 + 1] = true;

    lazy[node] = 0;
    hashGan[node] = 0;

}

void update(ll node, ll l, ll r, ll u, ll v ,ll val){
    if(v < l || u > r) return;
    if(u <= l && v >= r){
        T[node] = (r - l + 1) * val % mod;
        lazy[node] = val;
        hashGan[node] = 1;
        return;
    }
    push(node,l,r);
    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,val);
    update(node * 2 + 1,m + 1,r,u,v,val);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;

}

ll get_sum(ll node,ll l, ll r, ll u ,ll v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r){
        return T[node];
    }
    push(node,l,r);
    int m = l + (r - l) / 2;
    return get_sum(node * 2,l,m,u,v) + get_sum(node * 2 + 1,m + 1,r,u,v);
}

void solve(){
    int n,q;cin >> n >> q;
    rep(i,1,n) cin >> a[i];
    init(1,1,n);

    while(q--){

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