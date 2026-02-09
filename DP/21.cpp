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

int ans;
vi a;
int n,k;
vi res;
void dequy(int pos,int cnt,int sum, vi &v){
    if(cnt >= k) return;

    if(pos > n){
        if(ans < sum){
            ans = sum;
            res = v;
        }
        return;
    }

    //uong
    v.push_back(pos);
    dequy(pos + 1,cnt + 1,sum + a[pos],v);

    //khong uong
    v.pop_back();
    dequy(pos + 1,0,sum,v);
}

void solve(){
    cin >> n >> k;
    a.resize(n + 1,0);
    ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    vi v;
    res.clear();
    dequy(1,0,0,v);
    
    cout << (int)res.size() << ' ' << ans << endl;

    for(int i : res) cout << i << ' ';
    cout << endl;
    

}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa