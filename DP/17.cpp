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
    int n;cin >> n;
    vi a(n +  1,0);
    int LIMN = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        LIMN += a[i];
    }

    // for(int i=1;i<=n;i++) cout << a[i] << ' ';

    bool dp[LIMN + 1];//dp[i] = 1 : tong i co the tao dc
    memset(dp,false,sizeof(dp));

    dp[0] = true;
    for(int i=1;i<=n;i++){
        for(int j = LIMN;j>=a[i];j--){
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    vi res;
    for(int i=1;i<=LIMN;i++){
        if(dp[i]) res.push_back(i);
    }

    cout << (int)res.size() << endl;
    for(int i : res) cout << i << " ";

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