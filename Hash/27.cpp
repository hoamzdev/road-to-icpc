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
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

const ull base1 = 131ULL;
const ull base2 = 31ULL;

ull f1[N],p1[N];
ull f2[N],p2[N];


void buildHash(vi path){    
    p1[0] = 1;
    p2[0] = 1;
    int n = path.size();
    for(int i=1;i<=n;i++){
        f1[i] = 0;
        f2[i] = 0;
    }
    for(int i=1;i<=n;i++){
        p1[i] = (p1[i-1] * base1) % mod;
        p2[i] = (p2[i-1] * base2) % modr;
        f1[i] = (f1[i-1] * base1 + path[i - 1] + 1) % mod;
        f2[i] = (f2[i-1] * base2 + path[i - 1] + 1) % modr;
    }
}

struct HashPair{
    size_t operator() (const pair<ull,ull> &x) const{
        return x.first ^ (x.second << 1);
    }
};

pair<ull,ull> getHash(int l,int r){
    ll h1 = (f1[r] - f1[l - 1] * p1[r - l + 1] % mod + mod) % mod;
    ll h2 = (f2[r] - f2[l - 1] * p2[r - l + 1] % modr + modr) % modr;
    return {h1,h2};
}

bool check(int len,vector<vi> &paths){
    vi start = paths[0];
    if(len > (int)start.size()) return false;
    buildHash(start);
    unordered_set<pair<ull,ull>,HashPair> cm;

    for(int i=1;i<=(int)start.size() - len + 1;i++){
        cm.insert(getHash(i,i + len - 1));
    }

    //bat dau ss cs cac day con ben duoi
    for(int i=1;i<(int)paths.size();i++){
        if(len > (int)paths[i].size()) return false;
        unordered_set<pair<ull,ull>,HashPair> giao;
        buildHash(paths[i]);
        for(int j=1;j<=(int)paths[i].size() - len + 1;j++){
            if(cm.count(getHash(j,j + len - 1))) giao.insert(getHash(j,j + len - 1));
        }
        if(giao.empty()){
            return false;
        }
        //khac : chung to co su trung lap
        cm.swap(giao);
    }
    return true;
}

int longestCommonSubpath(int n, vector<vi>& paths) {
    int l = 1;
    int r = 1e9;
    for(auto it : paths) r = min(r,(int)it.size());

    int ans = 0;

    while(l <= r){
        int m = l + (r - l) / 2;
        bool ok = check(m,paths);
        if(ok){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return  ans;
}

void solve(){
    int n = 5;
    vector<vi> a = {{0,1,2,3,4},
                       {2,3,4},
                       {4,0,1,2,3}};
                       cout << longestCommonSubpath(n,a);
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