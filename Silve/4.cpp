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



// void solve(){
//     int n;cin >> n;
//     int a[n + 1];

//     for(int i=1;i<=n;i++) cin >> a[i];

//     ll pref[n + 1];

//     memset(pref,0,sizeof(pref));

//     for(int i=1;i<=n;i++){
//         pref[i] = a[i] + pref[i-1];
//     }
    
//     int cnt = 0;

//     for(int i=1;i<=n;i++){
//         bool ok = true;
//         for(int j = i;j<=n;j++){
//             if(pref[j] - pref[i-1] < 0){
//                 ok = false;
//                 break;
//             }
//         }
//         ll tmp = pref[n] - pref[i-1];
//         for(int j = 1;j<=i-1;j++){
//             if(tmp + pref[j] < 0){
//                 ok = false;
//                 break;
//             }
//         }
//         if(ok) cnt++;
//     }
//     cout << cnt;
// }

void solve(){
    int n;cin >> n;
    int a[n + 1];
    for(int i=1;i<=n;i++) cin >> a[i];
    int p[n + 1];
    
    for(int i=1;i<=n;i++) p[i] = p[i-1] + a[i];
    int xu[n + 1],nc[n + 1];

    xu[0] = p[0];
    for(int i=1;i<=n;i++) xu[i] = min(xu[i-1],p[i]);//gia tri nho nhat tinh den i
    for(int i=n;i>=1;i--){
        if(i == n) nc[i] = p[i];
        else nc[i] = min(nc[i + 1],p[i]);
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(nc[i] > p[i-1] && xu[i - 1] > (p[i-1] - p[n])) cnt++;
    }

    cout << cnt;
}

//acc
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa