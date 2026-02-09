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


//https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/?envType=problem-list-v2&envId=hash-function
ll fa[N],fb[N],p[N];

ll getHash(ll f[],int l,int r){
    ll ans = (f[r] - f[l - 1] * p[r - l + 1] % mod + mod) % mod;
    return ans;
}

bool checkRp(int len,int n,int m){
    unordered_set<ll> st;
    for(int i=1;i<=n - len + 1;i++){
        ll tmp = getHash(fa,i,i + len - 1);
        st.insert(tmp);
    }

    for(int i=1;i<=m - len + 1;i++){
        ll tmp = getHash(fb,i,i + len - 1);
        if(st.count(tmp) != 0){
            return true;
        }
    }
    return false;
}

int findLength(vector<int>& a, vector<int>& b) {
    p[0] = 1;
    int n = a.size();
    int m = b.size();

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    for(int i=1;i<=max(m,n);i++) p[i] = (p[i-1] * 119) % mod;

    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));

    //hash a
    for(int i=1;i<=n;i++){
        fa[i] = (fa[i-1] * 119 + a[i]) % mod;
    }
    //hash b
    for(int i=1;i<=m;i++){
        fb[i] = (fb[i-1] * 119 + b[i]) % mod;
    }

    int l = 0;
    int r = min(n,m);
    int ans = 0;

    while(l <= r){
        int lenMid = l + (r - l) / 2;
        if(checkRp(lenMid,n,m)){
            ans = lenMid;
            l = lenMid + 1;
        }
        else r = lenMid - 1;
    }
    return ans;

}


void solve(){
    vi a = {1,2,3,2,1};
    vi b = {3,2,1,4,7};
    cout << findLength(a,b);
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