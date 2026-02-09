#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
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
    vi a(n),b(m);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,m-1) cin >> b[i];

    sort(all(b));

    string trans;cin >> trans;

    unordered_map<int,int> first_time;//thoi diem dau tien di dc khoang cach curr

    int curr = 0;
    rep(i,0,k-1){
        if(trans[i] == 'L') curr--;
        else curr++;

        //neu lan dau gap
        if(first_time.count(curr) == 0) first_time[curr] = i;
    }

    vi slc(k + 1,0);//slc[i] : so luong con robot chet tai thoi diewm i

    rep(i,0,n-1){
        int tmp = k;//luu lai thoi diem (luot dau tien) ma con x chet
        auto it = lower_bound(all(b),a[i]);
        if(it != b.end()){
            int distR = *it - a[i];

            if(first_time.count(distR) != 0){
                tmp = min(tmp,first_time[distR]);
            }
        }
        if(it != b.begin()){
            int distL = *prev(it) - a[i];

            if(first_time.count(distL) != 0){
                tmp = min(tmp,first_time[distL]);
            }
        }
        
        //neu tmp < k thi chung to da gap trc khi ket thuc k luot di chuyen roi -> chung to tai luot tmp co them 1 con robot chet
        if(tmp < k){
            slc[tmp]++;
        }
        
    }

    int alive = n;//ban dau mac dinh song het
    
    rep(i,0,k-1){
        alive -= slc[i];
        cout << alive << ' ';
    }
    cout << endl;

}
//acc

int main(){
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