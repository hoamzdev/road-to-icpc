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

int n;
ll k;
vll a;

//phan them vao de n chia het cho gcd
ll b(ll n, ll gcd){
    ll m = (n + gcd - 1) / gcd * gcd;//gia tri nho nhat > n chia het cho gcd
    return m - n;
}

//check
bool check(ll gcd){
    ll cnt = 0;
    FOR0(i,n){
        if(a[i] % gcd == 0) continue;
        cnt += b(a[i],gcd);
        if(cnt > k) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    a = vll(n + 1,0);
    ll M = -1e9;

    FOR0(i,n){
        cin >> a[i];
        M = max(M,a[i]);
    }


    ll ans = a[0];
    for(int i=1;i<n;i++) ans = gcd(ans,a[i]);
    ll ans1 = 1;
    ll l = 1,r = M + k;

    while(l <= r){
        ll m = l + (r - l) / 2;
        if(check(m)){
            ans1 = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    
    cout << max(ans,ans1);
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}