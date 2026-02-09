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

bool bs(vi &a, int x){
    int l = 0,r = (int)a.size() - 1;

    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] == x) return true;
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return false;
}

void solve(){
    int n,x;cin >> n >> x;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];
    sort(all(a));
    bool ok = bs(a,x);
    if(ok) cout << "yes\n";
    else cout << "no\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    solve();
}
//Road to ICPC 2026 - by hwa