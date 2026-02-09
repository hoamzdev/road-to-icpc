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

int prime[N];

void seive(){
    REP(i,1,N) prime[i] = 1;
    prime[1] = prime[0] = 0;
    REP(i,2,sqrt(N)){
        if(prime[i]){
            for(int j=i * i;j<N;j+=i) prime[j] = 0;
        }
    }
}

ll dp[10][80][2];//t = 0;0->9,t = 1,0->s[i]

ll dg(int pos,int sum,int t,string &s){
    if(pos == (int)s.size()){
        return prime[sum];
    }
    if(dp[pos][sum][t] != -1) return dp[pos][sum][t];

    int maxD = (t) ? s[pos] - '0' : 9;
    ll res = 0;
    REP(i,0,maxD){
        int npos = pos + 1;
        int nsum = sum + i;
        int _t;
        if(t == 0) _t = 0;
        else{
            if(i == maxD) _t = 1;
            else _t = 0;
        }
        res += dg(npos,nsum,_t,s);
    }
    return dp[pos][sum][t] = res;
}


ll calc(ll x){
    if(x < 0) return 0;
    string s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dg(0,0,1,s);
}   

void solve(){
    seive();
    ll l,r;cin >> l >> r;
    cout << calc(r) - calc(l - 1);
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