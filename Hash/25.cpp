
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ull f1[N],p1[N];
ull f2[N],p2[N];

const ull base1 = 31ULL;
const ull base2 = 131ULL;

struct HashPair{
    size_t operator() (const pair<ull,ull> &x) const{
        return x.first ^ (x.second << 1);
    }
};

pair<ull,ull> getHash(int l,int r){
    ll a = f1[r] - f1[l - 1] * p1[r - l + 1];
    ll b = f2[r] - f2[l - 1] * p2[r - l + 1];
    return {a,b};
}

int check(int n,int len){
    unordered_map<pair<ull,ull>,int,HashPair> mp;
    for(int i=1;i<=n - len + 1;i++){
        auto p = getHash(i,i + len - 1);
        if(mp[p] != 0) return mp[p];
        mp[p] = i;
    }
    return -1;
}


//1044. Longest Duplicate Substring

string longestDupSubstring(string s) {
    int n = s.size();
    s = "#" + s;

    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));

    p1[0] = 1;
    p2[0] = 1;

    for(int i=1;i<=n;i++){
        p1[i] = p1[i-1] * base1;
        p2[i] = p2[i-1] * base2;
        f1[i] = (f1[i-1] * base1 + s[i] - 'a' + 1);
        f2[i] = (f2[i-1] * base2 + s[i] - 'a' + 1);
    }

    int l = 1,r = n;

    string ans = "";
    while(l <= r){
        int m = l + (r - l) / 2;
        int ok = check(n,m);//check xem tren xau s co ton tai xau con doi xung dai len = m hay khong
        if(ok != -1){
            ans = s.substr(ok,m);
            l = m + 1;
        }
        else{
            r = m - 1;
        }
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