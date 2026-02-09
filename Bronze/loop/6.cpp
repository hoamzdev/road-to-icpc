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

int a[maxn];

void seive(){
    FOR0(i,maxn) a[i] = 1;
    a[0] = a[1] = 0;
    for(int i=2;i * i <= sqrt(maxn);i++){
        if(a[i]){
            for(int j =i * i;j<maxn;j+=i) a[j] = 0;
        }
    }
}

void solve(){
    int n;cin >> n;
    seive();
    if(a[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
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