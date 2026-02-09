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
    int n,k,x;cin >> n >> k >> x;
    vi a;
    for(int i=1;i<=k;i++){
        if(i == x) continue;
        a.push_back(i);
    }
    int sz = (int)a.size();//so luong phan tu torng list
    if(sz == 0){
        cout << "no\n";
        return;
    }
    else{
        bool dp[n + 1];//dp[i] = 1: co tao dc tong  = i hay khong   
        vi ans(n + 1,-100);
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for(int i=0;i<sz;i++){
            for(int j=1;j<=n;j++){
                if(j >= a[i]){
                    if(!dp[j] && dp[j - a[i]]) {
                        dp[j] = true;
                        ans[j] = a[i];
                    }
                }
            }
        }
        if(!dp[n]){
            cout << "no\n";
            return;
        }
        cout << "yes\n";
        vi res;
        int pos = n;
        while(pos > 0){
            res.push_back(ans[pos]);
            pos -= ans[pos];
        }
        cout << (int)res.size() << endl;
        for(int i : res) cout << i << " ";
        cout << endl;
    }
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