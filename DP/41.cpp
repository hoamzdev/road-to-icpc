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


//C
void solve(){
    int n;cin >> n;
    vi s,tmp;
    rep(i,1,n){
        char x;cin >> x;
        s.push_back(x - '0');
        tmp.push_back(x - '0');
    }

    sort(all(tmp));

    vi idx;

    rep(i,0,n-1){
        if(s[i] != tmp[i]) idx.push_back(i);
    }
    
    if((idx.empty())){
        cout << "Bob";
    }
    else{
        cout << "Alice\n";
        cout << (int)idx.size() << endl;
        for(int i : idx) cout << i + 1 << ' ';
    }
    cout << endl;
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