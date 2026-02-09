#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;




void solve(){
    int n,m;cin >> n >> m;
    int v[n + 2],h[n + 2];
    h[0] = h[n + 1] = mod;
    
    int x[m + 1];
    memset(x,0,sizeof(x));

    for(int i=1;i<=n;i++){
        cin >> v[i];
        x[v[i]] = 1;
    }

    for(int i=1;i<=n;i++) cin >> h[i];

    // for(int i=1;i<m;i++) cout << x[i] << ' ';

    //so khoang chua nuoc
    int sk = m - 1 - n - 2;

    int dtt[sk + 1];

    int cnt = 0;
    int st = 1;
    for(int i=1;i<m;i++){
        if(x[i] == 0) cnt++;
        else{
            dtt[st++] = cnt;
            cnt = 0;
        }
    }
    dtt[st++] = cnt;

    int dtp[st];

    for(int i = 1;i<st;i++) dtp[i] = dtt[st - i];

    vi cct;

    for(int i=0;i<=n;i++){
        if(i + 1 <= n){
            int hh = min(h[i],h[i + 1]);
            cct.push_back(hh);
        }
    }
    cct.push_back(h[n]);
    vi ccp;

    for(int i=n + 1;i>=0;i--){
        if(i - 1 >= 0){
            int hh = min(h[i],h[i-1]);
            ccp.push_back(hh);
        }
    }

    for(int i=1;i<st;i++) {
        dtt[i] *= cct[i-1];
        dtt[i] *= -1;
    }

    for(int i=1;i<st;i++){
        dtp[i] *= ccp[i - 1];
        dtp[i] *=-1;
    }

    int q;cin >> q;

    while(q--){
        ll k;cin >> k;
        ll kp = k;

        //trai
        int cnt1 = 0;
        for(int i=1;i<st;i++){
            k += dtt[i];
            if(k > 0) cnt1++;
        }
        
        int cnt2 = 0;
        for(int i=1;i<st;i++){
            kp += dtp[i];
            if(kp > 0) cnt2++;
        }
        cout << cnt1 + cnt2 << endl;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa