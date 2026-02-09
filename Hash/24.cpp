#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e3+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ll f[N],p[N];

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

int longestDecomposition(string s) {
    int n = s.size();
    s = "@" + s;
    p[0] = 1;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        p[i] = (p[i-1] * 31) % mod;
        f[i] = (f[i-1] * 31 + s[i] - 'a' + 1) % mod;
    }
    int cnt = 0;
    int st = 1;
    int en = n;

    while(st <= en){
        bool found = false;
        for(int len = 1; len <= (en - st + 1) / 2; len++){
            ll l = getHash(st, st + len - 1);
            ll r = getHash(en - len + 1, en);
            if(l == r){
                cnt += 2;
                st += len;
                en -= len;
                found = true;
                break;
            }
        }
        if(!found){
            cnt++;
            break;
        }
    }

    return cnt;
}

void solve(){
    string s;cin >> s;
    cout << longestDecomposition(s);
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