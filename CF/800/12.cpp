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
    vi a;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(i == 1) a.push_back(x);
        else{
            //i != 1
            if(x >= a.back()) a.push_back(x);
            else{
                a.push_back(x);
                a.push_back(x);
            }
        }
    }
    cout << (int)a.size() << endl;
    for(int i : a) cout << i << ' ';
    cout << endl;
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