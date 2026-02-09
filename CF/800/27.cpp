#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;



void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++) cin >> a[i];

    int cnt1[n + 1],cnt2[n + 5];

    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));

    for(int i=1;i<=n;i++){
        if(a[i] == 2){
            cnt1[i] = cnt1[i-1] + 1;
        }
        else cnt1[i] = cnt1[i-1];
    }

    for(int i=n;i>=1;i--){
        if(a[i] == 2){
            cnt2[i] = cnt2[i + 1] + 1;
        }
        else cnt2[i] = cnt2[i + 1];
    }


    for(int i=1;i<=n;i++){
        if(cnt1[i] == cnt2[i + 1]){
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;

}

//acc

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa