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

ll f[N],p[N],ft[N];

ll getHash(ll f[],int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

string shortestPalindrome(string s) {
    int n = s.size();
    string t = s;
    reverse(all(t));
    string ans = s;
    s = "%" + s;
    t = "%" + t;

    p[0] = 1;
    memset(f,0,sizeof(f));
    memset(ft,0,sizeof(ft));
    for(int i=1;i<=n;i++){
        p[i] = (p[i-1] * 31) % mod;
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
        ft[i] = (ft[i-1] * 31 + t[i] - 'a' + 1) % mod;
    }

    int idx = -1;
    
    for(int len = n;len >= 1;len --){
        int mid = len / 2;
        if(len & 1){
            //le
            ll l = getHash(f,1,mid);
            ll r = getHash(ft,n - len + 1,n - mid - 1);
            if(l == r){
                idx = len + 1;
                break;
            }
        }
        else{
            //even
            ll l = getHash(f,1,mid);
            ll r = getHash(ft,n - len + 1,n - mid);
            if(l == r){
                idx = len + 1;
                break;
            }
        }
    }
    string tmp = "";
    for(int i=idx;i<=n;i++) tmp.push_back(s[i]);
    reverse(all(tmp));
    return tmp + ans;
}

void solve(){
    string s;cin >> s;
    cout << shortestPalindrome(s);
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