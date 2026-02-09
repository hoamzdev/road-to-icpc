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



void solve(){
    int n;cin >> n;

    vi a;

    per(i,9,0){
        cout << ((n >> i) & 1);
        if((n >> i) & 1) a.push_back(i);
    }
    cout << ' ' <<  __builtin_popcount(n) << endl;

    for(int i = (int)a.size() - 1;i>=0;i--){
        cout << (1 << a[i]) << ' ';
        per(j,9,0){
            cout << (((1 << a[i]) >> j) & 1);
        }
        cout << endl;
    }

    int _or,_end;cin >> _or >> _end;
    int _xor = _or - _end;
    cout << _xor << endl;


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