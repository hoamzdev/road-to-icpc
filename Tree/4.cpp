#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
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

int a[N];
int T[4 * N + 1];

void init(int node,int l,int r){
    if(l == r){
        T[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    init(node * 2,l,m);
    init(node * 2 + 1,m + 1,r);

    T[node] = max(T[node * 2],T[node * 2 + 1]);
}

//update
void update(int node,int l,int r,int idx,int val){
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

//get_max

int get_max(int node,int l,int r,int u,int v){
    
    if(v < l || u > r) return -1e6;
    if(u <= l && v >= r) return T[node];
    int m = l + (r - l) / 2;

    int le = get_max(node * 2,l,m,u,v);
    int ri = get_max(node * 2 + 1,m + 1,r,u,v);

    return max(le,ri);
}

void solve(){
    int n,q;cin >> n >> q;

    memset(a,0,sizeof(a));

    init(1,1,n);

    while(q--){
        char t;cin >> t;
        int x,y;cin >> x >> y;
        if(t == 'S'){
            update(1,1,n,x,y);
        }
        else{
            cout << get_max(1,1,n,x,y) << endl;
        }
    }



}

int main(){
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