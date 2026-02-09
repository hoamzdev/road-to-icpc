#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
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



void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int k = n / 2; k >= 0; k--) {
        int sh = 0, sl = 0, s_both = 0;
        for(int x : a) {
            if (x <= h && x <= l) s_both++;
            else if (x <= h) sh++;
            else if (x <= l) sl++;
        }
        if (min(sh, k) + min(sl, k) + s_both >= 2 * k 
            && sh + s_both >= k && sl + s_both >= k) {
            cout << k << endl;
            return;
        }
    }
}

int main(){
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