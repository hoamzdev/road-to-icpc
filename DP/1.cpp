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


void solve(){
    int n,q;cin >> n >> q;
    vll a(n + 1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    while(q--){
        int u,v;cin >> u >> v;
        cout << a[v] - a[u - 1] << endl;
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