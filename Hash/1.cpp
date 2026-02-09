#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

//https://oj.vnoi.info/problem/olp_kc23_tseq

void solve(){
    ll u,v;cin >> u >> v;
    ll S = u * u + v * v;
    cout << S / 4 << '.';
    if(S % 4 == 0) cout << "00" << endl;
    else if(S % 4 == 1) cout << "25" << endl;
    else if(S % 4 == 2) cout << "50" << endl;
    else cout << "75" << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa