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

int longestAlternating(vector<int>& a) {
    int n = a.size();
    vector<vi> L(n,vi (2,1));//do dai dai nhat thoa man tinh tu 0 den i(co 2 case [i][0] la dang tang,[i][1] la dang giam)
    //L[i]: ket thuc tai i
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1]) L[i][0] = L[i-1][1] + 1;
        else if(a[i] < a[i-1]) L[i][1] = L[i-1][0] + 1;
    }

    int ans = 1;

    //khong can xoa bat ki phan tu nao
    for(int i=1;i<n;i++) ans = max({ans,L[i][0],L[i][1]});

    vector<vi> R(n,vi (2,1));//R[i] bat dau tu i den n - 1
    for(int i = n - 2;i>=0;i--){
        if(a[i] > a[i + 1]) R[i][0] = R[i+1][1] + 1;
        else if(a[i] < a[i+1]) R[i][1] = R[i+1][0] + 1;
    }

    for(int i=0;i<n;i++) ans = max({ans,R[i][0],R[i][1]});

    //case bien
    // neu xoa phan tu cuoi cung L[n-2][0],L[n-2][1]
    //neu xoa phan tu dau tien R[1][0],R[1][1]
    ans = max({ans,L[n-2][0],L[n-2][1]});
    ans = max({ans,R[1][0],R[1][1]});
    //for gia su xoa i
    for(int i=1;i<n-1;i++){
        //tua la bayh minh xoa a[i]
        if(a[i - 1] < a[i + 1]){
            ans = max(ans,L[i-1][1] + R[i+1][0]);
        }
        else if(a[i-1] > a[i+1]){
            ans = max(ans,L[i-1][0] + R[i+1][1]);
        }
    }
    return ans;
}

void solve(){
    int n;cin >> n;
    vi a(n,0);
    rep(i,0,n-1) cin >> a[i];
    cout << longestAlternating(a) << endl;
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