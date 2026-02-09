#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;


void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++){
        char c;cin >> c;
        a[i] = c - '0';
    }

    vll pref(n + 1,0);
    pref[1] = a[1];

    for(int i=2;i<=n;i++) pref[i] = pref[i-1] + a[i];

    unordered_map<int,ll> mp;
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        mp[pref[i] - i]++;
    }
    
    ll cnt = 0;

    for(auto [fi,se] : mp){
        cnt += (se * (se - 1)) / 2;
    }
    cout << cnt << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa