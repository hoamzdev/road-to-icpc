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

int getM(int n){
    int M = 0;
    while(n){
        M = max(M,n % 10);
        n /= 10;
    }    
    return M;
}

void solve(){
    int n;cin >> n;
    
    ll cnt = 0;
    while(n){
        n -= getM(n);
        cnt++;
    }
    cout << cnt << endl;
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