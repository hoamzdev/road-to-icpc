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
    int n;cin >> n;
    vi red(n + 1,0),blue(n + 1,0);
    rep(i,1,n) cin >> red[i];
    rep(i,1,n) cin >> blue[i];

    ll f_max[n + 1];
    ll f_min[n + 1];

    f_max[0] = 0;
    f_min[0] = 0;

    for(int i=1;i<=n;i++){
        ll op1 = f_max[i-1] - red[i];
        ll op2 = f_min[i-1] - red[i]; 

        ll op3 = blue[i] - f_max[i-1];
        ll op4 = blue[i] - f_min[i-1];

        f_max[i] = max({op1,op2,op3,op4});
        f_min[i] = min({op1,op2,op3,op4});
    }
    
    cout << f_max[n] << endl;

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