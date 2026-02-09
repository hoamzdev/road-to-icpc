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

//1461. Check If a String Contains All Binary Codes of Size K
bool hasAllCodes(string s, int k) {
    unordered_set<string> uset;
    s = "@" + s;
    int n = s.size() - 1;
    for(int i = 1;i<=n - k + 1;i++){
        string tmp = s.substr(i,k);
        uset.insert(tmp);
    }
    return (int)uset.size() == pow(2,k);//dai k _> co 2 mu k cau hinh
}

void solve(){
    string s;int k;cin >> s >> k;
    cout << hasAllCodes(s,k);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa