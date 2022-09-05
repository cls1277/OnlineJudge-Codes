#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
int c[maxn];
bool vis[maxn];

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    fill(c, c + maxn, 0);
    fill(vis, vis + maxn, false);
    int n;
    cin >> n;
    // if (n == 1) {
    //     cout << 1 << endl
    //          << 1 << endl;
    //     return 0;
    // }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        q.emplace(t, i);
    }
    while (!q.empty() && q.top().first <= 2 * n) {
        if (q.top().first < n) {
            {
                int i = 2 * n - 1;
                while (vis[i]) {
                    i--;
                }
                vis[i] = true;
                c[i] = q.top().second;
            }
            for (int i = q.top().first / 2; i < 2 * n; i += q.top().first) {
                while (vis[i]) {
                    i--;
                }
                c[i] = q.top().second;
                vis[i] = true;
            }
        } else {
            for (int i = n - 1; i < 2 * n; i += n) {
                while (vis[i]) {
                    i--;
                }
                c[i] = q.top().second;
                vis[i] = true;
            }
        }
        q.pop();
    }
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i]) {
            if (!q.empty()) {
                c[i] = q.top().second;
                q.pop();
            } else {
                c[i] = c[2*n-1];
            }
        }
    }
    cout << 2 * n << endl;
    for (int i = 0; i < 2 * n; i++) {
        cout << c[i] << ' ';
    }
    return 0;
}
