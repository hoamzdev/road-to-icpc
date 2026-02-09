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
    int n,m,q;cin >> n >> m >> q;
    ll a[n + 1][m + 1];
    memset(a,0,sizeof(a));
    ll p[n + 1][m + 1];
    memset(p,0,sizeof(p));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + a[i][j];
        }
    }

    while(q--){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1] << endl;
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