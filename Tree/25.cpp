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
const ll mod=1e9+7;
const ll modr=1e9+9;

//Truy vấn loại 1 có dạng 1 L R A B, ta cộng thêm vào phần tử thứ i thêm (i − L)A + B đơn vị với mọi L ≤ i ≤ R

ll a[N];
ll T[4 * N],lazyA[4 * N],lazyB[4 * N];

void push(ll node,ll l,ll r){
    if(lazyA[node] == 0 && lazyB[node] == 0) return;

    int m = l + (r - l) / 2;

    lazyA[2 * node] = (lazyA[node * 2] + lazyA[node]) % mod;
    lazyB[2 * node] = (lazyB[node * 2] + lazyB[node]) % mod;

    T[node * 2] = (T[node * 2] + (lazyA[node] % mod * ((m - l + 1) * (l + m) / 2) % mod) % mod + (lazyB[node] % mod * (m - l + 1)) % mod) % mod;


    lazyA[2 * node + 1] = (lazyA[node * 2 + 1] + lazyA[node]) % mod;
    lazyB[2 * node + 1] = (lazyB[node * 2 + 1] + lazyB[node]) % mod;
    
    T[node * 2 + 1] = (T[node * 2 + 1] + (lazyA[node] % mod * ((r - m) * (m + 1 + r) / 2) % mod) % mod + (lazyB[node] % mod * (r - m)) % mod) % mod;

    lazyA[node] = lazyB[node] = 0;

}

void update(ll node,ll l,ll r,ll u,ll v,ll A,ll B){
    if(v < l || u > r) return;

    if(u <= l && v >= r){
        lazyA[node] = (lazyA[node] +  A) % mod;
        lazyB[node] = (lazyB[node] +  B) % mod;
        T[node] = (T[node] + (A % mod * ((r - l + 1) * (r + l) / 2) % mod) % mod + (B % mod * (r - l + 1)) % mod) % mod;
        return; 
    }

    push(node,l,r);
    int m = l + (r - l) / 2;

    update(node * 2,l,m,u,v,A,B);
    update(node * 2 + 1,m + 1,r,u,v,A,B);

    T[node] = T[node * 2] + T[node * 2 + 1];

}

ll getSum(ll node,ll l,ll r,ll u,ll v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r){
        return T[node] % mod;
    }
    push(node,l,r);
    int m = l + (r - l) / 2;
    ll le = getSum(node * 2,l,m,u,v);
    ll ri = getSum(node * 2 + 1,m + 1,r,u,v);
    return (le + ri + mod) % mod;
}

void solve(){
    int n,q;cin >> n >> q;

    while(q--){
        int t;cin >> t;
        if(t == 1){
            ll L,R,A,B;cin >> L >> R >> A >> B;
            B = (B - (L % mod * (A % mod)) % mod + mod) % mod;
            update(1,1,n,L,R,A,B);
        }
        else{
            ll L,R;cin >> L >> R;
            ll sum = getSum(1,1,n,L,R);
            cout << sum << endl;
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
