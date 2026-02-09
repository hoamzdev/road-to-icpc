#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

string s;
ll f[N],rf[N],p[N];
int base = 31;

ll getHash(ll a[],int l,int r){
    ll ans = (a[r] - a[l-1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}

void solve(){
    cin >> s;
    int n = (int)s.size();
    string t = s;
    s = "$" + s;
    reverse(all(t));
    t = "%" + t;
    p[0] = 1;
    for(int i=1;i<N;i++) p[i] = (p[i-1] * base) % mod;

    //hasing
    for(int i=1;i<=n;i++){
        f[i] = (f[i-1] * base + s[i] - 'a' + 1) % mod;
        rf[i] = (rf[i-1] * base + t[i] - 'a' + 1) % mod;
    }

    int ans = 0;

    //le
    //for vi tri trung tam
    for(int i = 1;i<=n;i++){
        int l = 1,r = min(i - 1,n - i);
        while(l <= r){
            int mid = l + (r - l) / 2;
            int L = i - mid;
            int R = i + mid;

            ll h = getHash(f,L,R);
            ll k = getHash(rf,n - R + 1,n - L + 1);
            if(h == k){
                ans = max(ans,2*mid + 1);
                l = mid + 1;
            }
            else r - mid - 1;
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa