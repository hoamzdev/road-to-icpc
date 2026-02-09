#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

void solve(){
    int n,k;cin >> n >> k;
    set<int> s;

    for(int i=1;i<=n;i++){
        int x;cin >> x;
        s.insert(x);
    }

    if(s.find(k) != s.end()) cout << "yes\n";
    else cout << "no\n";

}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa