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
    int n,x;cin >> n >> x;

    ll max_sum = 0;
    ll min_sum = 0;
    ll sumTmp = 0;
    rep(i,1,n){
        int a;cin >> a;
        max_sum += ((a + x - 1) / x);
        if(a % x == 0){
            min_sum += ((a + x - 1) / x);
        }
        else sumTmp += a;
    }

    cout << min_sum + (sumTmp + x - 1) / x << ' ' << max_sum << endl;

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