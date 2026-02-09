#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	string s;
	cin >> s;
	int y = 0;int v = 0;int c = 0;int n = 0;int g = 0;

    for (int i = 0; i < (int)s.size(); i++){
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') v++;
		else if (s[i] == 'Y') y++;
		else {
			c++;
			if (s[i] == 'N') n++;
			if (s[i] == 'G') g++;
		}
	}
    //hieu
	int ans = 0;
	
	// c tv c
    for (int j = 0; j <= v; j++){
        for (int  i = 0; i <= y; i++){
			int tv = j + i;
			if (c + (y - i) >= 2 * tv){
				ans = max(ans, tv * 3 + min({n,g,c + (y - i) - 2 * tv ,2*tv}));
			}
		}
	}
	
	cout << ans << endl;
}


signed main(){
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