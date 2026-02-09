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
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



struct MT{
    int m,n;//m hang ,n cot
    ll d[51][51];

    MT(int _m = 0,int _n = 0){
        m = _m;
        n = _n;
        memset(d,0,sizeof(d));
    }

    MT operator * (const MT &a) const{
        int x = m,y = n,z = a.n;
        MT res(x,z);
        rep(i,0,x - 1){
            rep(j,0,y-1){
                rep(k,0,z-1){
                    res.d[i][k] = (res.d[i][k] +  1ll * d[i][j] * a.d[j][k]) % mod;
                }
            }
        }
        return res;
    }

    MT operator ^ (ll k) const{
        MT res(n,n);
        rep(i,0,n - 1) res.d[i][i] = 1;
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
    MT A(3,3);
    A.d[0][0] = 1;
    A.d[0][1] = 0;
    A.d[0][2] = 0;
    A.d[1][0] = 0;
    A.d[1][1] = 0;
    A.d[1][2] = 1;
    A.d[2][0] = 1;
    A.d[2][1] = 1;
    A.d[2][2] = 1;
    
    MT v0(1,3);

    v0.d[0][0] = 1;
    v0.d[0][1] = 1;
    v0.d[0][2] = 1;

    MT res = v0 * (A ^ n);

    cout << res.d[0][0] << endl;

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