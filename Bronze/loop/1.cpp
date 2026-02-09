#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod 1000000007
#define INF 1000000001
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define endl '\n'
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int shell[1001][1001];

void solve(){
    int n;cin >> n;
    FOR1(i,n) FOR1(j,3) cin >> shell[i][j];

    int res = 0;
    for(int i=1;i<=3;i++){
        int cnt = 0;
        int posStart = i;//g/s vt ban dau cua vien ngoc
        for(int j=1;j<=n;j++){
            int a = shell[j][1];
            int b = shell[j][2];
            int c = shell[j][3];
            if(posStart == a) posStart = b;
            else if(posStart == b) posStart = a;
            if(posStart == c) cnt++;
        }
        res = max(res,cnt);
    }
    cout << res;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa