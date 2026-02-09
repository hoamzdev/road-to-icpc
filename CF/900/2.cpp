#include<bits/stdc++.h>
using namespace std;

#define el '\n'
typedef long long ll;

// dp[vị trí][tight][chữ số trước][độ dài đoạn]
// Lưu pair {Tổng_Giá_Trị, Số_Lượng_Số}
pair<ll, ll> dp[20][2][11][20];

pair<ll, ll> sol(string& s, int curr = 0, bool tight = true, int pre = 10, int len = 0) {
    // BƯỚC 1: ĐIỂM DỪNG (Khi đã viết xong 1 số)
    if (curr == (int)s.size()) {
        // Một số luôn kết thúc bằng một đoạn cuối cùng (ví dụ số 22233 thì đoạn cuối là 33)
        // Đoạn cuối này chưa được tính ở vòng lặp phía dưới, nên ta tính nốt ở đây.
        // Trả về: {Giá trị đoạn cuối, Đếm là 1 số}
        ll gia_tri_doan_cuoi = (ll)pre * len * len;
        return { gia_tri_doan_cuoi, 1 };
    }

    // BƯỚC 2: KIỂM TRA BỘ NHỚ (MEMOIZATION)
    if (dp[curr][tight][pre][len].first != -1) {
        return dp[curr][tight][pre][len];
    }

    pair<ll, ll> ans = {0, 0};
    int limit = tight ? (s[curr] - '0') : 9;

    // BƯỚC 3: DUYỆT CÁC CHỮ SỐ CÓ THỂ CHỌN
    for (int i = 0; i <= limit; i++) {
        bool next_tight = tight && (i == limit);
        pair<ll, ll> hh;

        if (i == pre) {
            // TRƯỜNG HỢP 1: Chữ số mới GIỐNG chữ số trước (ví dụ đang là 22, chọn thêm 2 thành 222)
            // Ta chưa chốt giá trị, chỉ tăng độ dài (len + 1) và đi tiếp về phía trước.
            hh = sol(s, curr + 1, next_tight, i, len + 1);
            
            // Vì đoạn này chưa kết thúc, giá trị của nó sẽ được tính ở các bước sau hoặc ở điểm dừng.
            // Ta chỉ việc mang tổng giá trị từ tương lai về.
            ans.first += hh.first;
            ans.second += hh.second;
        } 
        else {
            // TRƯỜNG HỢP 2: Chữ số mới KHÁC chữ số trước (ví dụ đang là 222, chọn thêm 3 thành 2223)
            // ĐÂY LÀ LÚC CHỐT SỔ ĐOẠN CŨ (222)
            hh = sol(s, curr + 1, next_tight, i, 1); // Đoạn mới bắt đầu bằng chữ số i với len = 1
            
            // Logic nhân phân phối:
            // Giả sử phía sau có hh.second = 5 con số hợp lệ.
            // Cụm "222" này sẽ xuất hiện trong cả 5 số đó.
            // Nên tổng đóng góp của cụm "222" này là: (Giá trị cụm) * (Số lượng số phía sau)
            ll gia_tri_cum_cu = (ll)pre * len * len;
            ll tong_dong_gop = gia_tri_cum_cu * hh.second;
            
            // Tổng mới = (Tổng các đoạn phía sau) + (Tổng đóng góp của cụm vừa chốt)
            ans.first += (hh.first + tong_dong_gop);
            ans.second += hh.second;
        }
    }

    return dp[curr][tight][pre][len] = ans;
}


ll calc(ll x){
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return sol(s).first;
}

void solve() {
    ll a, b; 
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;
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