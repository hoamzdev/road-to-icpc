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
    ll n,k;cin >> n >> k;
    
    //x = 1,y = 
    if((n - 2) % k == 0){
        cout << "Yes\n";
    }
    //x=,y = 1
    else if((n - k) % 2 == 0){
        cout <<"Yes\n";
    }
    //x = 0 || y = 0
    else if(n % 2 == 0|| n % k == 0){
        cout << "Yes\n";
    }
    else cout <<"No\n";

}
//acc
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa