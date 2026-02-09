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


int trace[N];

void solve(){
    int n,k;cin >> n >> k;
    vi a(n + 1,0);
    vll f(n + k + 1,mod);
    
    for(int i=1;i<=n;i++) cin >> a[i];
    f[1] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(f[i + j] > f[i] + abs(a[i + j] - a[i])){
                f[i + j] = f[i] + abs(a[i + j] - a[i]);
                trace[i + j] = i;
            }
        }
    }
    cout << f[n] << endl;
    vi res;
    int pos = n;
    while(pos != 1){
        res.push_back(pos);
        pos = trace[pos];
    }
    res.push_back(1);
    reverse(all(res));
    for(int i : res) cout << i << ' ';
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