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
    
    vector<vi> ve(n + 1);
    int minNhat = INT_MAX;

    for(int i=1;i<=n;i++){
        int m;cin >> m;
        vi tmp;
        for(int j=0;j<m;j++){
            int x;cin >> x;
            minNhat = min(minNhat,x);
            tmp.push_back(x);
        }
        ve[i] = tmp;
    }

    for(int i=1;i<=n;i++) sort(all(ve[i]));//sort tang dan

    vi MinThu2;

    for(int i=1;i<=n;i++){
        MinThu2.push_back(ve[i][1]);
    }

    ll ans = 0;
    for(int x : MinThu2) ans += x;

    ans -= (*min_element(all(MinThu2)));

    ans += minNhat;

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