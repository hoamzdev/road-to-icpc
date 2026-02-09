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


ll a,b,k;

ll dp[101][101][101][2];

ll dg(int pos,int modK,int sumModk,int t,string &s){
    if(pos == (int)s.size()){
        return modK == 0 && sumModk == 0;
    }

    if(dp[pos][modK][sumModk][t] != -1) return dp[pos][modK][sumModk][t];

    int maxD = (t) ? s[pos] - '0' : 9;
    ll res = 0;
    REP(i,0,maxD){
        int _pos = pos + 1;
        int _modK = (modK * 10 + i) % k;
        int _sumModK = (sumModk + i) % k;
        int _t;
        if(t == 0) _t = 0;
        else{
            if(i == maxD) _t = 1;
            else _t = 0;
        }
        res += dg(_pos,_modK,_sumModK,_t,s);
    }
    return dp[pos][modK][sumModk][t] = res;
}


ll calc(ll x){
    string s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dg(0,0,0,1,s);
}

void solve(){
    cin >> a >> b >> k;
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