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


void solve(){
    int n,m,k;cin >> n >> m >> k;
    int a[n + 1][6];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;
            a[i][j] = x;//so luong x cua linh kien thu j cua con robot thu i
        }
    }

    vector<deque<int>> dq(m + 1);

    vi ans(m + 1,0);

    int maxL = 0;

    int l = 0;

    for(int r=0;r<n;r++){
        for(int j=0;j<m;j++){
            while(!dq[j].empty() && a[dq[j].back()][j] <= a[r][j]){
                dq[j].pop_back();
            }
            dq[j].push_back(r);
        }


        //tinh tong so phat ban trong doan tu l den r ht
        while(true) {
            ll current_sum = 0;
            for(int j = 0; j < m; j++){
                if(!dq[j].empty()){
                    current_sum += a[dq[j].front()][j];
                }
            }

            if(current_sum <= k) break;

            for(int j = 0; j < m; j++){
                if(!dq[j].empty() && dq[j].front() == l){
                    dq[j].pop_front();
                }
            }

            l++;
        }

        if(r - l + 1 > maxL){
            maxL = r - l + 1;
            for(int j=0;j<m;j++){
                ans[j] = a[dq[j].front()][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        cout << ans[i] << ' ';
    }


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