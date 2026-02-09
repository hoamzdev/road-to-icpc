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
    ll n,m,h;
    cin >> n >> m >> h;
    vll a(n + 1,0);
    vll tmp(n + 1,0);
    rep(i,1,n) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    
    set<ll> idx;//nhung vi tri da thay doi

    while(m--){
        ll b,c;cin >> b >> c;
        if(a[b] + c <= h){
            a[b] += c;
            idx.insert(b);
        }
        else{
            //reset ve ban dau
            for(auto i : idx) a[i] = tmp[i];
            idx.clear();
        }
    }
    // cout << n << endl;
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;

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