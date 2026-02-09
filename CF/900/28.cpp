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
    string s,t;cin >> s >> t;


    unordered_map<int,stack<int>> dp;

    int cnt[101];
    memset(cnt,0,sizeof(cnt));

    for(char c : t) cnt[c - 'A']++;

    for(int i=(int)s.size() - 1;i>=0;i--){
        if((int)dp[s[i] - 'A'].size() < cnt[s[i] - 'A'] || dp[s[i] - 'A'].empty()){
            dp[s[i] - 'A'].push(i);
        }
    }


    int start = -1;

    if(!dp[t[0] - 'A'].empty()){
        start = dp[t[0] - 'A'].top();
        dp[t[0] - 'A'].pop();
    }

    if(start == -1){
        cout << "NO" << endl;
        return;
    }


    // cout << start << ' ';

    for(int i=1;i<(int)t.size();i++){
        if(dp[t[i] - 'A'].empty()){
            cout << "NO" << endl;
            return;
        }

        int curr = dp[t[i] - 'A'].top();dp[t[i] - 'A'].pop();
        if(curr < start){
            cout << "NO" << endl;
            return;
        }
        start = curr;
        // cout << start << ' ';
    }

    // cout << endl;
    cout << "YES" << endl;

}


void solve2(){
    string s,t;cin >> s >> t;

    int cnt[30];
    memset(cnt,0,sizeof(cnt));
    for(char c : t) cnt[c - 'A']++;


    string res;

    for(int i = (int)s.size() - 1;i>=0;i--){
        if(cnt[s[i] - 'A'] > 0){
            //minh van can s[i]
            res.push_back(s[i]);
            cnt[s[i] - 'A']--;
        }
    }

    reverse(all(res));

    if(res == t) cout << "YES" << endl;
    else cout << "NO" << endl;

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