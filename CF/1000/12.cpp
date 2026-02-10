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
const ll N=1e5;
const ll mod=1e9+7;
const ll modr=1e9+9;


void solve(){
    ll n;cin >> n;
    if(n % 2 == 0){
        cout << n / 2 << ' ' << n / 2 << endl;
        return;
    }

    int d = -1;//d luu uoc nho nhat cua n (n le)

    rep(i,2,sqrt(n)){
        if(n % i == 0){
            d = i;
            break;
        }
    }

    if(d == -1){
        //deo co uoc nao ngoai 1 va cn
        cout << 1 << ' ' << n - 1 << endl;
        return;
    }

    //n / d se la uoc lon nhat cua n
    cout << n / d << ' ' << n - n / d << endl;
    
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