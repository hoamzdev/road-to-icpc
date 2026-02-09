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

ll a[N],T[4 * N],lazymul[4 * N],lazyAdd[4 * N];

void init(ll node, ll l, ll r){
    lazymul[node] = 1;
    lazyAdd[node] = 0;
    if(l == r){
        T[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;
}

void push(ll node, ll l, ll r){
    if(lazyAdd[node] == 0 && lazymul[node] == 1) return;

    ll m = l + (r - l) / 2;
    T[node * 2] = (T[node * 2]  * lazymul[node] % mod  + (m - l + 1) * lazyAdd[node] % mod) % mod;
    T[node * 2 + 1] = (T[node * 2 + 1]  * lazymul[node] % mod + (r - m) * lazyAdd[node] % mod) % mod;

    lazymul[node * 2] = (lazymul[node * 2] * lazymul[node] % mod) % mod;
    lazymul[node * 2 + 1] = (lazymul[node * 2 + 1] * lazymul[node] % mod) % mod;

    lazyAdd[node * 2] = (lazyAdd[node * 2]  * lazymul[node] % mod + lazyAdd[node] % mod) % mod;
    lazyAdd[node * 2 + 1] = (lazyAdd[node * 2 + 1]  * lazymul[node] % mod + lazyAdd[node] % mod) % mod;

    lazyAdd[node] = 0;
    lazymul[node] = 1;
}


void update(ll node, ll l,ll r,ll u,ll v,ll valA,ll valB){
    if(v < l || u > r) return;

    if(u <= l && v >= r){
        T[node] = (T[node] * valA % mod + (r - l + 1) * valB % mod) % mod;
        lazyAdd[node] = (lazyAdd[node]  * valA % mod + valB % mod) % mod;
        lazymul[node] = (lazymul[node] * valA % mod) % mod;
        return;
    }


    push(node,l,r);

    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,valA,valB);
    update(node * 2 + 1,m + 1,r,u,v,valA,valB);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;

}

ll getsum(ll node, ll l,ll r,ll u, ll v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r){
        return T[node];
    }

    push(node,l,r);

    int m = l + (r - l) / 2;

    ll le = getsum(node * 2,l,m,u,v);
    ll ri = getsum(node * 2 + 1,m + 1,r,u,v);

    return (le + ri) % mod;
}


void solve(){
    int n,q;cin >> n >> q;

    rep(i,1,n)cin >> a[i];
    init(1,1,n);

    while(q--){
        int t;cin >> t;
        if(t == 1){
            int l,r,x;cin >> l >> r >> x;
            //cong tat ca cac phan tu [L,R] += x
            update(1,1,n,l,r,1,x);
        }
        else if(t == 2){
            //thang [L,R]*= x
            int l,r,x;cin >> l >> r >> x;
            update(1,1,n,l,r,x,0);
        }
        else if(t == 3){
            //gan [L,R] = x
            int l,r,x;cin >> l >> r >> x;
            update(1,1,n,l,r,0,x);
        }
        else{
            int l,r;cin >> l >> r;
            ll ans = getsum(1,1,n,l,r);
            cout << ans << endl;
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