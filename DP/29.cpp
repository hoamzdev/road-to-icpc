#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define REP(i, l, r) for (int i = (l); i <= (r); ++i)
#define PER(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

int dp[N],pre[N],sum[N];

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    REP(i,1,n) cin >> a[i];
    REP(i,1,n){
        dp[i] = 1;//1 phan tu cx la 1 day con
        pre[i] = -1;
        sum[i] = 0;
    }
    REP(i,1,n){
        sum[i] = a[i];
        REP(j,1,i - 1){
            if(a[j] < a[i]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    sum[i] = sum[j] + a[i];
                    pre[i] = j;
                }
                else if(dp[j] + 1 == dp[i]){
                    if(sum[j] + a[i] < sum[i]){
                        sum[i] = sum[j] + a[i];
                        pre[i] = j;
                    }
                }
            }
        }
    }

    int best = 1;
    REP(i,2,n){
        if(dp[i] > dp[best] || (dp[i] == dp[best] && sum[i] < sum[best])){
            best = i;
        }
    }

    vi ans;
    while(best != -1){
        ans.push_back(best);
        best = pre[best];
    }

    reverse(all(ans));
    cout << (int)ans.size() << endl;

    for(int i : ans) cout << i << ' ';
}

//acc

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa