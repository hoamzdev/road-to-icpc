#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;


void solve(){
    int a,b;cin >> a >> b;
    int aa = a;
    int bb = b;
    int ans1 = 0;
    int top = 1;
    while(aa >= 0){
        if(aa - top >= 0){
            aa -= top;
            ans1++;
            top *= 2;
        }
        else break;
        if(bb - top >= 0){
            bb -= top;
            ans1++;
            top *= 2;
        }
        else break;
    }
    top = 1;
    aa = b;
    bb = a;
    int ans2 = 0;
    while(aa >= 0){
        if(aa - top >= 0){
            aa -= top;
            ans2++;
            top *= 2;
        }
        else break;
        if(bb - top >= 0){
            bb -= top;
            ans2++;
            top *= 2;
        }
        else break;
    }
    cout << max(ans1,ans2) << endl;
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