#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define REP(i, l, r) for (int i = (l); i <= (r); ++i)
#define PER(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ll dp[N];

void solve(){
    int n,m;cin >> n >> m;
    vi a(n + 1,0),c(m + 1,0);
    REP(i,1,n) cin >> a[i];
    sort(all(a));
    REP(i,1,m) cin >> c[i];

    c[m + 1] = mod;
    PER(i,m,1){
        c[i] = min(c[i],c[i+1]);
    }

    REP(i,1,N) dp[i] = mod;

    dp[0] = 0;//dp[i]: gia tri tien it nhat de phu bat den vi tri gian hang thu i

    REP(i,0,n - 1){
        REP(j,i + 1,n){
            //che tu i + 1 den j( gia dinh da che xong den i roi)
            int len = a[j] - a[i + 1] + 1;//khoang cach tu gian hang thu i + 1 den gian hang thu j
            dp[j] = min(dp[j],dp[i] + c[len]);//chi phi che den gian hang thu i + gia tien mua bat tu i + 1 den j
        }
    }

    cout << dp[n];
}
//acc

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa