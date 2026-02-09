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
    vi a(n,0);
    rep(i,0,n-1) cin >> a[i];
    sort(all(a));
    
    // for(int i=0;i<n;i++) cout << a[i] << ' ';
    // cout << endl;

    int len = 1;
    int cnt = 1;
    rep(i,1,n - 1){
        if(a[i] - a[i-1] <= k){
            cnt++;
        }
        else{
            len = max(len,cnt);
            cnt = 1;
        }
    }
    len = max(len,cnt);
    cout << n - len << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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