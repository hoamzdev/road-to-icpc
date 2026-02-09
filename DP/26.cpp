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

int dp[N];

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    REP(i,1,n) cin >> a[i];
    sort(all(a));
    
    //dp[i]: so luong phan tu thoa man dai nhat tinh den vi tri i
    REP(i,1,n) dp[i] = 1;//1 phan tu cung thoa man 1 mang con

    REP(i,1,n - 1){
        REP(j,i + 1,n){
            if(a[j] % a[i] == 0){
                dp[j] = max(dp[j],dp[i] + 1);
            }
        }
    }
    int ans = 0;
    REP(i,1,n){
        ans = max(ans,dp[i]);
    }

    cout << n - ans;

}
//80.00 diem
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