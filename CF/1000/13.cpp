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
    char c;cin >> c;
    string s;cin >> s;
    if(c == 'g'){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    int st = -1;
    int en = -1;
    int g_end = -1;
    for(int i=0;i<(int)s.size();i++){
        if(s[i] == c){
            if(st == -1) st = i;
        }
        if(s[i] == 'g' && st != -1){
            // cout << st << ' ' << i << endl;
            ans = max(ans,i - st);
            g_end = i;
            st = -1;
        }
    }

    for(int i = (int)s.size() - 1;i>=0;i--){
        if(s[i] == c){
            en = i;
        }
        if(s[i] == 'g') break;
    }
    
    if(g_end < en){
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == 'g'){
                // cout << i << endl;
                ans = max(ans,n - en + i);
                // cout << n - en + i << endl;
                break;
            }
        }
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