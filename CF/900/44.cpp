#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
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
    vi a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    int ii = 0,jj = 0,kk = -1;

    ii = 1;

    for(int i=2;i<=n;i++){
        if(ii != 0 && jj != 0){
            if(a[i] < a[jj]){
                kk = i;
                break;
            }
        }
        if(a[i] > a[ii] && a[i] > a[jj]){
            jj = i;
        }
        else if(a[i] < a[ii]){
            ii = i;
        }
    }

    if(kk == -1) cout << "NO"<< endl;
    else {
        cout << "YES" << endl;
        cout << ii << ' ' << jj << ' ' << kk << endl; 
    }
//acc
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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