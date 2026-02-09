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

int n,q;

int xorSum[1 << 20];

void solve(){
    cin >> n >> q;
    int m = 1 << n;
    for(int i=0;i<m;i++){
        cin >> xorSum[i + m];
    }

    for(int i = m - 1;i>=1;i--){
        xorSum[i] = xorSum[2 * i] ^ xorSum[2 * i + 1];
    }

    while(q--){
        int b,c;cin >> b >> c;//b la vi tr, c la ki nang moi
        
        int vttt = m + b - 1;//vi tri tren cay

        int soLuongLonHon = 0;//so luong lon hon b

        int sumXorCurr = c;
        int tp = 1;//ban dau chi co 1 con bo

        while(vttt > 1){
            int vtdt = vttt ^ 1;
            
            int xorDt = xorSum[vtdt];

            int flag = 0;
            
            if(sumXorCurr < xorDt){
                flag = 1;
            }

            if(sumXorCurr == xorDt && vtdt < vttt){
                flag = 1;
            }

            if(flag){
                soLuongLonHon += tp;
            }

            sumXorCurr ^= xorDt;
            vttt /= 2;//di chuyen nen tang tren
            //tang tren se co 2 con bo
            tp *= 2;
        }
        cout << soLuongLonHon << endl;
    }
}
//acc
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