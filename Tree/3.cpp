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
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

int n,q;
int a[N];
ll T[4 * N];
ll delta[4 * N];

void init(int node, int l, int r){
    if(l == r){
        T[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = max(T[node * 2],T[node * 2 + 1]);
    
}


void update(int node, int l ,int r, int u, int v, int val){
    if(v < l || u > r){
        return;
    }

    if(u <= l && v >= r){
        T[node] += val;
        delta[node] += val;
        return;
    }

    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,val);
    update(node * 2 + 1,m + 1,r,u,v,val);

    T[node] = max(T[node * 2],T[node * 2 + 1]) + delta[node];

}


ll get_max(int node, int l,int r,int u,int v){
    if(v < l || u > r){
        return -mod;
    }

    if(u <= l && v >= r){
        return T[node];
    }


    int m = l + (r - l) / 2;

    ll L = get_max(node * 2,l,m,u,v);
    ll R = get_max(node * 2 + 1,m + 1,r,u,v);

    return max(L,R) + delta[node];

}

void solve(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    init(1,1,n);
    cin >> q;
    while(q--){
        int tt;cin >> tt;
        if(tt == 1){
            int x,y,val;cin >> x >> y >> val;
            update(1,1,n,x,y,val);
        }
        else{
            int x,y;cin >> x >> y;
            cout << get_max(1,1,n,x,y) << endl;
        }
    }
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