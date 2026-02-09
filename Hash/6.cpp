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

string s,t;

ll f[N],p[N];
ll HashT = 0;

ll getHash(int l,int r){
    ll ans = (f[r] - f[l-1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}

void solve(){
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = "@" + s;
    t = "@" + t;

    p[0] = 1;
    for(int i = 1;i<=m;i++){
        p[i] = (p[i-1] * 31) % mod;
    }

    for(int i=1;i<=m;i++){
        HashT = (HashT * 31 + t[i] - 'a' + 1) % mod;
    }

    memset(f,0,sizeof(f));

    for(int i=1;i<=n;i++){
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
    }

    for(int i=1;i<=n - m + 1;i++){
        if(HashT == getHash(i,i + m - 1)) cout << i << " ";
    }
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