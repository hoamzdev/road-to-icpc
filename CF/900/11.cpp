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



void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int check = 0;
    rep(i,0,n - 1){
        if(s[i] == '0'){
            check = 1;
            break;
        }
    }

    if(check == 0){
        cout << 0 << endl;
        return;
    }

    int sls0 = 0;//so luong so 0 lien tiep
    if(s[0] != '0'){
        int sl = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') sl++;
            else{
                sls0 = max(sls0,sl);
                sl = 0;
            }
        }
        sls0 = max(sls0,sl);
    }
    else{
        int i = 0;
        while(s[i] == '0'){
            sls0++;
            i++;
        }
        int j = n - 1;
        while(s[j] == '0'){
            sls0++;
            j--;
        }
        int sl = 0;
        for(int k=i;k<=j;k++){
            if(s[k] == '0') sl++;
            else{
                sls0 = max(sl,sls0);
                sl = 0;
            }
        }
        sls0 = max(sls0,sl);
    }

    cout << sls0 << endl;

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