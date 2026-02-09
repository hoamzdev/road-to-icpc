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
const ll N=1e4+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

// ll dp[pos][modeD][t];
ll dp[N][101][2];
int D;

ll dg(int pos,int modD,int t,string &s){
    if(pos == (int)s.size()){
        return modD == 0;
    }

    if(dp[pos][modD][t] != -1) return dp[pos][modD][t];

    int maxD = (t) ? (s[pos] - '0') : 9;


    ll res = 0;
    rep(i,0,maxD){
        int _t = (t) && i == maxD;
        int _modD = (modD + i) % D;
        int _pos = pos + 1;
        res = ((res + dg(_pos,_modD,_t,s)) + mod) % mod;
    }

    return dp[pos][modD][t] = res;

}


ll calc(string s){
    memset(dp,-1,sizeof(dp));
    return dg(0,0,1,s);
}


void solve(){
    string n;cin >> n;
    cin >> D;

    cout << (calc(n) - 1 + mod) % mod << endl;
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