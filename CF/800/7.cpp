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


void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    int cnt = 0;

    while (x.size() < s.size()) {
        x += x;
        cnt++;
    }

    for (int i = 0; i <= 2; i++) {
        if (x.find(s) != string::npos) {
            cout << cnt << endl;
            return;
        }
        x += x;
        cnt++;
    }

    cout << -1 << endl;
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