#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1007050321;
const ll modr=1e9+9;

ll cnt[4 * N];
ll v[4 * N];
ll pow2[N];
string s;


void pull(int node) {
    int left = node * 2;
    int right = node * 2 + 1;

    cnt[node] = cnt[left] + cnt[right];

    v[node] = (v[left] * pow2[cnt[right]] + v[right]) % mod;
}

void init(int node, int l, int r) {
    if (l == r) {
        cnt[node] = 1;  
        v[node] = s[l-1] - '0';
        return;
    }
    int m = l + (r - l) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    pull(node);
}


void update(int node, int l, int r, int idx) {
    if (l == r) {
        cnt[node] = 0;
        v[node] = 0;
        return;
    }

    int m = l + (r - l) / 2;
    if (idx <= cnt[node * 2]) {
        update(node * 2, l, m, idx);
    } else update(node * 2 + 1, m + 1, r, idx - cnt[node * 2]);
    
    pull(node);
}

struct Res {
    ll count;
    ll val;
};

Res query(int node, int l, int r, int u, int vv) {
    if (u <= 1 && cnt[node] <= vv) {
        return {cnt[node], v[node]};
    }

    int m = l + (r - l) / 2;
    int leftCount = cnt[node * 2];

    if (u > leftCount) {
        return query(node * 2 + 1, m + 1, r, u - leftCount, vv - leftCount);
    }
    
    if (vv <= leftCount) {
        return query(node * 2, l, m, u, vv);
    }

    Res leftRes = query(node * 2, l, m, u, leftCount);
    Res rightRes = query(node * 2 + 1, m + 1, r, 1, vv - leftCount);

    return {
        leftRes.count + rightRes.count,
        (leftRes.val * pow2[rightRes.count] + rightRes.val) % mod
    };
}

void solve() {
    int n, q;
    cin >> s;
    n = s.size();
    cin >> q;
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = (pow2[i - 1] * 2) % mod;

    init(1, 1, n);

    while (q--) {
        char type; cin >> type;
        if (type == '-') {
            int p; cin >> p;
            update(1, 1, n, p);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r).val << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa