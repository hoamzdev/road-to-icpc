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

//B
int get(int l,int r,vi a){
    set<int> s;
    rep(i,l,r) s.insert(a[i]);
    rep(i,0,103){
        if(s.find(i) == s.end()){
            return i;
        }
    }
    return *s.rbegin() + 1;
}

void solve(){
    int n;cin >> n;
    vi a(n + 1,-1000);
    int cnt0 = 0;
    int cnt1 = 0;
    rep(i,1,n) {
        cin >> a[i];
        if(a[i] == 0) cnt0++;
        if(a[i] == 1) cnt1++;
    }

    if(cnt0 == 0){
        //mang khong co so 0
        cout << "no\n";
        return;
    }

    if(cnt0 != 0 && cnt1 == 0){
        if(cnt0 >= 2){
            //neu co >= 2 so 0 va khong co so 1 nao
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
        return;
    }

    sort(all(a));

    rep(i,1,n - 1){
        int l = get(1,i,a);
        int r = get(i + 1,n,a);
        if(l == r){
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}


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