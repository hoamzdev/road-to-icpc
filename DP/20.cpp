#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n;ll T;
    cin >> n >> T;

    vi h(n + 1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    ll dp[n + 1];//dp[i]: tg it nhat de den duoc cot i
    
    for(int i=1;i<=n;i++) dp[i] = LLONG_MAX;

    dp[1] = 0;//dang o cot mot san roi

    for(int i=1;i<n;i++){
        for(int j = i + 1;j<=n;j++){
            dp[j] = min(dp[j],dp[i] + 1ll * (j - i) * abs(h[j] - h[i]));
        }
    }

    if(dp[n] > T) cout << "NO";
    else{
        cout << "YES" << endl;
        cout << dp[n];
    }
}

//acc

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa