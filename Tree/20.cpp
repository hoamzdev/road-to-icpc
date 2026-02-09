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
    int sl1 = 0;
    
    rep(i,0,n-1) {
        if(s[i] == '1') sl1++;
    }


    vi b(n,0);
    rep(i,0,n-1){
        if(s[i] == '1'){
            b[i] = 1;
            if(i > 0) b[i-1] = 1;
            if(i < n - 1) b[i+1] = 1;
        }
    }

    rep(i,0,n-1){
        if(b[i] == 0){
            sl1++;
            int vt = i;
            if(i < n - 1){
                if(b[i + 1] == 0){
                    vt = i + 1;
                }
            }
            b[vt] = 1;
            if(vt > 0) b[vt - 1] = 1;
            if(vt < n - 1) b[vt + 1] = 1;
        }
    }

    cout << sl1 << endl;

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