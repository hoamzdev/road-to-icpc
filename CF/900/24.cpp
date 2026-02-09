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
    vi a(n + 1,0);
    int _0 = 0;
    rep(i,1,n) {
        cin >> a[i];
        if(a[i] == 0){
            _0++;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 0) continue;
        else{
            //a[i] != 0
            if(a[i - 1] != 0) continue;
            else ans++;
        }
    }
    if(_0 == n) cout << 0 << endl;
    else if(_0 > 0){
        cout << min(2,ans) << endl;
    }
    else cout << min(1,ans) << endl;
}

//acc
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