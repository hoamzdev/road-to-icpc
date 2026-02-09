#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// dp[vị trí][chữ số trước][trạng thái][tight][leading_zero]
ll dp[100005][13][3][2][2];

ll dg(int pos, int lastDigit, int state, bool tight, bool isLeadingZero, string &s) {
    if (pos == (int)s.size()) {
        return isLeadingZero ? 0 : 1;
    }

    if (dp[pos][lastDigit][state][tight][isLeadingZero] != -1)
        return dp[pos][lastDigit][state][tight][isLeadingZero];

    ll res = 0;
    int limit = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        bool nextTight = tight && (d == limit);
        
        if (isLeadingZero) {
            if (d == 0) {
                res = (res + dg(pos + 1, 0, 0, nextTight, true, s)) % MOD;
            } else {
                res = (res + dg(pos + 1, d, 0, nextTight, false, s)) % MOD;
            }
        } else {
            if (state == 0) { 
                if (d > lastDigit) {
                    res = (res + dg(pos + 1, d, 2, nextTight, false, s)) % MOD;
                } else if (d < lastDigit) {
                    res = (res + dg(pos + 1, d, 1, nextTight, false, s)) % MOD;
                }
            } else if (state == 1) { 
                if (d > lastDigit) {
                    res = (res + dg(pos + 1, d, 2, nextTight, false, s)) % MOD;
                }
            } else if (state == 2) { 
                if (d < lastDigit) {
                    res = (res + dg(pos + 1, d, 1, nextTight, false, s)) % MOD;
                }
            }
        }
    }
    return dp[pos][lastDigit][state][tight][isLeadingZero] = res;
}

ll calc(string s) {
    memset(dp, -1, sizeof(dp));
    return dg(0, 0, 0, true, true, s);
}

bool isGirl(const string &s) {
    int n = s.size();
    if (n <= 1) return (n == 1 && s[0] != '0');
    int state = 0;
    for (int i = 1; i < n; i++) {
        int d1 = s[i-1] - '0', d2 = s[i] - '0';
        if (d1 == d2) return false;
        if (state == 0) state = (d2 > d1) ? 2 : 1;
        else if (state == 1) { if (d2 <= d1) return false; state = 2; }
        else if (state == 2) { if (d2 >= d1) return false; state = 1; }
    }
    return true;
}

void solve() {
    int lenA, lenB;
    string A, B;
    cin >> lenA >> lenB >> A >> B;
    
    ll ansB = calc(B);
    ll ansA = calc(A);
    
    ll final_res = (ansB - ansA + MOD) % MOD;
    
    if (isGirl(A)) {
        final_res = (final_res + 1) % MOD;
    }
    
    cout << final_res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}