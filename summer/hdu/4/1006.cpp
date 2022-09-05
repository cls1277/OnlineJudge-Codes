#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

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
    double real = 0;
    double expect = 0;
    for (int i = 0; i < n; i++) {
        double p = read();
        expect += p;
        if (real >= 200) {
            real += p * 0.5;
        } else if (real >= 100) {
            real += p * 0.8;
        } else {
            real += p;
        }
    }
    if (expect >= 225) {
        expect = 200 + (expect - 225) * 0.5;
    } else if (expect >= 100) {
        expect = 100 + (expect - 100) * 0.8;
    }
    printf("%.3lf %.3lf\n", expect, real);
}

signed main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    // cout << fixed << setprecision(3); // 设置输出三位小数
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}