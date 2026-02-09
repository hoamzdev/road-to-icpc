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

//https://oj.vnoi.info/problem/fc139_divsub

void solve(){
    int n,p;
    cin >> n >> p;
    string s;cin >> s;
    s = "&" + s;
    ll pref[n + 1];
    ll pp[n + 1];
    pp[0] = 1;
    for(int i=1;i<=n;i++) pp[i] = (pp[i-1] * 10) % p;
    
    memset(pref,0,sizeof(pref));

    for(int i=1;i<=n;i++){
        pref[i] = (pref[i-1] * 10 + s[i] - '0') % p;
    }

    int cnt = 0;
    
    for(int len = 1;len <= n;len ++){
        for(int i=1;i<=n - len + 1;i++){
            int tmp = (pref[i + len - 1] - pref[i - 1] * pp[len] + p * p) % p;
            if(tmp == 0) cnt++;
        }
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