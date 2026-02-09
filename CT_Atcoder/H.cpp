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
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

const int MAXN = 300005;
int tree[4 * MAXN];
int n, m;

// Cập nhật giá trị tại vị trí p thành val -> da hieu
void update(int node, int start, int end, int p, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (p <= mid) update(2 * node, start, mid, p, val);
    else update(2 * node + 1, mid + 1, end, p, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Tính tổng trong đoạn [l, r] -> da hieu
int cnt_(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return cnt_(2 * node, start, mid, l, r) + cnt_(2 * node + 1, mid + 1, end, l, r);
}

void solve() {
    cin >> n >> m;

    vi raw_a(n);
    for (int &x : raw_a) cin >> x;

    vi a;
    vector<ll> cnt(m + 1, 0);
    //nen lai ko cho hai phan tu giong nhau dung canh nhau
    for (int x : raw_a) {
        if (a.empty() || a.back() != x) {
            a.push_back(x);
            cnt[x]++;
        }
    }
    int sz = a.size();

    ll total_ans = 0;
    for (int i = 1; i <= m; i++) {
        total_ans += cnt[i] * (m - 1);
    }

    vi prev_pos(m + 1, -1);
    for (int i = 0; i < sz; i++) {
        int val = a[i];
        int L = prev_pos[val];

        if (L != -1) {

            int k = cnt_(1, 0, sz - 1, L + 1, i - 1);
            
    
            total_ans -= (m - 1 - k);
        
            update(1, 0, sz - 1, L, 0);
        }

        update(1, 0, sz - 1, i, 1);
        prev_pos[val] = i;
    }

    cout << total_ans << endl;
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