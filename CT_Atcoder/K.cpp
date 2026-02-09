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
    int n,k;cin >> n >> k;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    vi dp(k + 1,0);//neu luot bayh co i vien soi thi nguoi di bayh co thang hay khong : dp[i]

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            //minh lay a[j]
            if(i >= a[j] && dp[i - a[j]] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
    
    if(dp[k]) cout << "First";
    else cout << "Second";
    
    cout << endl;

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