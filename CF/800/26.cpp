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

int _gcd(int a, int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int flag = 0;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int x = _gcd(a[i],a[j]);
            if(x <= 2){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout << "Yes\n";
    }
    else cout << "no\n";
}


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