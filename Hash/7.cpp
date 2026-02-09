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

//cho biet xau con tu l den r co phai xau doi xung hay khong

string s;
ll f[N],p[N],rf[N];

ll getHash(ll a[],int l,int r){
    ll ans = (a[r] - a[l-1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}

void solve(){
    cin >> s;
    int q;cin >> q;
    int n = s.size();
    string t = s;//rev s
    reverse(all(t));
    s = "1" + s;
    t = "1" + t;
    p[0] = 1;
    for(int i=1;i<N;i++) p[i] = (p[i-1] * 31) % mod;

    memset(f,0,sizeof(f));
    memset(rf,0,sizeof(rf));

    for(int i=1;i<=n;i++){
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
        rf[i] = (rf[i-1] * 31 + t[i] - 'a' + 1) % mod;
    }


    while(q--){
        int l,r;cin >> l >> r;
        (getHash(f,l,r) == getHash(rf,n - r + 1,n - l + 1)) ? (cout << "YES\n") : (cout << "NO\n");
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