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
    ll a,b,c;cin >> a >> b >> c;
    //case1
    {
        //nhan vao a
        ll d = c - b;
        ll x = (b - d) / a;
        if(x > 0 && b - a*x == d){
            cout << "yes" << endl;
            return;
        }
    }

    //case2
    {
        ll d = b - a;
        ll x = (b + d) / c;
        if(x > 0 && b + d == x * c){
            cout << "yes" << endl;
            return;
        }
    }

    {
        ll x = (a + c) / (2 * b);
        if(x > 0 && b*x - a == c - b * x){
            cout << "yes" << endl;
            return;
        }
    }


    cout << "no" << endl;
//acc
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