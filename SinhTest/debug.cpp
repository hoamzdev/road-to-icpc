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


mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l ,ll h){
    return l + rd() * 1ll * rd() % (h - l + 1);
}

void makeTest(){
    ofstream inp("test.inp");
    int n = Rand(1,100);
    int x = Rand(1,100);
    inp << n << ' ' << x;
    rep(i,1,n){
        inp << 1 << ' ';
    }
    inp.close();
}


const int NTEST = 20;

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif
    srand(time(0));

    rep(i,1,NTEST){
        makeTest();
        system("trau.exe");
        system("test.exe");

        if(system("fc test.out trau.ans") != 0){
            cout << "TEST " << i << "wrong\n";
            return 0;//dung test khi gap loi sai
        }
        cout << "TEST " << i << " correct\n";
    }
}
//Road to ICPC 2026 - by hwa