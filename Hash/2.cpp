#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

void solve(){
    int n,q;cin >> n >> q;
    string s;cin >> s;
    s = "@" + s;
    vector<vi> a(26,vi(n + 1,0));

    for(int i=1;i<=n;i++){
        char c = s[i];
        a[c - 'a'][i] = a[c - 'a'][i-1] + 1;
        for(char x = 'a';x <= 'z';x++){
            if(c != x) a[x - 'a'][i] = a[x - 'a'][i-1];
        }
    }

    while(q--){
        int st,en;cin >> st >> en;
        st++;
        en++;
        int cnt = 0;
        for(int c = 'a';c <= 'z';c++){
            int tmp = (a[c - 'a'][en] - a[c - 'a'][st - 1]);
            if(tmp & 1) cnt++;
        }
        cout << cnt / 2 << endl;
    }
}


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa