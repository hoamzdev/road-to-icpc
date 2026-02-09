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
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

int a[N];
int T[4 * N + 1];

void init(int node, int l, int r){
    if(l == r) {
        T[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = min(T[node * 2],T[node * 2 + 1]);
}

int get_min(int node, int l, int r, int u, int v){
    if(v < l || u > r) return INT_MAX;

    if(u <= l && v >= r) return T[node];

    int m = l + (r - l) /2;

    return min(get_min(node * 2,l,m,u,v),get_min(node * 2 + 1,m + 1,r,u,v));
}


void solve(){
    int n,q;cin >> n >> q;
    rep(i,1,n) cin >> a[i];

    init(1,1,n);

    while(q--){
        int u,v;cin >> u >> v;
        cout << get_min(1,1,n,u,v) << endl;
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
    // cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa