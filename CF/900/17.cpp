#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define fi first
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

// bool cmd(pair<int,int> &a, pair<int,int> &b){
//     if(a.first != b.first) return a.first < b.first;
//     return a.second < b.second;
// }

void solve(){
    int n,Ax,Ay,Bx,By;cin >> n >> Ax >> Ay >> Bx >> By;

    map<int,int> minYcuaX;//voi moi cot x thi luu lai Y cao nhat cua cai cot do
    map<int,int> maxYcuaX;//voi moi cot x thi luu lai Y thap nhat cua cai cot do

    vi x(n + 1,0);
    vi y(n + 1,0);

    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) cin >> y[i];

    for(int i=1;i<=n;i++){
        //chua xuat hien
        if(minYcuaX.count(x[i]) == 0){
            minYcuaX[x[i]] = y[i];
            maxYcuaX[x[i]] = y[i];
        }
        //xuat hien r thi lay y cao nhat, y thap nhat cua cot x
        else{
            minYcuaX[x[i]] = min(minYcuaX[x[i]],y[i]);
            maxYcuaX[x[i]] = max(maxYcuaX[x[i]],y[i]);
        }
    }

    minYcuaX[Ax] = maxYcuaX[Ax] = Ay;
    minYcuaX[Bx] = maxYcuaX[Bx] = By;

    //cot ket huc la cot Bx

    vector<pair<int,pair<int,int>>>  v;
    //v[x[i]] = {minY cua x[i],maxY cua x[i]}

    for(auto [x,y] : minYcuaX){
        v.push_back({x,{y,maxYcuaX[x]}});
    }

    // sort(all(v),cmd);

    int sz = v.size();

    ll dp[sz + 1][3];//dp[i][j]: chi phi den cot thu i vs trang thai j
    //j = 0, ket thuc y thap nhat
    //j = 1, ket thuc y cao nhat

    dp[0][0] = dp[0][1] = 0;

    for(int i=0;i<sz;i++){
        if(i == 0){
            //bat dau tai Ax,Ay
            continue;
        }

        int x = v[i].first;
        auto [minY,maxY] = v[i].second;
        auto [minY_truoc,maxY_truoc] = v[i - 1].second;

        int distX = x - v[i-1].first;
        //case 1
        //ket thuc o minY cua cot i
        dp[i][0] = min(dp[i-1][0] + abs(maxY - minY_truoc),dp[i-1][1] + abs(maxY - maxY_truoc)) + distX + maxY - minY;
        //case 2
        //ket thuc o maxY cua cot i
        dp[i][1] = min(dp[i-1][0] + abs(minY - minY_truoc),dp[i-1][1] + abs(minY - maxY_truoc)) + distX + maxY - minY;

    }

    cout << dp[sz - 1][0] << endl;
    //tai Bx,By minY,maxY trung nhau

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa