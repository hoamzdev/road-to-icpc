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

ll f[N],p[N];

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}
//1392. Longest Happy Prefix
string longestPrefix(string s) {
    int n = s.size();
    s = "@" + s;

    p[0] = 1;
    for(int i=1;i<=n;i++){
        p[i] = (p[i-1] * 31) % mod;
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
    }
    
    for(int len = n - 1;len >= 1;len --){
        ll l = getHash(1,len);
        ll r = getHash(n - len + 1,n);
        if(l == r){
            return s.substr(1,len);
        }
    }
    return "";
}

void solve(){
    string s;cin >> s;
    cout << longestPrefix(s);
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