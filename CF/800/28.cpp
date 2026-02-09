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
    set<int> s;
    int M1 = INT_MIN;
    vi a(n + 1,0);
    int idx = -1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s.insert(a[i]);
        if(a[i] > M1){
            M1 = a[i];
            idx = i;
        }
    }

    if((int)s.size() == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << M1 << ' ';
    for(int i=1;i<=n;i++){
        if(a[i] != M1){
            cout << a[i] << ' ';
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i] == M1 && i != idx){
            cout << a[i] << ' ';
        }
    }
    cout << endl;
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