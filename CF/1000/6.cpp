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
    int n,k;cin >> n >> k;
    vector<set<int>> se(n);//se[i]: ds cac ki tu xuat hien o cot i

    rep(i,1,k){
        string s;cin >> s;
        for(int j=0;j<(int)s.size();j++){
            se[j].insert(s[j] - 'a');
        }
    }

    vi div;
    rep(i,1,sqrt(n)){
        if(n % i == 0){
            div.push_back(i);
            if(i != n / i) div.push_back(n / i);
        }
    }

    sort(all(div));

    for(int i=0;i<(int)div.size();i++){
        int d = div[i];
        string ans = "";
        int found = 1;
        
        for(int j=0;j<d;j++){
            char c;
            int oke = -1;
            for(int cc : se[j]){
                int check = 1;
                for(int k = j + d;k < n;k+=d){
                    if(se[k].find(cc) == se[k].end()){
                        check = 0;
                        break;
                    }
                }
                //if check = 0 chung to ki tu c ko thoa man nam o tat ca cac cot theo chu ki
                if(check == 1){
                    c = cc + 'a';
                    oke = 1;
                    break;
                }
            }
            if(oke == 1) {
                ans.push_back(c);
            }
            else {
                found = -1;
                break;
            }
        }

        if(found == 1){
            for(int t=0;t<n/d;t++){
                cout << ans;
            }
            cout << endl;
            return;
        }
    }
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
        solve();
    }
}
//Road to ICPC 2026 - by hwa