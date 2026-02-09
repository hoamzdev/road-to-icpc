#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define ull unsigned long long
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

int dx[4] = {-1,1,-1,1};
int dy[4] = {-1,-1,1,1};

void solve(){
    int a,b;cin >> a >> b;//nuoc con ma co the di trong 1 lan
    int xK,yK;cin >> xK >> yK;
    int xQ,yQ;cin >> xQ >> yQ;

    //timf cac vi tri ma con ma co the an dc K,cac vi tri co the an duoc Q
    set<pair<int,int>> killK,killQ;

    for(int i=0;i<4;i++){
        pair<int,int> pKab = {xK + dx[i] * a,yK + dy[i] * b};
        pair<int,int> pKba = {xK + dx[i] * b,yK + dy[i] * a};

        pair<int,int> pQab = {xQ + dx[i] * a,yQ + dy[i] * b};
        pair<int,int> pQba = {xQ + dx[i] * b,yQ + dy[i] * a};
        killK.insert(pKab);
        killQ.insert(pQab);
        killK.insert(pKba);
        killQ.insert(pQba);
    }

    //giao cua 2 set la an dc ca K va Q

    int ans = 0;
    for(auto it : killK){
        if(killQ.find(it) != killQ.end()) ans++;
    }

    cout << ans << endl;
}
//acc
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
//Road to ICPC 2026 - by hwa