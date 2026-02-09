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

//trau cua bai 13

void solve(){
    int n,m,k;cin >> n >> m >> k;
    int a[n + 1][6];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;
            a[i][j] = x;//so luong x cua linh kien thu j cua con robot thu i
        }
    }

    int l = 0;
    int max_len = 0;
    vi ans(m + 1,0);

    
    for(int r=0;r<n;r++){
        int sum = 0;
        vi sl;
        for(int i=0;i<m;i++){
            int tmp = 0;
            for(int j=l;j<=r;j++){
                tmp = max(tmp,a[j][i]);
            }
            sl.push_back(tmp);
            sum += tmp;
        }
        
        while(sum > k){
            sl.clear();
            int sumTmp = 0;
            for(int i=0;i<m;i++){
                int tmp = 0;
                for(int j=l + 1;j<=r;j++){
                    tmp = max(tmp,a[j][i]);
                }
                sl.push_back(tmp);
                sumTmp += tmp;
            }
            sum = sumTmp;
            l++;
        }

        //sum <= k
        if(r - l + 1 > max_len){
            max_len = r - l + 1;
            for(int i=0;i<m;i++){
                ans[i] = sl[i];
            }
        }
    }

    for(int i=0;i<m;i++) cout << ans[i] << ' ';

    cout << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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