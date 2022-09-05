#include <algorithm>
#include <iostream>
using namespace std;
// const int maxn = 5e3+3;
// int dp[maxn];

void solve(int C)
{
    int ans = C;
    for (int a = 1; a * 2 < C; a++) {
        for (int b = (C - a) / 2; (a + b) * 2 > C; b--) {
            int c = C - a - b;
            if (a > b) {
                break;
            }
            if (a + b <= c || a + c <= b || b + c <= a) {
                continue;
            }
            if (a * a + b * b == c * c) {
                ans = min(ans, c - a);
                // cout << ans << endl;
            }
        }
    }
    if (ans == C) {
        if (C % 4 == 0) {
            ans = 0;
        } else if (C % 2 == 0) {
            ans = 1;
        }
    }
    cout << (ans == C ? -1 : ans) << endl;
    // dp[C] = ans == C ? -1 : ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int C;
    cin >> C;
    solve(C);
    // for (int C = 3; C <= 5000; C++) {
    //     solve(C);
    //     if ((C&1) && dp[C] != -1)
    //     cout << dp[C] << " ";
    // }
    return 0;
}
