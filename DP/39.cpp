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


//A
void solve(){
    int n;cin >> n;
    vi a(n + 1,-1000);
    vi b(n + 1,-1000);
    rep(i,1,n) {
        cin >> a[i];
        b[i] = a[i];
    }

    //2 case
    int case1[n + 1];
    int case2[n + 1];

    sort(all(b));

    rep(i,1,n){
        if(i & 1) {
            case1[b[i]] = 1;
            case2[b[i]] = 0;
        }
        else {
            case1[b[i]] = 0;
            case2[b[i]] = 1;
        }
    }

    //check case 1
    int ok = 1;

    rep(i,1,n - 1){
        if(case1[a[i]] == case1[a[i + 1]]){
            ok = 0;
            break;
        }
    }
    
    if(ok){
        cout << "yes\n";
        return;
    }

    ok = 1;
    rep(i,1,n - 1){
        if(case2[a[i]] == case2[a[i + 1]]){
            ok = 0;
            break;
        }
    }

    if(ok){
        cout << "yes\n";
        return;
    }

    cout << "no\n";

}
//acc
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