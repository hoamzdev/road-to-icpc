#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

bool checkNewYear(int n,string s){
    bool a = false;
    for(int i=0;i<=n - 4;i++){
        string tmp = s.substr(i,4);
        if(tmp == "2026"){
            return true;
        }
        else if(tmp == "2025"){
            a = true;
        }
    }
    //chay dc xuong day chung to ko co 2026
    return a == false;
}



void solve(){
    int n;cin >> n;
    string s;cin >> s;

    if(checkNewYear(n,s)){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
    
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa