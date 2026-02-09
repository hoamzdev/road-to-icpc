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
    ll n,x,y;cin >> n >> x >> y;
    vll a(n + 1,0);
    ll slctc = 0;
    rep(i,1,n){
        cin >> a[i];
        slctc += (a[i] / x);//so lan chuyen toi da cua 1 ngan hang
    }

    ll ans = 0;

    rep(i,1,n){
        //gia su chuyen het ve ngan hang i
        ans = max(ans, (slctc - a[i] / x) * y);
    }

    cout << ans << endl;

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