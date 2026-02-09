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

//truy van 3 nhan cac a[i] nen x lan i nam trong [L,R]
ll a[N],T[4 * N],lazy[4 * N];

void init(ll node, ll l, ll r){
    if(l == r){
        T[node] = a[l];
        lazy[node] = 1;
        return;
    }
    int m = l + (r - l) / 2;
    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);
    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;
}

void push(ll node){
    if(lazy[node] == 1) return;//khong nhan

    T[node * 2] = (T[node * 2] % mod * lazy[node] % mod) % mod;
    T[node * 2 + 1] = (T[node * 2 + 1] % mod * lazy[node] % mod) % mod;

    lazy[node * 2] = (lazy[node * 2] % mod * lazy[node] % mod) % mod;
    lazy[node * 2 + 1] = (lazy[node * 2 + 1] % mod * lazy[node] % mod) % mod;
    lazy[node] = 1;//reset
}


void update(ll node,ll l, ll r, ll u, ll v, ll val){
    if(v < l || u > r) return;

    if(u <= l && v >= r){
        T[node] = (T[node] % mod * val % mod) % mod;
        lazy[node] = (lazy[node] % mod * val % mod) % mod;
        return;
    }

    push(node);

    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,val);
    update(node * 2 + 1,m + 1,r,u,v,val);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;

}


ll getSum(ll node, ll l, ll r, ll u, ll v){
    if(v < l || u > r) return;
    if(u <= l && v >= r) return T[node];

    push(node);

    int m = l + (r - l) / 2;

    return (getSum(node * 2,l,m,u,v) % mod + getSum(node * 2,m + 1,r,u,v) % mod) % mod;

}


void solve(){
    
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