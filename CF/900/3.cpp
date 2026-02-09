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
    int n,k;cin >> n >> k;
    string s;cin >> s;
    if(n == 1){
        cout << "yes\n";
        return;
    }
    int len = n - k;
    int a[28];
    memset(a,0,sizeof(a));
    rep(i,0,n - 1){
        a[s[i] - 'a']++;
    }

    int cnt = 0;
    rep(i,0,26){
        if(a[i] & 1) cnt++;
    }

    if(cnt == 0){
        cout << "yes\n";
        return;
    }

    if(len & 1){
        if(cnt - 1 <= k){
            cout << "yes\n";
        }
        else cout << "no\n";
    }
    else{
        if(cnt <= k) cout << "yes\n";
        else cout <<"no\n";
    }
}
//acc
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