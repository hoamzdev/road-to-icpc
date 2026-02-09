

#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=3e4+7;
const ll mod=1e9+7;
const ll modr=1e9+9;

//1044. Longest Duplicate Substring

ll f[N],p[N];

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

int checkrp(int n,int len){
    unordered_map<ll,int> mp;
    for(int i=1;i<=n - len + 1;i++){
        ll tmp = getHash(i,i + len - 1);
        mp[tmp]++;
        if(mp[tmp] > 1) return i;
    }
    return -1;
}

string longestDupSubstring(string s) {
    p[0] = 1;
    int n = s.size();
    s = "@" + s;
    for(int i=1;i<=(int)s.size();i++){
        p[i] = (p[i-1] * 31) % mod;
    }

    //hash
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
    }

    int l = 0;
    int r = n;

    string ans = "";

    while(l <= r){
        int len = l + (r - l) / 2;
        int idx = checkrp(n,len);
        if(idx != -1){
            //= true
            ans = s.substr(idx,len);
            l = len + 1;
        }
        else r = len - 1;
    }

    return ans;
}

void solve(){
    string s;cin >> s;
    cout << longestDupSubstring(s);
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