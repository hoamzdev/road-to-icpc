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

ll dp[10][231][2];//pos, diff, t

ll dg(int pos, int diff, int t, string &s){
    if(pos == (int)s.size()){
        return diff == 1;
    }

    if(dp[pos][diff + 100][t] != -1) return dp[pos][diff + 100][t];

    int maxD = (t) ? s[pos] - '0' : 9;

    ll res = 0;

    rep(i,0,maxD){
        int _pos = pos + 1;
        int _t = t && (i == maxD);
        int _diff = diff;

        //diff
        int vt = (int)s.size() - pos;//tinh tu ben phai qua de tranh so 0 o dau

        if(vt & 1) _diff -= i;
        else _diff += i;

        res += dg(_pos,_diff,_t,s);
    }

    return dp[pos][diff + 100][t] = res;
}
//acc
ll calc(ll x){
    string s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dg(0,0,1,s);
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