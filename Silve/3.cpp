#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define maxn 1000005

int pre[maxn];

int get(int n){
    int res = 0;
    while(n){
        res += (n % 10);
        n/=10;
    }
    return res;
}

void sieve(){
    for(int i=0;i<maxn;i++) pre[i] = 1;
    pre[1] = pre[0] = 0;
    for(int i=2;i * i<=maxn;i++){
        if(pre[i]){
            for(int j = i * i;j<maxn;j+=i) pre[j] = 0;
        }
    }
}


void solve(){
    sieve();
    string s = "";
    for(int i = 2;i<maxn;i++){
        if(pre[get(i)]) s += to_string(i);
    }
    //note o day -> bai toan con la cat xau
    // cout << s << endl;
    int t;cin >> t;
    while(t--){
        int x;cin >> x;
        vector<int> idx;

        string n = to_string(x);
        int st = s.find(n) + 1;
        cout << st << endl;
    }
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 🚀💻🔥- by hwa