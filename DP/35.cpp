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

// ll dp[pos][sumO][sumE][t];
ll dp[10][47][47][2];

ll dg(int pos,int sumE,int sumO,int t,string &s){
    if(pos == (int)s.size()){
        return sumE - sumO == 1;
    }

    if(dp[pos][sumE][sumO][t] != -1) return dp[pos][sumE][sumO][t];

    int maxD = (t) ? s[pos] - '0' : 9;

    ll res = 0;
    REP(i,0,maxD){
        int _pos = pos + 1;
        int _sumE = sumE,_sumO = sumO;
        if(pos & 1) _sumO = sumO + i;
        else _sumE = sumE + i;

        int _t;

        if(t == 0) _t = 0;
        else {
            if(i == maxD) _t = 1;
            else _t = 0;
        }
        res += dg(_pos,_sumE,_sumO,_t,s);
    }
    return dp[pos][sumE][sumO][t] = res;
}
//30/100
ll calc(ll x){
    string s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dg(0,0,0,1,s);
}

void solve(){
    ll a,b;cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa
