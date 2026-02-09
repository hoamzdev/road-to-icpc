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
    int n,k;cin >> n >> k;
    vll a(n + 1,0);
    rep(i,1,n) cin >> a[i];
    int ans = INT_MAX;
    int cntR[6];
    memset(cntR,0,sizeof(cntR));
    rep(i,1,n){
        if(a[i] % k == 0){
            cout << 0 << endl;
            return;
        }
        a[i] %= k;
    }

    rep(i,1,n){
        cntR[a[i]]++;
    }

    if(cntR[2] >= 2 && k == 4){
        cout << 0 << endl;
        return;
    }

    rep(i,1,k-1){
        if(cntR[i] == 0) continue;
        ans = min(ans,k - i);    
    }
    
    if(k == 4){
        if(cntR[1] != 0){
            ans = min(ans,4 - 1);
            if(cntR[1] >= 2) ans = min(ans,2);
        }
        if(cntR[2] != 0){
            ans = min(ans,2);
            if(cntR[1] != 0) ans = min(ans,1);
        }
        if(cntR[3] != 0) ans = min(ans,1);
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