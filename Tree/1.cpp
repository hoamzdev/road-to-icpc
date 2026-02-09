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

int n,a[N];
int T[4 * N],delta[4 * N];

void init(int node,int l,int r){
    if(l > r) return;
    if(l == r){
        T[node] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = max(T[node * 2], T[node * 2 + 1]);//nhanh trai , nhanh phai
}

void update(int node,int l,int r,int idx,int w){
    //tac dong viec tang doan u v nen doan co dinh L - R
    if(l == r){
        a[idx] = w;
        T[node] = w;
        return;
    }

    int mid  = l + (r - l) / 2;

    if(idx <= mid){
        update(node * 2,l,mid,idx,w);
    }
    else {
        update(node * 2 + 1,mid + 1,r,idx,w);
    }

    T[node] = max(T[node * 2],T[node * 2 + 1]);
}

int get_max(int node,int l,int r,int u,int v){
    if(u > r || v < l) return -mod;//khong giao nhau

    //chua nhau
    if(u <= l && v >= r){
        return T[node];//giao la [l,r]
    }

    int mid = l + (r - l) / 2;

    int maxL = get_max(node * 2,l,mid,u,v);
    int maxR = get_max(node * 2 + 1,mid + 1,r,u,v);
    
    return max(maxL,maxR);
}

void solve(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int q;cin >> q;
    init(1,1,n);

    while(q--){
        int type,u,v;cin >> type >> u >> v;
        if(type == 1){
            update(1,1,n,u,v);
        }
        else{
            //get max
            cout << get_max(1,1,n,u,v) << endl;
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