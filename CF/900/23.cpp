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
    vi a(n,0);
    rep(i,0,n-1) cin >> a[i];
    int ans = a[n - 1] - a[0];
    int max_a = *max_element(all(a));
    int min_a = *min_element(all(a));

    ans = max({ans,a[n - 1] - min_a,max_a - a[0]});

    for(int i = 0;i<n-1;i++){
        ans = max(ans,a[i] - a[i+1]);
    }

    cout << ans << endl;
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