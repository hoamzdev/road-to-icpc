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
    int n;cin >> n;
    vll a(n + 2,LLONG_MAX);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = n + 1;i>=1;i--){
        a[i] = min(a[i],a[i + 1]);
    }
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        cout << a[x] << endl;
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