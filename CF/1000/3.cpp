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


bool cmd(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}  

void solve(){
    ll n,p;cin >> n >> p;
    vll a(n,0),b(n,0);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,n-1) cin >> b[i];

    vector<pair<ll,ll>> v;
    rep(i,0,n-1) v.push_back({a[i],b[i]});

    sort(all(v),cmd);

    ll ans = p;
    ll total = n;
    --total;
    for(ll i=0;i<n - 1;i++){
        if(v[i].second >= p){
            ans += 1ll * total * p;
            total = 0;
            break;
        }
        if(total <= 0){
            //tat ca deu nhan dc thong tin
            break;
        }
        ans += 1ll * v[i].second * min(total,v[i].first);
        total -= min(v[i].first,total);
    }

    cout << min(ans,1ll * n * p) << endl;

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