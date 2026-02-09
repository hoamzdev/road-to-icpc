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


int dp[N];
vi d[N];

void seive(){
    //O(nlog(n))
    for(int i=1;i<1000001;i++){
        for(int j=i;j<1000001;j+=i){
            d[j].push_back(i);
        }
    }
    //dp[j] = {list cac uoc cua j}
}

void solve(){
    seive();
    int s,t;cin >> s >> t;
    for(int i=1;i<=t + 10;i++){
        dp[i] = mod;
    }

    dp[s] = 0;//0 buoc de dua s -> s

    //goi x la uoc cua a -> b - a = x; vay thi b = a + x
    //voi moi i thuoc [s,t] duyet tat ca cac uoc cua i
    //-> b = i + x(x la uoc cua i)
    //dp[b] = so buoc de tu i den b
    //dp[b] = min(dp[b],dp[i] + 1);

    for(int i=s;i<=t;i++){
        //duyet uoc cua i
        for(int x : d[i]){
            int b = i + x;
            if(i + 1 < b && b < 2 * i && b <= t){
                dp[b] = min(dp[b],dp[i] + 1);
            }
        }
    }

    if(dp[t] == mod) cout << -1 << endl;
    else cout << dp[t] << endl;

}

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