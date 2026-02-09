#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n;cin >> n;
    vector<vi> a(n + 1,vi(4,0));

    rep(i,1,n)rep(j,1,3) cin >> a[i][j];



    // int dp[n + 1][4];//dp[i][j] : hp lon nhat tinh den ngay thu i khi chon j
    vector<vi> dp(n + 1,vi(4,0));

    rep(i,1,3) dp[1][i] = a[1][i];



    rep(i,2,n){
        rep(j,1,3){
            //gia tri trc
            rep(k,1,3){
                if(k != j){
                    dp[i][j] = max(dp[i][j],dp[i-1][k] + a[i][j]);
                }
            }
        }
    }
    
    cout << *max_element(all(dp[n])) << endl;

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa