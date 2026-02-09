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
    int n,k;cin >> n >> k;
    vi f(n + 1,0);
    vi a(n + 1,1);
    for(int i=1;i<=k;i++){
        int x;cin >> x;
        a[x] = 0;
    }
    //f[i] : so cach de nen bac thu i
    f[1] = 1;
    if(a[2]) f[2] = 1;
    for(int i=3;i<=n;i++){
        if(!a[i]) continue;
        f[i] = (f[i-1] + f[i - 2]) % 14062008;
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