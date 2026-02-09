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
const ll mod=1e9+7;
const ll modr=1e9+9;

int T[4 * N + 1];
int lazy[4 * N + 1];

void push(int node, int l,int r){
    if(lazy[node] != 0){
        int m = l + (r - l) / 2;
        T[node * 2] = (m - l + 1) - T[node * 2];
        lazy[node * 2] = 1 - lazy[node * 2];
        T[node * 2 + 1] = (r - m) - T[node * 2 + 1];
        lazy[node * 2 + 1] = 1 - lazy[node * 2 + 1];
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int u, int v){
    if(v < l || u > r) return;

    if(u <= l && v >= r){
        T[node] = (r - l + 1) - T[node];
        lazy[node] = 1 - lazy[node];
        return;
    }
    push(node,l,r);
    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v);
    update(node * 2 + 1,m + 1,r,u,v);

    T[node] = T[node * 2] + T[node * 2 + 1];

}

int get_on(int node, int l, int r, int u, int v){
    if(v < l || u > r) return 0;

    if(u <= l && v >= r) return T[node];
    push(node,l,r);

    int m = (l + r) / 2;
    int le = get_on(node * 2,l,m,u,v);
    int ri = get_on(node * 2 + 1,m + 1,r,u,v);

    return le + ri;

}

void solve(){
    int n,m;cin >> n >> m;
    while(m--){
        int t,l,r;cin >> t >> l >> r;
        if(t == 0){
            update(1,1,n,l,r);
        }
        else{
            cout << get_on(1,1,n,l,r) << endl;
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