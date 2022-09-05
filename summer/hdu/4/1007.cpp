#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int a[maxn];

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

void solve() {
    int n = read();
    a[0] = read();
    int k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    a[n + 1] = 0;       // 终点
    int idx = 0;        // 当前楼层下标
    int tk = k;         // 暂时的k
    while (idx <= n) {
        cout << "我刚打爆了前" << idx << "层，我现在有" << a[idx] << "攻击，我能向上跳" << tk << "层" << endl;
        int rest = 0;      // 还需要多少atk
        int acc = a[idx];  // 累计值
        bool flag = false;  // 能继续走下去吗？
        for (int i = idx + 1; i <= idx + tk; i++) {
            rest = max(a[i] - a[idx], rest - a[i]);
            acc += a[i];
            cout << "我现在在计算第" << i << "层，我有" << a[idx] << "攻击，我还需要" << rest << "攻击。" << endl;
            if (rest <= 0) {  // 开打
                a[i] = acc;
                tk = min(k - (i - idx - 1), n-i+1);
                idx = i;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}
