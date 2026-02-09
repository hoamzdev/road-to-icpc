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



void solve(){
    int n;cin >> n;
    vi a(n,0);

    FOR0(i,n) cin >> a[i];
    int res = 0;
    int M = a[n-1];
    for(int i = n - 2;i>=0;i--){
        if(a[i] > M) res++;
        M = max(M,a[i]);
    }
    cout << res << endl;
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