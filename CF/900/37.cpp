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



void solve2(){
    ll n;cin >> n;

    if(n % 25 == 0){
        cout << 0 << endl;
        return;
    }

    int f0 = -1,f5 = -1;

    string s = to_string(n);

    n = s.size();
    
    for(int i = n - 1;i>=0;i--){
        if(s[i] == '5' && f5 == -1) f5 = i;
        if(s[i] == '0' && f0 == -1) f0 = i;
        if(f5 != -1 && f0 != -1) break;
    }

    int cnt = mod;

    if(f5 != -1){
        for(int i = f5 - 1;i>=0;i--){
            int x = (s[i] - '0') * 10 + 5;
            if(x % 25 == 0){
                cnt = (f5 - i - 1) + (n - f5 - 1);
                break;
            }    
        }
    }
    
    int cnt2 = mod;
    if(f0 != -1){
        for(int i = f0 - 1;i>=0;i--){
            int x = (s[i] - '0') * 10;
            if(x % 25 == 0){
                cnt2 = (f0 - i - 1) + (n - f0 - 1);
                break;
            }
        }
    }
    
    if(cnt == mod && cnt2 == mod){
        cout << n << endl;
        return;
    }
    cout << min(cnt,cnt2) << endl;
        
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
        solve2();
    }
}
//Road to ICPC 2026 - by hwa