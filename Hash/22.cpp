// https://codeforces.com/problemset/problem/271/D
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const int N = 1600;

const ull base1 = 31ULL;
const ull base2 = 131ULL;

ull f1[N], p1[N];
ull f2[N], p2[N];

// custom hash for pair<ull, ull>
struct HashPair {
    size_t operator() (const pair<ull,ull> &x) const{
        return x.first ^ (x.second << 1);
    }
};


pair<ull, ull> getHash(int l, int r){
    ull h1 = f1[r] - f1[l - 1] * p1[r - l + 1];
    ull h2 = f2[r] - f2[l - 1] * p2[r - l + 1];
    return {h1, h2};
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = "@" + s; // 1-index

    // hash init
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++){
        p1[i] = p1[i - 1] * base1;
        p2[i] = p2[i - 1] * base2;
        f1[i] = f1[i - 1] * base1 + (s[i] - 'a' + 1);
        f2[i] = f2[i - 1] * base2 + (s[i] - 'a' + 1);
    }

    // good / bad chars
    int g[26];
    for(int i = 0; i < 26; i++){
        char x; cin >> x;
        g[i] = x - '0';
    }

    int k;
    cin >> k;

    // prefix bad count
    int bad[N];
    bad[0] = 0;
    for(int i = 1; i <= n; i++){
        bad[i] = bad[i - 1] + (g[s[i] - 'a'] == 0);
    }

    unordered_set<pair<ull, ull>, HashPair> ans;

    for(int len = 1; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int l = i;
            int r = i + len - 1;
            if(bad[r] - bad[l - 1] <= k){
                ans.insert(getHash(l, r));
            }
        }
    }

    cout << ans.size() << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
