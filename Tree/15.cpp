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
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<vi> a(n + 1,vi(m + 1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];//sl linh kien loai j cua con robot thu i
    }

    vector<deque<int>> d(m + 1);//d[i] = {};front() la index cua con robot co sl link kien loai i lon nhat

    int l = 0;
    int max_len = 0;

    vi ans(m + 1,0);

    for(int r=0;r<n;r++){

        for(int j=0;j<m;j++){
            while(!d[j].empty() && a[d[j].back()][j] <= a[r][j]){//a[r][j]: sl linh kien loai j cua con rb thu r
                d[j].pop_back();
            }
            d[j].push_back(r);
            //-> d[j] : se la list giam dan theo sl linh kien loai 
        }

        while(true){
            int sum = 0;//tong so lan ban de tieu diet doan tu l den r

            for(int i=0;i<m;i++){
                if(!d[i].empty()) sum += a[d[i].front()][i];
            }

            if(sum <= k){
                //thoa man
                break;
            }

            //ko thoa man tuc van > k

            for(int i=0;i<m;i++){
                if(!d[i].empty() && d[i].front() == l){//d[i].front() : la index cua con robot co so luong linh kien loai i lon nhat
                    d[i].pop_front();
                }
            }

            ++l;
            //vong nen tinh tong lai tu l(moi) den r
        }

        //cap nhat
        if(r - l + 1 > max_len){
            max_len = r - l + 1;
            //i la so vien dan loai i de tieu diet so link kien loai i trong doan l-r
            for(int i=0;i<m;i++){
                ans[i] = a[d[i].front()][i];
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