#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define REP(i, l, r) for (int i = (l); i <= (r); ++i)
#define PER(i, r, l) for (int i = (r); i >= (l); --i)
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

int f[N],cnt[N];

void solve(){
    int n;cin >> n;
    vi a(n + 1,0);
    REP(i,1,n) {
        cin >> a[i];
        cnt[a[i]] += 1;//danh dau a[i] co ton tai trong mang(dem tan xuat xuat hien cua phan tu a[i])
    }

    sort(all(a));

    int ans = 0;
    REP(i,1,1e6){
        f[i] = max(f[i],cnt[i]);
        //duyet tat ca cac boi cua i ton tai trong mang
        for(int j = i + i;j<=1e6;j+=i) if(cnt[j] != 0){
            f[j] = max(f[j],f[i] + cnt[j]);//so luong cua day con ket thhuc tai gia tri j
        }
        ans = max(ans,f[i]);
    }

    cout << n - ans;

}

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