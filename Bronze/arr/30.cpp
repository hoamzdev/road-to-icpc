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
    ll n,d;cin >> n >> d;
    vll a(n + 1,0);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
        a[i] = (a[i] % d + d) % d;
    }

    ll cnt = 0;
    unordered_map<ll,ll> mp;
    mp[0] = 1;

    for(int i=1;i<=n;i++){
        mp[a[i]]++;
    }
    for(auto [fi,se] : mp){
        cnt += (se * (se - 1)) / 2;
    }

    cout << cnt;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa