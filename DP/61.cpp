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
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;


void solve(){
    int n;cin >> n;
    vi a(n + 1,0);

    vi pos[n + 1];
    
    rep(i,1,n){
        cin >> a[i];
        if(a[i] <= n){
            pos[a[i]].push_back(i);
        }
    }

    int dp[n + 1];
    memset(dp,0,sizeof(dp));

    vi cnt(n + 1,0);//dang xet den so x thu may trong pos

    for(int i=1;i<=n;i++){
        //ko dung a[i] de ket thuc
        dp[i] = dp[i-1];
        int x = a[i];
        if(x > n) continue;
        cnt[x]++;//lan xuat hien thu cnt[x] cua x
        int k = cnt[x];

        if(k >= x){
            int st_pos = pos[x][k - x];
            dp[i] = max(dp[i],dp[st_pos - 1] + x);
        }
    }

    cout << dp[n] << endl;

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