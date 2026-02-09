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
    int n,m;cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    vi ans;

    for(int i=1;i<=m;i++){
        int tmp = 0;
        for(int j=1;j<=n;j++){
            tmp += a[j][i];
        }
        ans.push_back(tmp);
    }
    for(int i : ans) cout << i << ' ';
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