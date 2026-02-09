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
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

void solve(){
    int n;cin >> n;
    vi t(n + 1,0);
    vi r(n + 1,0);
    for(int i=1;i<=n;i++) cin >> t[i];
    for(int j=1;j<n;j++) cin >> r[j];

    vll f(n + 1,0);
    f[1] = t[1];
    //thoi gian toi uu de phuc vu tu 1 den i
    for(int i=2;i<=n;i++){
        f[i] = min(f[i-1] + t[i],f[i - 2] + r[i - 1]);
    }

    cout << f[n];

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