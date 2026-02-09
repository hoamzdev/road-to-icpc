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
    string s;cin >> s;
    s = "@" + s;
    int n = s.size();
    int dp[27][n + 1];//dp['c'][i] : tan xuat cua ki tu c tinh den idex i
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(char c = 'a';c <= 'z';c++){
            dp[c - 'a'][i] = dp[c - 'a'][i-1];
        }
        dp[s[i] - 'a'][i] = dp[s[i] - 'a'][i - 1] + 1;
    }

    int q;cin >> q;
    while(q--){
        int l,r;cin >> l >> r;
        vector<char> ve;
        for(char c = 'a';c <= 'z';c++){
            if(dp[c - 'a'][r] - dp[c - 'a'][l - 1] > 0){
                //chung to ki tu c co ton tai trong doan [l,r]
                ve.push_back(c);
            }
        }

        int ans = 0;
        for(int i=0;i<(int)ve.size() - 1;i++){
            for(int j = i + 1;j<(int)ve.size();j++){
                int d = abs(ve[i] - ve[j]);
                d = min(d,26 - d);
                ans = max(ans,d);
            }
        }
        cout << ans << endl;
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
//Road to ICPC 2026 - by hwa