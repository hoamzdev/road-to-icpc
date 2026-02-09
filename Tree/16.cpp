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
    ll n,d,s;cin >> n >> d >> s;

    //do dich den la boi cua s nen ta chia het cho s, va tang ban dau la 1
    n /= s;
    d /= s;

    ll y = min(2 * d,n);

    if(y % 2 == 0){
        cout << min(y * s,s);
        return;
    }

    //y le, thi y - 1 cung la 1 trong nhung pa co the xay ra
    ll ans = max(s,(y - 1) * s);

    for(ll i = 3;i * i <= y;i++){
        if(y % i == 0){
            //i la uoc cua y
            if(y - i <= d || y - y / i <= d){
                ans = max(ans,y * s);
                break;
            }
        }
    }

    //check xem co the nhay tu 1 nen y hay khong
    if(y - 1 <= d) {
        ans = max(ans,y * s);
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