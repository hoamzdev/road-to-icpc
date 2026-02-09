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

//https://codeforces.com/problemset/problem/271/D

ll f[N],pp[N];

ll getHash(int l,int r){
    ll ans = (f[r] - f[l - 1] * pp[r - l + 1] % mod + mod) % mod;
    return ans;
}

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = "@" + s;

    pp[0] = 1;
    for(int i=1;i<=n;i++){
        pp[i] = (pp[i-1] * 119) % mod;
        f[i] = (f[i - 1] * 119 + s[i] - 'a' + 1) % mod;
    }

    int g[27];
    for(int i=0;i<26;i++){
        char x;cin >> x;
        g[i] = x - '0';
    }
    int k;cin >> k;
    int p[27][1577];//p[c][i] tinh den indx i thi tan xuat cua c la bao nhieu
    memset(p,0,sizeof(p));

    for(int i=1;i<(int)s.size();i++){
        char c = s[i];
        p[c - 'a'][i] = p[c - 'a'][i-1] + 1;
        for(char x ='a';x <= 'z';x++){
            if(x != c){
                p[x - 'a'][i] = p[x - 'a'][i-1];
            }
        }
    }

    unordered_set<ll> ans;
    
    for(int len = 1;len <= n;len ++){
        for(int i=1;i<=n - len + 1;i++){
            int l = i;
            int r = i + len - 1;
            int tmp = k;

            for(char c = 'a';c <= 'z';c++){
                if(g[c - 'a']) continue;//ki tu dep
                int count = p[c - 'a'][r] - p[c - 'a'][l - 1];
                tmp -= count;
            }

            if(tmp >= 0){
                //chung to co toi da k ki tu xau
                ans.insert(getHash(i,i + len - 1));
            }
        }
    }
    cout << (int)ans.size() << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa