#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod 1000000007
#define INF 1000000001
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define endl '\n'
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int n, k;
vll a;

bool check(ll g) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % g == 0) cnt++;
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll mx = *max_element(a.begin(), a.end());

    vll dd;
    for(long long d = 1; d * d <= mx; d++) {
        if(mx % d == 0) {
            dd.push_back(d);
            if(d != mx / d) dd.push_back(mx / d);
        }
    }
    sort(dd.rbegin(), dd.rend());

    for(ll g : dd) {
        if(check(g)) {
            cout << g;
            return 0;
        }
    }
    cout << 1;
}
