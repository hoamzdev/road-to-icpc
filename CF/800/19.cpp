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
    int n;cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x]++;
    }

    int ans = 0;

    if(mp[-1] > mp[1]){
        int d = mp[-1] - mp[1];
        if(d % 2 == 1){
            ans = (d / 2) + 1;
        }
        else ans = d / 2;
        mp[-1] -= ans;
    }

    if(mp[-1] % 2 == 1){
        ans++;
    }

    cout << ans << endl;
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