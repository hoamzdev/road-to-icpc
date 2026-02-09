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
    int a,b,c,d;cin >> a >> b >> c >> d;
    if(b > d){
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    while(b < d){
        a++;
        b++;
        cnt++;
    }
    //b == d
    if(a < c){
        cout << -1 << endl;
        return;
    }
    //a >= c
    cnt += (a - c);
    cout << cnt << endl;
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