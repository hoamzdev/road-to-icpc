#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
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



void solve(){
    string s;cin >> s;
    int _1 = 0;
    int _0 = 0;
    for(char x : s){
        if(x == '0') _0++;
        else _1++;
    }
    int n = (int)s.size();
    for(int i=0;i<(int)s.size();i++){
        if(s[i] == '0' && _1 > 0){
            _1--;
            n--;
        }
        else if(s[i] == '1' && _0 > 0){
            _0--;
            n--;
        }
        else break;
    }

    cout << n << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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