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

//Truy vấn 1: Tang giá trị trong [L,R] thêm x đơn vị va tinh tong

ll a[N],T[4 * N],lazy[4 * N];

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


void push(ll node, ll l, ll r){
    if(lazy[node] == 0) return;
    
    int m = l + (r - l) / 2;

    lazy[node * 2] = (lazy[node * 2] + lazy[node]) % mod;
    lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % mod;

    T[node * 2] = (T[node * 2] % mod + (m - l + 1) * lazy[node] % mod) % mod;
    T[node * 2 + 1] = (T[node * 2 + 1] % mod + (r - m) * lazy[node] % mod) % mod;

    lazy[node] = 0;

}

void update(ll node, ll l, ll r, ll u, ll v, ll x){
    if(v < l || u > r) return;
    if(u <= l && v >= r){
        T[node] = (T[node] + (r - l + 1) * x % mod) % mod;
        lazy[node] = (lazy[node] % mod + x % mod) % mod;
        return;
    }

    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,x);
    update(node * 2 + 1,m + 1,r,u,v,x);

    T[node] = (T[node * 2] + T[node * 2 + 1]) % mod;

}