#include<bits/stdc++.h>
using namespace std;
#define MfX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define fll(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    string s,t;cin >> s >> t;

    int fir[27];
    int las[27];

    memset(fir,-1,sizeof(fir));
    memset(las,-1,sizeof(las));

    for(int i=1;i<(int)s.size();i++){
        if(fir[s[i] - 'a'] == -1) fir[s[i] - 'a'] = i;
    }

    for(int i=0;i<(int)t.size() - 1;i++){
        las[t[i] - 'a'] = i;
    }

    int min_len = 1e8 + 7;
    int ok = -1;

    int _fi,_la;
    for(int i=0;i<27;i++){
        int f = fir[i];
        int l = las[i];
        if(f != -1 && l != -1){
            if(min_len > 1 + f + (int)t.size() - l - 1){
                min_len = 1 + f + (int)t.size() - l - 1;
                _fi = f;
                _la = l;
                ok = 1;
            }
        }
    }

    if(ok == -1){
        cout << ok << endl;
        return;
    }
    
    // cout << min_len << endl;
    cout << s.substr(0,_fi) + t.substr(_la,(int)t.size() - _la);
    cout << endl;

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
//Rofd to ICPC 2026 - by hwf