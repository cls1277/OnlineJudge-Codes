#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e5 + 5;
const int mod = 998244353;
int P[maxn];
int Q[maxn];
int S[maxn * 2];

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

int dfs(int pi, int qi, int n) {
    if (pi == n) {
        while (qi < n) {
            if (S[pi + qi] != Q[qi]) {
                return 0;
            }
            qi++;
        }
        return 1;
    }
    if (qi == n) {
        while (pi < n) {
            if (S[pi + qi] != P[pi]) {
                return 0;
            }
            pi++;
        }
        return 1;
    }
    int res = 0;
    if (S[pi + qi] == P[pi]) {
        res += dfs(pi + 1, qi, n);
    }
    if (S[pi + qi] == Q[qi]) {
        res += dfs(pi, qi + 1, n);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Q[i];
    }
    for (int i = 0; i < 2 * n; i++) {
        cin >> S[i];
    }
    cout << dfs(0, 0, n) << endl;
    // shuffle(P, P+n, mt19937(0));
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