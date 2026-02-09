#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e5+7;
const ll mod=1e9+7;
const ll modr=1e9+9;


string s,t;
ll a[N],b[N],p[N];
int base = 31;

ll getHash(ll a[],int l,int r){
    ll ans = (a[r] - a[l - 1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}

void solve(){
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = "1" + s;
    t = "1" + t;
    p[0] = 1;
    for(int i=1;i<N;i++) p[i] = (p[i-1] * base) % mod;

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    //hashing
    for(int i=1;i<=n;i++) a[i] = (a[i-1] * base + s[i] - 'a' + 1) % mod;
    for(int i=1;i<=m;i++) b[i] = (b[i-1] * base + t[i] - 'a' + 1) % mod;

    int mx = min(n,m);
    int idx = 0;
    for(int i = mx;i>=1;i--){
        ll h = getHash(a,n - i + 1,n);
        ll k = getHash(b,1,i);
        if(h == k){
            idx = i;
            break;
        }
    }

    for(int i=1;i<=n;i++) cout << s[i];
    for(int i = idx + 1;i<=m;i++) cout << t[i];

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