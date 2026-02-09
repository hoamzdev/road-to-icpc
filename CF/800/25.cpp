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
    string s;cin >> s;
    int r = n - 1;
    int l = 0;
    while(l <= r){
        if((s[l] == '1' && s[r] == '0') || (s[l] == '0' && s[r] == '1')){
            l++;
            r--;
        }
        else break;
    }
    if(l <= r){
        cout << r - l + 1 << endl;
    }
    else cout << 0 << endl;
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