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
    vi b,c;
    map<int,int> mp;
    int M = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        mp[x]++;
        M = max(M,x);
    }

    if((int)mp.size() == 1){
        cout << -1 << endl;
        return;
    }

    for(auto [f,s] : mp){
        if(f == M) break;
        for(int i=0;i<s;i++){
            b.push_back(f);
        }
    }

    for(int i=0;i<mp[M];i++){
        c.push_back(M);
    }

    cout << (int)b.size() << ' ' << (int)c.size() << endl;

    for(int i : b) cout << i << ' ';
    cout << endl;
    for(int i : c) cout << i << ' ';
    cout << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa