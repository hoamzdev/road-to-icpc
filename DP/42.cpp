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

// ll dp[pos][lastVal][state][co phai so 0 o dau hay khong][t]
//state : 0: nghia la trc do chi taon gia  tri 0 o dau
// state = 1: nghia la so sau > so trc
//state = 2: nghia la so trc > so sau
ll dp[100003][13][5][2][2];//[1] : so 0 o dau vi du (0123),1:la bi gioi han


ll dg(int pos,int lastVal,int state,int isLead0,int t,string &s){
    if(pos == (int)s.size()){
        return !isLead0;
    }

    if(dp[pos][lastVal][state][isLead0][t] != -1) return dp[pos][lastVal][state][isLead0][t];

    int maxD = (t) ? s[pos] - '0' : 9;
    ll res = 0;
    rep(i,0,maxD){
        int _pos = pos + 1;
        int _t = t && (i == maxD);

        //neu van con so 0 o dau
        if(isLead0){
            if(i == 0) res = (res + dg(_pos,0,0,1,_t,s)) % mod;
            else res = (res + dg(_pos,i,0,0,_t,s)) % mod;
        }
        //trc do la chu so != 0
        else{
            if(state == 0){
                //moi bat dau 
                if(i > lastVal){
                    res = (res + dg(_pos,i,2,0,_t,s)) % mod;
                }
                else if(i < lastVal) res = (res + dg(_pos,i,1,0,_t,s)) % mod;
            }
            else if(state == 2){
                if(i < lastVal){
                    res = (res + dg(_pos,i,1,0,_t,s)) % mod;
                }
            }
            else if(state == 1){
                if(i > lastVal){
                    res = (res + dg(_pos,i,2,0,_t,s)) % mod;
                }
            }
        }
    } 

    return dp[pos][lastVal][state][isLead0][t] = res;

}

ll calc(string x){
    memset(dp,-1,sizeof(dp));
    return dg(0,0,0,1,1,x);
}


bool ck(string s){
    //state = 1,state = 2;doi xung <><><>< 
    int state;
    if((int)s.size() < 2) return true;
    if((int)s.size() == 2 && s[0] != s[1]) return true;
    //if(tang giam -> state = 1)
    //giam tang -> state = 2
    if(s[0] == s[1]) return false;

    if(s[0] > s[1]) state = 2;
    else if(s[0] < s[1]) state = 1;
    (state == 2) ? (state = 1) : (state = 2);
    rep(i,1,(int)s.size() - 2){
        if(state == 2){
            if(s[i] <= s[i + 1]) return false;
        }
        else if(state == 1){
            if(s[i] >= s[i + 1]) return false;
        }
        (state == 2) ? (state = 1) : (state = 2);
    }
    return true;
}

void solve(){
    int a,b;cin >> a >> b;
    string A,B;cin >> A >> B;
    ll R = calc(B) % mod;
    ll L = calc(A) % mod;

    ll ans = ((R - L) + mod) % mod;

    if(ck(A)){
        ans = (ans + 1) % mod;
    }
    cout << ans << endl;
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