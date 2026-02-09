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

int n;
int ans = 0;

ll dp[N][3],a[N];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }


    //dp[i][j] : la so diem dat dc sau khi bat luot thu i khi con j vien dan
    dp[0][2] = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=2;j++){
            //nap
            dp[i + 1][2] = max(dp[i + 1][2],dp[i][j]);//khong ban
            
            //neu ban
            if(j > 0) dp[i + 1][j - 1] = max(dp[i + 1][j - 1],dp[i][j] + a[i + 1]);
        }
    }

    cout << max({dp[n][0],dp[n][1],dp[n][2]});
}

void dq(int pos, int cnt, int sum){
    if(pos == n + 1){
        //dung
        ans = max(ans,sum);
        return;
    }

    //ban
    if(cnt >= 1){
        dq(pos + 1,cnt - 1,sum + a[pos]);
    }

    //nap
    dq(pos + 1,2,sum);

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