#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
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
    vi a(n + 1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    vi dp(n + 7,0);
    //dp[i]: so luong phan tu du lai nhieu nhat tinh tu n den i

    for(int i=n;i>=1;i--){
        dp[i] = dp[i + 1];//dp[i] ko phai pt dau tien cua day con

        if(i + a[i] <= n){
            dp[i] = max(dp[i],1 + a[i] + dp[1 + a[i] + i]);
        }
    }

    cout << n - dp[1] << endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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