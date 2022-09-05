#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5 + 5;

struct Node {
    int i, a, p;
    Node() = default;
    Node(int i, int a, int p)
        : i(i)
        , a(a)
        , p(p)
    {
    }
} node[maxn];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        node[i].i = i + 1;
        node[i].p = 0;
        cin >> node[i].a;
    }
    sort(node, node + n, [](const Node& n1, const Node& n2) {
        return n1.a < n2.a;
    });

    int l = 0, r, mid, idx = 0;
    for (int p = 1; p <= n; p++) {
        if (l >= n) {
            while (node[idx].p) {
                idx++;
            }
            node[idx].p = p;
        } else {
            r = n - 1;
            while (l + 1 <= r) {
                mid = (l + r) / 2;
                if (node[mid].a <= p) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            // cout << "FIND " << l << " IS " << p << endl;
            if (node[l].a > p) {
                node[l].p = p;
                l++;
            } else {
                l++;
                p--;
            }
            // for (int i = l; i < n; i++) {
            //     if (node[i].a > p && !node[i].p) {
            //         node[i].p = p;
            //         l++;
            //         break;
            //     }
            // }
        }
    }
    cout << "YES" << endl;
    sort(node, node + n, [](const Node& n1, const Node& n2) {
        return n1.i < n2.i;
    });
    for (int i = 0; i < n; i++) {
        cout << node[i].p << ' ';
    }
    cout << endl;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}