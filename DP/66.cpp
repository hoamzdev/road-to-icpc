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
    int state = 5;
    //duyet cac bit 1 cua state
    for(int h = state;h >= 1 ;h ^= h & -h){
        int i = __builtin_ctz(h);
        cout << i << ' ';
    }
    cout << endl;
    //duyet cac bit 0 cua state
    // int n = 3;
    for(int h = ((1 << 3) - 1) ^ state ;h >= 1;h ^= h & -h){
        int i =__builtin_ctz(h);
        cout << i << ' ';
    }
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