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
ll hA = 0,hB = 0;

bool check(int j,int i,int k){
    return abs(j - i) <= k;
}

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

vector<int> beautifulIndices(string s, string a, string b, int k) {
    int n = s.size();
    int na = a.size();
    int nb = b.size();
    s = "@" + s;
    a = "@" + a;
    b = "@" + b;

    p[0] = 1;
    for(int i=1;i<=n;i++) p[i] = p[i-1] * 31 % mod;
    for(int i=1;i<=n;i++) f[i] = (f[i-1] * 31 + (s[i]-'a'+1)) % mod;

    ll hA=0,hB=0;
    for(int i=1;i<=na;i++) hA = (hA * 31 + (a[i]-'a'+1)) % mod;
    for(int i=1;i<=nb;i++) hB = (hB * 31 + (b[i]-'a'+1)) % mod;

    vi posB;
    for(int j=1;j<=n-nb+1;j++){
        if(getHash(j,j+nb-1) == hB){
            posB.push_back(j);
        }
    }

    vi ans;
    for(int i=1;i<=n-na+1;i++){
        if(getHash(i,i+na-1) != hA) continue;
        for(int j : posB){
            if(check(j,i,k)){
                ans.push_back(i - 1);
                break;
            }
        }
    }
    return ans;
}

void solve(){
    string s,a,b;int k;cin >> s >> a >> b >> k;
    vi aa = beautifulIndices(s,a,b,k);
    for(int i : aa) cout << i << ' ';
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