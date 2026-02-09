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

struct Data{
    int l,r,c;
    Data(int _l = 0,int _r = 0,int _c = 0){
        l = _l;
        r = _r;
        c = _c;
    }
};

bool cmd(Data &a, Data &b){
    return a.l < b.l;
}

void solve(){
    int n;cin >> n;
    vector<Data> ve(n + 1);
    for(int i=1;i<=n;i++){
        int l,r,c;cin >> l >> r >> c;
        ve[i] = Data(l,r,c);
    }

    sort(all(ve),cmd);

    int dp[n + 1];//dp[i] : loi nhuan lon nhat thu dc tinh den phong thu i
    for(int i=1;i<=n;i++) dp[i] = ve[i].c;

    for(int i=1;i<n;i++){
        for(int j = i + 1;j<=n;j++){
            if(ve[j].l >= ve[i].r){
                dp[j] = max(dp[j],dp[i] + ve[j].c);
            }
        }
    }

    int ans = 0; 
    for(int i=1;i<=n;i++){
        ans = max(ans,dp[i]);
    }

    cout << ans;
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