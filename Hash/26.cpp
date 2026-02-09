#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define vi vector<int>
#define fi first
#define se second
#define vull vector<ull>
const ull base1 = 131ULL;
const ull base2 = 31ULL;
const ull mod1  = 1000000007;
const ull mod2  = 1000000009;


struct HashPair {
    size_t operator()(const pair<ull, ull>& x) const {
        return x.fi ^ (x.se << 1);
    }
};

void buildHash(
    const vi& path,
    vull& f1, vull& f2,
    vull& p1, vull& p2
) {
    int n = path.size();
    f1.assign(n + 1, 0);
    f2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i - 1] * base1) % mod1;
        p2[i] = (p2[i - 1] * base2) % mod2;
        f1[i] = (f1[i - 1] * base1 + path[i - 1] + 1) % mod1;
        f2[i] = (f2[i - 1] * base2 + path[i - 1] + 1) % mod2;
    }
}

pair<ull, ull> getHash(int l, int r,
    const vull& f1, const vull& f2,
    const vull& p1, const vull& p2
) {
    ull h1 = (f1[r] - f1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    ull h2 = (f2[r] - f2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
    return {h1, h2};
}

/* check có subpath độ dài len chung cho tất cả paths không */
bool check(int len, const vector<vi>& paths) {
    if (len == 0) return true;

    unordered_set<pair<ull, ull>, HashPair> common;

    vull f1, f2, p1, p2;

    /* path đầu tiên */
    buildHash(paths[0], f1, f2, p1, p2);
    int n0 = paths[0].size();

    for (int i = 1; i + len - 1 <= n0; i++) {
        common.insert(getHash(i, i + len - 1, f1, f2, p1, p2));
    }

    /* các path tiếp theo */
    for (int id = 1; id < (int)paths.size(); id++) {
        unordered_set<pair<ull, ull>, HashPair> cur;

        buildHash(paths[id], f1, f2, p1, p2);
        int n = paths[id].size();

        for (int i = 1; i + len - 1 <= n; i++) {
            auto h = getHash(i, i + len - 1, f1, f2, p1, p2);
            if (common.count(h)) cur.insert(h);
        }

        if (cur.empty()) return false;
        common.swap(cur);   // O(1)
        //thay vi dung common = cur thì dùng swap nhanh hơn 
    }

    return true;
}

int longestCommonSubpath(int n, vector<vi>& paths) {
    int l = 0;
    int r = 1e9;

    for (auto& p : paths)
        r = min(r, (int)p.size());

    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, paths)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}


void solve(){
    int n = 5;
    vector<vi> a = {{0,1,2,3,4},
                       {2,3,4},
                       {4,0,1,2,3}};
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