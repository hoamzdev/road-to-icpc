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

ll f[N],p[N];
int base = 31;
int n,k;

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] + mod * mod) % mod;
    return ans;
}

bool check(int len){
    unordered_map<ll,int> mp;
    for(int i=1;i<=n - len + 1;i++){
        ll tmp = getHash(i,i + len - 1);
        // cout << tmp << endl;
        mp[tmp]++;
        if(mp[tmp] >= k) return true;
    }
    return false;
}

void solve(){
    string s;
    cin >> n >> k >> s;
    s = "1" + s;
    p[0] = 1;
    for(int i=1;i<N;i++) p[i] = (p[i-1] * base) % mod;

    memset(f,0,sizeof(f));

    for(int i=1;i<=n;i++) f[i] = (f[i-1] * base + s[i] - 'a' + 1) % mod;

    int l = 1,r = n;
    int ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        bool ok = check(mid);
        // cout << endl << endl;
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    cout << ans << endl;

    // cout << check(4);

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