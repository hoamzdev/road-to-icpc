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
    int n; cin >> n;
    vll a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    vll L(n+1), R(n+2);
    vll bestL(n+1), bestR(n+2);

    L[1] = a[1];
    bestL[1] = a[1];
    for(int i=2;i<=n;i++){
        L[i] = max(a[i], L[i-1] + a[i]);
        bestL[i] = max(bestL[i-1], L[i]);
    }

    R[n] = a[n];
    bestR[n] = a[n];
    for(int i=n-1;i>=1;i--){
        R[i] = max(a[i], R[i+1] + a[i]);
        bestR[i] = max(bestR[i+1], R[i]);
    }

    ll ans = LLONG_MIN;
    for(int i=1;i<n;i++){
        ans = max(ans, bestL[i] + bestR[i+1]);
    }

    cout << ans;
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