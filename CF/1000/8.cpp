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

bool cmd(pair<int,int> &a, pair<int,int> &b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve(){
    int n,k;cin >> n >> k;
    vector<pair<int,int>> v;
    rep(i,1,n){
        int x;cin >> x;
        x %= k;
        if(x == 0) x = k;
        v.push_back({x,i});
    }

    sort(all(v),cmd);

    for(auto [fi,idx] : v) cout << idx << ' ';

    cout << endl;

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