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
    int n;cin >> n;
    string s;cin >> s;
    
    int lenM = 1;
    int cnt = 0;
    
    char state = s[0];
    cnt = 1;
    for(int i=1;i<(int)s.size();i++){
        if(s[i] == state){
            cnt++;
        }
        else{
            lenM = max(lenM,cnt);
            state = s[i];
            cnt = 1;
        }
    }
    
    lenM = max(lenM,cnt);

    cout << lenM + 1 << endl;

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