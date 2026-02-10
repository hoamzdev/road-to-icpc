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
    int n;cin >> n;
    string s;cin >> s;
    s = "@" + s;
    vi pref(n + 5,0);//pref[i] : sl phan tu khac nhau tinh tu 1 den i
    vi ex(27,0);
    rep(i,1,n){
        if(ex[s[i] - 'a'] == 0){
            //bayh moi gap
            pref[i] = pref[i - 1] + 1;
            ex[s[i] - 'a'] = 1;
        }
        else pref[i] = pref[i - 1];
    }

    ex = vi(27,0);
    vi suf(n + 5,0);
    
    per(i,n,1){
        if(ex[s[i] - 'a'] == 0){
            suf[i] = suf[i + 1] + 1;
            ex[s[i] - 'a'] = 1;
        }
        else suf[i] = suf[i + 1];
    }

    int ans = 1;

    rep(i,1,n){
        ans = max(ans,pref[i] + suf[i + 1]);
    }

    cout << ans << endl;
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