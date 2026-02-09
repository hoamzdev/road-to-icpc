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
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

ll a[N];
ll sum[4 * N],pre[4 * N],suf[4 * N],maxSum[4 * N];

void pull(int node){
    //tong ca doan tu L den R
    int l = node * 2;
    int r = node * 2 + 1;
    sum[node] = sum[l] + sum[r];

    pre[node] = max(pre[l],sum[l] + pre[r]);

    suf[node] = max(suf[r],sum[r] + suf[l]);

    maxSum[node] = max({maxSum[l],maxSum[r],suf[l] + pre[r]});

}

void init(int node, int l, int r){
    if(l == r){
        ll v = max(0LL,a[l]);//bai cho phep mang trong  =< neu co so am -> gia tri = 0 
        sum[node] = a[l];
        pre[node] = suf[node] = maxSum[node] = v;
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    pull(node);

}

void update(int node, int l, int r, int idx,int val){
    if(l == r){
        a[idx] = val;
        ll v = max(0LL,1ll * val);
        sum[node] = val;
        pre[node] = suf[node] = maxSum[node] = v;
        return;
    }

    int m = l + (r - l) / 2;

    if(idx <= m) update(node * 2,l,m,idx,val);
    else update(node * 2 + 1,m + 1,r,idx,val);

    pull(node);

}

void solve(){
    int n,q;cin >> n >> q;
    rep(i,1,n) cin >> a[i];
    init(1,1,n);
    while(q--){
        int u,v;cin >> u >> v;
        update(1,1,n,u,v);
        cout << maxSum[1] << endl;
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