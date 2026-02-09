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
    ll X,K,D;cin >> X >> K >> D;
    if(X > 0){
        //lui
        ll n = (X + D - 1) / D;
        K -= n;
        X -= n * D;
        //X < 0
        if(K & 1){
            if(abs(X + D) > abs(X - D)){
                cout << abs(X - D) << endl;
            }
            else cout << abs(X + D) << endl;
        }
        else{
            cout << abs(X) << endl;
        }
    }
    else{
        //tien
        ll n = (-X + D - 1) / D;
        K -= n;
        X += n * D;
        //X > 0
        if(K & 1){
            if(abs(X + D) > abs(X - D)){
                cout << abs(X - D) << endl;
            }
            else cout << abs(X + D) << endl;
        }
        else{
            cout << abs(X) << endl;
        }
    }
// 
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