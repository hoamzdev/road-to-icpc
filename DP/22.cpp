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

int dp[1005][1005];
pair<int,int> trace[1005][1005];

void solve(){
    int n,k;cin >> n >> k;
    vi a(n + 1,0);
    for(int i=1;i<=n;i++) cin >> a[i];

    
    dp[0][0] = 0;//dp[i][j]: so ruou da uong tinh den chai thu i va j chai lien tiep

    for(int i=0;i<n;i++){
        for(int j = 0;j<k;j++){
            if(j + 1 < k){
                //uong chai r thu i + 1
                //j + 1 chai lien tiep
                if(dp[i + 1][j + 1] < dp[i][j] + a[i + 1]){
                    dp[i + 1][j + 1] = dp[i][j] + a[i + 1];
                    trace[i + 1][j + 1] = {i,j};
                }
                // dp[i + 1][j + 1] = max(dp[i + 1][j + 1],);
            }
            //khong uong chai i + 1
            if(dp[i + 1][0] < dp[i][j]){
                dp[i + 1][0] = dp[i][j];
                trace[i + 1][0] = {i,j};
            }
        }
    }

    int ans = 0;
    int cnt = 0;
    for(int i=0;i<k;i++){
        if(ans < dp[n][i]){
            ans = dp[n][i];
            cnt = i;
        }
    }

    vi res;
    int pos = n;
    while(pos > 0){
        int pcnt = trace[pos][cnt].second;
        int ppos = trace[pos][cnt].first;

        if(cnt != 0){
            res.push_back(pos);
        }
        pos = ppos;
        cnt = pcnt;
    }

    reverse(all(res));
    cout << (int)res.size() << ' ' << ans << endl;
    for(int i : res) cout << i << ' ';

}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa