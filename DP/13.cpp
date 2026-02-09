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
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

/*
Cho dãy số gồm n số a1, a2, a3, ..., an.

Hãy tìm dãy con gồm các số có chỉ số không liên tiếp nhau có tổng lớn nhất (2 số liên tục 
ví dụ: a2, a3 không đồng thời có trong dãy con).*/

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vll dp(n + 1,0);//dp[i] : tong cua day con lon nhat ket thuc tai i

    dp[1] = a[1];
    
    for(int i=2;i<=n;i++){
        dp[i] = a[i];
        dp[i] = max({dp[i],dp[i] + dp[i - 2],dp[i - 1]});
    }

    ll ans = 0;
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
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa