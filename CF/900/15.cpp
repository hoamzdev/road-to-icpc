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
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    ll n,x;cin >> n >> x;
    vll a(n + 1,0),b(n + 1,0),c(n + 1,0);

    rep(i,1,n) cin >> a[i] >> b[i] >> c[i];

    ll _0lui = 0;
    //tong tat ca doan duong nhay dc neu ko lui
    rep(i,1,n) _0lui += (b[i] - 1) * a[i];

    if(_0lui >= x){
        cout << 0 << endl;
        return;
    }

    ll D = 0;//luu lai do dai nhay lon nhat trong 1 chu ki (tinh den khi phai lui 1 lan)
    rep(i,1,n) D = max(D,b[i] * a[i] - c[i]);

    if(D <= 0){
        //sau 1 chu ki ko tien them dc buoc nao (vi tr ko doi)
        cout << -1 << endl;
        return;
    }

    x -= _0lui;
    //k . D = x voi k la so lan lap lai 1 chu ki -> k = x / D (lay phan nguyen tren)

    cout << (x + D - 1) / D << endl;
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