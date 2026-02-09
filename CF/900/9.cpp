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

/*
6
4
1 2 3 0
8
3 1 4 1 5 9 2 6
6
1 5 4 1 4 7
5
0 0 0 0 0
7
1 1 9 9 0 1 8
3
100 100 0
*/

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    if(n % 2 == 0){
        cout << 2 << endl;
        cout << 1 << ' ' << n << endl;
        cout << 1 << ' ' << n << endl;
    }
    else{
        cout << 4 << endl;
        cout << 1 << ' ' << n - 1 << endl;
        cout << 1 << ' ' << n - 1<< endl;
        cout << n - 1 << ' ' << n << endl;
        cout << n - 1 << ' ' << n << endl;
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