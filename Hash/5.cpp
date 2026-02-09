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
ll hashT = 0;
int base = 31;
//cho sau s,t hay tim vi tri cua xau t trong xau s

ll getHash(int,int);

void solve(){
    string s,t;cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = "@" + s;
    t = "@" + t;

    p[0] = 1;
    //p[i] = p ^ i
    for(int i=1;i<=m;i++){
        p[i] = (p[i-1] * base) % mod;
    }

    for(int i=1;i<=m;i++){
        hashT = (hashT * base + t[i] - 'a' + 1) % mod;
    }

    memset(f,0,sizeof(f));

    for(int i=1;i<=n;i++){
        f[i] = (f[i-1] * base + s[i] - 'a' + 1) % mod;
    }


    for(int i=1;i<= n - m + 1;i++){
        if(hashT == getHash(i,i + m - 1)){
            cout << i << ' ';
        }
    }
}

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
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