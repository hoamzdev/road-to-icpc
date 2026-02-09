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
//1316. Distinct Echo Substrings
int distinctEchoSubstrings(string s) {
    int n = s.size();
    s = "@" + s;
    p[0] = 1;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        p[i] = (p[i-1] * 119) % mod;
        f[i] = (f[i-1] * 119 + s[i] - 'a' + 1) % mod;
    }    

    set<string> se;

    for(int len = 2;len <= n;len +=2){
        for(int i=1;i<=n - len + 1;i++){
            int h = len / 2;
            ll l = getHash(i,i + h - 1);
            ll r = getHash(i + h,i + len - 1);
            if(l == r){
                se.insert(s.substr(i,h));
            }
        }
    }
    return (int)se.size();
}

void solve(){
    string s;cin >> s;
    cout << distinctEchoSubstrings(s);
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