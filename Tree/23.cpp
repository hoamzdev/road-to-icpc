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



void solve(){
    int n,k;cin >> n >> k;
    vll a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    vll dp(n + 1,-1e9 - 3);//dp[i]: tien nhieu nhat co dc khi chon den vat thu i

    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i],a[i]);

        for(int j=1;j<=k;j++){
            if(i + j <= n) dp[i + j] = max(dp[i + j],dp[i] + a[i + j]);
        }
    }

    cout << *max_element(all(dp));

}

void solve2(){
    int n,k;cin >> n >> k;
    vll a(n + 1,0);
    rep(i,1,n) cin >> a[i];

    vll dp(n + 1,0);//dp[i] : gia tri toi uu nhat tinh den i 

    deque<int> dq;

    for(int i=1;i<=n;i++){
        if(!dq.empty() && dq.front() < i - k){
            dq.pop_front();
        }

        ll max_prev = (dq.empty()) ? (-mod) : dp[dq.front()];

        dp[i] = max(a[i],max_prev + a[i]);

        while(!dq.empty() && dp[dq.back()] <= dp[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << *max_element(all(dp));
}


ll a[N];
ll T[4 * N];


void update(int node,int l,int r,int idx, ll val){
    if(l == r){
        T[node] = val;
        return;
    }

    int m = l + (r - l) / 2;
    if(idx <= m){
        update(node * 2,l,m,idx,val);
    }
    else update(node * 2 + 1,m + 1,r,idx,val);


    T[node] = max(T[node * 2],T[node * 2 + 1]);
}

ll get_val(int node,int l,int r,int u,int v){
    if(v < l || u > r) return -mod;

    if(u <= l && v >= r){
        return T[node];
    }

    int m = l + (r - l) / 2;

    ll le = get_val(node * 2,l,m,u,v);
    ll ri = get_val(node * 2 + 1,m + 1,r,u,v);

    return max(le,ri);

}

void solve3(){
    int n,k;cin >> n >> k;
    rep(i,1,n) cin >> a[i];

    fill(T,T + 4*N,-mod);

    vll dp(n + 1,0);//dp[i] :gia tr toi uu tinh den index i

    for(int i=1;i<=n;i++){
        
        ll max_val = get_val(1,1,n,max(1,i - k),i - 1);//gia tri lon nhat cua dp[i] trong [i-k,i-1]

        dp[i] = max(a[i],max_val + a[i]);

        //cap nhat lai
        update(1,1,n,i,dp[i]);
    }

    cout << *max_element(all(dp));

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
        solve3();
    }
}
//Road to ICPC 2026 - by hwa