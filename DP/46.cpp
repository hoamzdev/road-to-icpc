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

//tim so fibonaci thu n n lon

#define maxs 23

struct Mt{
    int m,n;
    ll d[maxs][maxs];
    Mt(int _m = 0,int _n = 0){
        m = _m;
        n = _n;
        memset(d,0,sizeof(d));
    }

    Mt operator * (const Mt &a) const{
        int x = m,y = n,z = a.n;
        Mt res(x,z);
        rep(i,0,x-1){
            rep(j,0,y){
                rep(k,0,z - 1){
                    res.d[i][k] = (res.d[i][k] + 1ll * d[i][j] * a.d[j][k]) % mod;
                }
            }
        }
        return res;
    }

    Mt operator ^ (ll k) const{
        Mt res(n,n);
        rep(i,0,n-1) res.d[i][i] = 1;
        Mt mul = *this;

        while(k){
            if(k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};


void solve(){
    // ll n;cin >> n;
    // Mt A = Mt(2,2);
    // A.d[0][0] = 0;
    // A.d[0][1] = 1;
    // A.d[1][0] = 1;
    // A.d[1][1] = 1;

    // Mt v0 = Mt(1,2);
    // v0.d[0][0] = 0;
    // v0.d[0][1] = 1;

    // Mt res = v0 * (A ^ n);
    // cout << res.d[0][0];
    
    int n;cin >> n;

    Mt a = Mt(4,4);

    a.d[0][0] = 0;
    a.d[0][1] = 3;
    a.d[0][2] = 0;
    a.d[0][3] = 0;

    a.d[1][0] = 1;
    a.d[1][1] = 0;
    a.d[1][2] = 2;
    a.d[1][3] = 0;

    a.d[2][0] = 0;
    a.d[2][1] = 2;
    a.d[2][2] = 0;
    a.d[2][3] = 1;

    a.d[3][0] = 0;
    a.d[3][1] = 0;
    a.d[3][2] = 3;
    a.d[3][3] = 0;

    Mt t = Mt(1,4);
    t.d[0][0] = 1;//dang o nhom 0
    t.d[0][1] = 0;
    t.d[0][2] = 0;
    t.d[0][3] = 0;

    Mt res = t * (a ^ n);
    cout << res.d[0][3] << endl;

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