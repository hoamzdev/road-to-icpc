#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n;cin >> n;
    vi vst(n + 1,0);
    vi a(n + 1,0);

    a[n] = 1;
    vst[1] = 1;
    for(int i=n-1;i>=2;i--){
        a[i] = (i ^ 1);
        vst[a[i]] = 1;
    } 

    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            a[1] = i;
            break;
        }
    }
    //acc
    rep(i,1,n) cout << a[i] << " ";
    cout << endl;

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa