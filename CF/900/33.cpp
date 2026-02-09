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

struct MT{
    int m,n;//m hang, n cot
    ll d[7][7];

    MT(int _m = 0,int _n = 0){
        n = _n;
        m = _m;
        memset(d,0,sizeof(d));
    }

    MT operator *(const MT &a) const{
        MT res(m,a.n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<a.n;k++){
                    res.d[i][k] = (res.d[i][k] + 1ll * d[i][j] * a.d[j][k]+ mod) % mod; 
                }
            }
        }
        return res;
    }

    MT operator ^(ll k) const{
        MT res(n,n);
        for(int i=0;i<n;i++) res.d[i][i] = 1;

        MT mul = *this;

        while(k){
            if(k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};

void solve(){
    ll n;cin >> n;
    MT _6x6(6,6);
    for(int i=0;i<6;i++){
        _6x6.d[0][i] = 1;
    }
    
    _6x6.d[1][0] = 1;
    _6x6.d[2][1] = 1;
    _6x6.d[3][2] = 1;
    _6x6.d[4][3] = 1;
    _6x6.d[5][4] = 1;

    MT v(6,1);//[]f(n),f(n - 1),f(n-2),f(n-3),f(n-4),f(n-5)
    //ma tran khoi tao
    //f(0) = 1,f(-1) = 0....
    //f(n): so cach tao ra tong = n; f(n) = f(n - 1) + f(n-2) + f(n-3) + f(n-4) + f(n-5);

    v.d[0][0] = 1;

    MT res = (_6x6 ^ n) * v;

    cout << res.d[0][0] << endl;
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