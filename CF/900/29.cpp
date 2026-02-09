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
    int n;cin >> n;
    vi a(n + 1,0);
    
    unordered_map<int,int> mp;
 
    rep(i,1,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
 
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    
    if((int)mp.size() == 1){
        cout << 0 << endl;
        return;
    }
 
    int sptgnnn = 1;
 
    for(auto [f,s] : mp){
        sptgnnn = max(sptgnnn,s);
    }
    
    if(sptgnnn == n){
        cout << 0 << endl;
        return;
    }
 
    int sptkn = n - sptgnnn;
    int soLan = 0;//so lan thuc hien 
 
    while(sptkn != 0){
        soLan++;// 1 la copy
        soLan += min(sptgnnn,n - sptgnnn);
        sptgnnn += min(sptgnnn,n - sptgnnn);
        sptkn = n - sptgnnn;
    }
 
    cout << soLan << endl;
 
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