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
    int a[11][11];
    memset(a,0,sizeof(a));
    int t = 1;int n = 10;
    int p = 1;
    while(t < n){
        for(int i=t;i<=n;i++){
            a[t][i] = p;
            a[n][i] = p;
            a[i][t] = p;
            a[i][n] = p;
        }
        t++;
        n--;
        p++;
    }
    int ans = 0;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            char x;cin >> x;
            if(x == 'X'){
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa