#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
dp[pos][sum][tight]
pos   : đang xét chữ số thứ pos
sum   : tổng chữ số đã chọn
tight : 1 = bị giới hạn bởi x, 0 = tự do
*/
ll dp[20][170][2];
bool isPrime[170];
string s;

// Sàng nguyên tố tới 162
void sieve() {
    for (int i = 0; i < 170; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 170; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < 170; j += i)
                isPrime[j] = false;
        }
    }
}

// Digit DP
ll dfs(int pos, int sum, int tight) {
    // Đã đi hết các chữ số → kiểm tra tổng chữ số
    if (pos == (int)s.size()) {
        return isPrime[sum];
    }

    // Trạng thái đã tính rồi
    if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];

    ll res = 0;

    // Nếu tight = 1 thì không được vượt quá chữ số của x
    int maxDigit = tight ? s[pos] - '0' : 9;

    for (int d = 0; d <= maxDigit; d++) {
        res += dfs(
            pos + 1,
            sum + d,
            tight && (d == maxDigit)
        );
    }

    return dp[pos][sum][tight] = res;
}

// calc(x) = số lượng số trong [0, x]
ll calc(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 1);
}

int main() {
    sieve();

    ll l, r;
    cin >> l >> r;

    cout << calc(r) - calc(l - 1);
}
