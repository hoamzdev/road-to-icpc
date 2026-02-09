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

void A(int,int);
void B(int,int);
void solve(){
    int n,k;cin >> n >> k;
    B(n,k);
}

//chuyen doi n ve he co so k
void A(int n,int k){
    string s = "";

    while(n != 0){
        s.push_back((n % k) + '0');
        n/=k;
    }
    
    reverse(all(s));
    cout << s;
}

//n dang o he co so k chuyen n ve he co so 10
void B(int n,int k){
    int ans = 0;
    string s = to_string(n);
    for(int i=0;i<(int)s.size();i++){
        ans = ans * k + s[i] - '0';
    }
    cout << ans;
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