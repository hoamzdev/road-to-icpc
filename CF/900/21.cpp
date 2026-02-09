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

class RideSharingSystem {
public:
    deque<int> dqRider;
    deque<int> dqDrive;

    RideSharingSystem() {
       //nothing 
    }
    
    void addRider(int riderId) {
        dqRider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        dqDrive.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(!dqDrive.empty() && !dqRider.empty()){
            int u = dqDrive.front();dqDrive.pop_front();
            int v = dqRider.front();dqRider.pop_front();
            return {u,v};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(dqRider.empty()) return;  

        for(auto it = dqRider.begin();it != dqRider.end();it ++){
            if(*it == riderId){
                dqRider.erase(it);
                break;
            }
        }
    }
};
//acc
void solve(){
    // RideSharingSystem* obj = new RideSharingSystem();
    // obj->addRider(riderId);
    // obj->addDriver(driverId);
    // vector<int> param_3 = obj->matchDriverWithRider();
    // obj->cancelRider(riderId);


    
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