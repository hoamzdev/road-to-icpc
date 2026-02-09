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

//dem so co tong la snt trong doan lon

int prime[1001];

void seive(){
    rep(i,1,1001) prime[i] = 1;
    prime[0] = prime[1] = 0;
    rep(i,2,sqrt(1001)) if(prime[i]){
        for(int j=i*i;j<1001;j+=i) prime[j] = 0;
    }
}

ll dp[10][90][2];

ll dg(int pos,int sum,int t,string &s){
    if(pos == (int)s.size()){
        return prime[sum];
    }

    if(dp[pos][sum][t] != -1) return dp[pos][sum][t];

    int maxD = (t) ? s[pos] - '0' : 9;

    ll res = 0;


    rep(i,0,maxD){
        int _t = t && i == maxD;
        
        res += dg(pos + 1,sum + i,_t,s);
        
    }


    return dp[pos][sum][t] = res;


}

ll calc(ll x){
    string s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dg(0,0,1,s);
}

void solve(){
    int l,r;cin >> l >> r;
    cout << calc(r) - calc(l-1) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    seive();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa