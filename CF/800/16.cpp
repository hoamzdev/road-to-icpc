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

bool check(vi a){
    int n = a.size();
    int p = a[0];//gia tri lon nhat tinh den chi so i - 1
    for(int i=1;i<n;i++){
        if(a[i] < p) return false;
        p = a[i];
    }
    return true;
}

void solve(){
    int n;cin >> n;
    vi a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];

    //neu ban dau da khong tang dan
    if(!check(a)){
        cout << 0 << endl;
    }
    //neu ban dau tang dan
    else{
        int d = INT_MAX;
        for(int i=0;i<n-1;i++){
            d = min(d,abs(a[i] - a[i + 1]));
        }
        cout << (d / 2) + 1 << endl;
    }
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