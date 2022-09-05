#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

struct ITV {
    int l, r;

    ITV(int l = 0, int r = 0) : l(l), r(r) {}

    friend bool operator<(const ITV& i1, const ITV& i2) { return i1.r > i2.r; }
} arr[maxn];

priority_queue<ITV> q;

void solve() {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    sort(arr, arr + k, [](const ITV& i1, const ITV& i2) {
        if (i1.l == i2.l) {
            return i1.r < i2.r;
        }
        return i1.l < i2.l;
    });

    int ans = 0;

    for (int i = 0; i < k; i++) {
        // cout << arr[i].l << " " << arr[i].r << endl;
        if (!q.empty() && q.top().r < arr[i].l) {
            while (q.size() >= n && q.top().r < arr[i].l) { 
                // cout << "开始第" << ans + 1 << "次取快递.." << endl;
                for (int t = 0; t < n; t++) {
                    // cout << q.top().l << " " << q.top().r << endl;
                    q.pop();
                }
                // cout << endl;
                // cout << endl;
                ans++;
            }
            if (!q.empty() && q.top().r < arr[i].l) {
                // cout << "开始第" << ans + 1 << "次取快递.." << endl;
                while (!q.empty()) {
                    // cout << q.top().l << " " << q.top().r << endl;
                    q.pop();
                }
                // cout << "这次没取满呜呜呜" << endl;
                // cout << endl;
                // cout << endl;
                ans++;
            }
        }

        q.emplace(arr[i]);
    }
    while (q.size() >= n) {
        // cout << "开始第" << ans + 1 << "次取快递.." << endl;
        for (int i = 0; i < n; i++) {
            // cout << q.top().l << " " << q.top().r << endl;
            q.pop();
        }
        // cout << endl;
        // cout << endl;
        ans++;
    }
    if (!q.empty()) {
        // cout << "开始第" << ans + 1 << "次取快递.." << endl;
        while (!q.empty()) {
            // cout << q.top().l << " " << q.top().r << endl;
            q.pop();
        }
        // cout << "这次没取满呜呜呜" << endl;
        // cout << endl;
        // cout << endl;
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}