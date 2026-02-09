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

/**
 * cho x,y tim p,q sao cho p & q == 0 va |x - p| + |y - q| la nho nhat
 */

pair<ll,ll> getPQ(ll x,ll y){
    ll p = x;
    ll q;
    vi dd(33,0);
    for(int i=0;i<31;i++){
        if((p >> i) & 1) dd[i] = 1;//danh dau bit i la bit 1
    }

    //bay h tim lon nhat <= y , nho nhat >= y (sao no cai gia tri tim dc day & p = 0)

    //-> vay chi can quan tam nhung bit van con gia tri = 0(tonr mang dd) -> vi 0 & 1 -> 0
    //tim gia tri lon nhat <= y

    ll lonNhatNhoHonY = 0;

    for(int i=30;i>=0;i--){
        //neu dd[i] van = 0

        if(dd[i] == 0){
            //cong 1 << i vao lonNhatNhoHonY van con <= y -> bat bit i nen
            if(lonNhatNhoHonY + (1ll << i) <= y){
                lonNhatNhoHonY += (1ll << i);
            }
        }
    }

    //tim gia tri nho nhat >= y
    ll tmp = lonNhatNhoHonY;
    ll nhoNhatLonHonY = 4e18;

    ll sumTmp = 0;

    for(int i=0;i<31;i++){
        if((tmp >> i) & 1){
            sumTmp += (1ll << i);
        }
        //thu bat bit i nen va ko lay nhung bit  1 tinh tu bot  0
        if(dd[i] == 0 && tmp + (1ll << i) - sumTmp >= y){
            nhoNhatLonHonY = min(nhoNhatLonHonY,tmp + (1ll << i) - sumTmp);
        }
    }

    if(y - lonNhatNhoHonY > nhoNhatLonHonY - y){
        q = nhoNhatLonHonY;
    }
    else q = lonNhatNhoHonY;
    
    return {p,q};
}

void solve(){
    ll x,y;cin >> x >> y;

    pair<ll,ll> p1 = getPQ(x,y);
    pair<ll,ll> p2 = getPQ(y,x);

    // cout << p1.fi << ' ' << p1.se << endl;
    // cout << p2.se << ' ' << p2.fi << endl;

    ll kc1 = labs(x - p1.fi) + labs(y - p1.se);
    ll kc2 = labs(x - p2.se) + labs(y - p2.fi);

    // cout << kc1 << ' ' << kc2 << endl;

    if(kc1 < kc2){
        cout << p1.fi << ' ' << p1.se << endl;
    }
    else cout << p2.se << ' ' << p2.fi << endl;

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