#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ll fs[N],p[N],ft[N];


ll getHash(ll f[],int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

long long maxProduct(string s) {
    int n = s.size();
    if(n <= 3) return 1;
    string t = s;
    reverse(all(t));
    s = "%" + s;
    t = "#" + t;
    p[0] = 1;
    memset(fs,0,sizeof(fs));
    memset(ft,0,sizeof(ft));

    for(int i=1;i<=n;i++){
        fs[i] = (fs[i-1] * 31 + s[i] - 'a' + 1) % mod;
        ft[i] = (ft[i-1] * 31 + t[i] - 'a' + 1) % mod;
        p[i] = (p[i-1] * 31) % mod;
    }

    ll ans = 1;

    for(int len = 3;len <= n;len +=2){
        vi a;
        a.push_back(1);
        for(int i=1;i<=n - len + 1;i++){
            int l = i;
            int r = i + len - 1;
            ll h1 = getHash(fs,l,r);
            ll h2 = getHash(ft,n - r + 1,n - l + 1);
            if(h1 == h2){
                a.push_back(len);
                i = r;
            }
        }
        sort(all(a));
        int na = (int)a.size();
        if(na != 1){
            ans = max(ans,1ll * a[na - 1] * a[na - 2]);
        }
    }
    return ans;
}

void solve(){
    string s;cin >> s;
    cout << maxProduct(s);
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