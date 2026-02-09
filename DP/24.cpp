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

struct Data{
    int a,b,h;
    Data(int _a = 0,int _b = 0,int _c = 0){
        a = _a;
        b = _b;
        h = _c;
    }
};

bool cmd(Data &x, Data &y){
    if(x.a != y.a) return x.a > y.a;
    else if(x.b != y.b) return x.b > y.b;
    return x.h > y.h;
}

void solve(){
    int n;cin >> n;
    vector<Data> ve;

    for(int i=1;i<=n;i++){
        int a,b,h;cin >> a >> b >> h;
        ve.push_back(Data(a,b,h));
    }

    sort(all(ve),cmd);

    int dp[n];//dp[i]: chieu cao lon nhat dat duoc khi xep dx den vien gach thu i
    int cnt[n];//cnt[i]: so vien gach nhieu nhat co the xep chong nen nhau tinh den vien thu i

    for(int i=0;i<n;i++) {
        dp[i] = ve[i].h;//dung mot minh cung co chieu cao h
        cnt[i] = 1;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ve[j].b < ve[i].b && ve[j].a < ve[i].a){
                dp[j] = max(dp[j],dp[i] + ve[j].h);
                cnt[j] = max(cnt[j],cnt[i] + 1);
            }
        }
    }

    int ans = 0;int dem = 0;

    for(int i=0;i<n;i++) {
        ans = max(ans,dp[i]);
        dem = max(cnt[i],dem);
    }
    cout << dem << " " << ans;
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