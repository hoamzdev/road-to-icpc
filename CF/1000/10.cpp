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
    vi a(n + 1,0),b(n + 1,0);

    rep(i,1,n){
        cin >> a[i]; 
    }
    rep(i,1,n){
        cin >> b[i]; 
    }
    
    vi mpA(2 * n + 1,0),mpB(2 * n + 1,0);//mp[i] do dai day co tat ca cac gia tri la i dai nhat
    rep(i,1,n){
        int x = a[i];
        int cnt = 1;
        while(i + 1 <= n && a[i] == a[i + 1]){
            i++;
            cnt++;
        }
        mpA[x] = max(mpA[x],cnt);
        cnt = 1;
    }

    rep(i,1,n){
        int x = b[i];
        int cnt = 1;
        while(i + 1 <= n && b[i] == b[i + 1]){
            i++;
            cnt++;
        }
        mpB[x] = max(mpB[x],cnt);
        cnt = 1;
    }

    int ans = 1;

    rep(x,1,2 * n){
        ans = max(ans,mpA[x] + mpB[x]);
    }

    cout << ans << endl;

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