#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 1000001

ll p[maxn + 5];
int spf[maxn + 5];

void sieve_spf(){
    for(int i = 1; i < maxn; i++) spf[i] = i;

    for(int i = 2; i * i < maxn; i++){
        ll val = i * i;
        for(int j = val; j < maxn; j += val){
            while(spf[j] % val == 0){
                spf[j] /= val;
            }
        }
    }
}


int main(){
    sieve_spf();
    ll n;
    cin >> n;

    map<ll,ll> mp;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        mp[spf[x]]++;
    }

    ll res = 0;
    for(auto [k, cnt] : mp){
        res += cnt * (cnt - 1) / 2;
    }
    cout << res;
}
