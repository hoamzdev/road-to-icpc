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

// ll dp[pos][sum1][sum2][t];//sum1 : tong cac chu so,sum2 : tong binh phuong cac chu so

//check 2 so nguyen to cung nhau
bool ck(int a,int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a == 1;
}

ll dp[19][173][1731][2];

ll dg(int pos,int sum1,int sum2,int t,string &s){
    if(pos == (int)s.size()){
        return ck(sum1,sum2);
    }

    if(dp[pos][sum1][sum2][t] != -1) return dp[pos][sum1][sum2][t];

    int maxD = (t) ? s[pos] - '0' : 9;

    ll res = 0;

    rep(i,0,maxD){
        int _t = t && (i == maxD);
        int _pos = pos + 1;
        int _sum1 = sum1 + i;
        int _sum2 = sum2 + i * i;
        
        res += dg(_pos,_sum1,_sum2,_t,s);
    }

    return dp[pos][sum1][sum2][t] = res;

}
//acc
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