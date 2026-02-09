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


void solve(){
    int n;cin >> n;
    
    ll sum = -1;
    int _0 = 0,_1 = 0;

    rep(i,1,n){
        int x;cin >> x;
        _0 += x == 0;
        _1 += x == 1;
        sum += x;
    }

    if(_1 == 0){
        cout << 0 << endl;
        return;
    }

    cout << 1ll * _1 * (1ll << _0) << endl;
    //minh co _0 phan tu 0
    // moi phan tu 0 co hai cach sd: cho vao sub va ko cho vao sub -> 1 ^ _0
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