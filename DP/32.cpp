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
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;


//dem cac so tu 1 den n ma tong binh phuong cac chu so cua no chia het cho 3


// ll dp[pos][mod3][t];mod3 = tong % 3
ll dp[10001][5][2];

ll dg(int pos,int mod3,int t,string &s){

    if(pos == (int)s.size()){
        return mod3 == 0;
    }

    if(dp[pos][mod3][t] != -1) return dp[pos][mod3][t];

    int maxD = (t) ? s[pos] - '0' : 9;

    ll res = 0;
    REP(i,0,maxD){
        int npos = pos + 1;
        int nmod3 = (mod3 + i * i) % 3;
        int _t;
        if(t == 0) _t = 0;
        else{
            if(i == maxD) _t = 1;
            else _t = 0;
        }
        res = (res + dg(npos,nmod3,_t,s)) % mod;
    }

    return dp[pos][mod3][t] = res;
}

ll sumStr(string s){
    ll ans = 0;
    REP(i,0,(int)s.size() - 1){
        int x = s[i] - '0';
        x *= x;
        ans += x;
    }
    return ans;
}

void solve(){
    string n;cin >> n;
    memset(dp,-1,sizeof(dp));
    ll cal = dg(0,0,1,n);
    if(sumStr(n) % 3 == 0) cal--;
    cout << cal << endl;
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