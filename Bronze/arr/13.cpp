#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod 1000000007
#define INF 1000000001
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define endl '\n'
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};


void ins(vi &a,int &n,int k,int x){
    for(int i = n;i>k;i--){
        a[i] = a[i-1];
    }
    n++;
    a[k] = x;
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    cout << endl;
}


void solve(){
    int n,q;cin >> n >> q;
    vi a;

    FOR0(i,n){
        int x;cin >> x;
        a.pb(x);
    }
    
    while(q--){
        int i,x;cin >> i >> x;
        --i;
        ins(a,n,i,x);
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa