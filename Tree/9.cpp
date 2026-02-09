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
const ll N=4e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ll a[N];
ll T[4 * N + 1];
ll lazy[4 * N + 1];

void init(int node, int l, int r){
    if(l == r){
        T[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = min(T[node * 2],T[node * 2 + 1]);

}

void update(int node, int l, int r, int u,int v,int val){
    if(v < l || u > r) return;
    if(u <= l && v >= r) {
        T[node] += val;
        lazy[node] += val;
        return;
    }

    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,val);
    update(node * 2 + 1,m + 1,r,u,v,val);

    T[node] = min(T[node * 2],T[node * 2 + 1]) + lazy[node];

}

ll get_min(int node, int l, int r, int u, int v){
    if(v < l || u > r) return LLONG_MAX;

    if(u <= l && v >= r) return T[node];

    int m = l + (r - l) / 2;

    ll le = get_min(node * 2,l,m,u,v);
    ll ri = get_min(node * 2 + 1,m + 1,r,u,v);
    


    ll res = min(le,ri);

    if(res >= LLONG_MAX) return LLONG_MAX;
    return res + lazy[node];

}

void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];

    init(1, 1, n);

    int q; cin >> q;
    cin.ignore();
    string line;

    while (q--) {
        getline(cin, line);
        if (line.empty()) continue;
        stringstream ss(line);
        ll l, r, v;

        if (ss >> l >> r >> v) {
            l++; r++;
            if (l <= r) update(1, 1, n, l, r, v);
            else {
                update(1, 1, n, l, n, v);
                update(1, 1, n, 1, r, v);
            }
        } else {
            ss.clear(); ss.str(line);
            ss >> l >> r;
            l++; r++;
            if (l <= r) cout << get_min(1, 1, n, l, r) << endl;
            else {
                cout << min(get_min(1, 1, n, l, n), get_min(1, 1, n, 1, r)) << endl;
            }
        }
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