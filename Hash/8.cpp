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
const ll NN = 1e5 + 5;

ll da[N],db[N];
int a[N],b[N];

ll hashA[N],hashB[N],p[N];

ll getHash(int l,int r){
    ll ans = (hashA[r] - hashA[l - 1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}
//https://codeforces.com/contest/471/problem/D
void solve(){
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=m;j++) cin >> b[j];

    p[0] = 1;//31 ^ i
    for(int i=1;i<N;i++) p[i] = (p[i-1] * 31) % mod;


    for(int i=2;i<=n;i++) da[i] = a[i] - a[i-1];
    for(int i=2;i<=m;i++) db[i] = b[i] - b[i-1];

    memset(hashA,0,sizeof(hashA));
    memset(hashB,0,sizeof(hashB));
    for(int i=2;i<=n;i++) hashA[i] = (hashA[i-1] * 31 + da[i] + NN) % mod;
    for(int i=2;i<=m;i++) hashB[i] = (hashB[i-1] * 31 + db[i] + NN) % mod;

    int cnt = 0;
    ll di = hashB[m];
    for(int i=1;i<=n - m + 1;i++){
        if(getHash(i + 1,i + m - 1) == di) cnt++;
    }
    cout << cnt;
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