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
    friend bool operator<(const Node& n1, const Node& n2) {
        return n1.a < n2.a;
    }
    friend bool operator<(const Node& n1, int p) {
        return n1.a < p;
    }
    friend bool operator<(int p, const Node& n1) {
        return p < n1.a;
    }
    friend bool operator==(const Node& n1, int p) {
        return n1.a == p;
    }
} node[maxn];


struct Pair {
    int first, second;
    Pair(int first = 0, int second = 0) : first(first), second(second) {}
    friend bool operator< (const Pair& p1, const Pair& p2) {
        return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
    }
};

void solve()
{
    priority_queue<Pair > q;
    map<int, int> mp;
    int n;
    cin >> n;
    cout<<n<<endl;
    for (int i = 1; i <= n; i++) {
        mp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        node[i].i = i + 1;
        node[i].p = 0;
        cin >> node[i].a;
        cout<<node[i].a<<' ';
        mp[node[i].a]++;
    }
    cout<<endl;
    for (int i = 1; i <= n; i++) {
        q.emplace(mp[i], i);
    }
    sort(node, node + n);

    while (!q.empty()) {
        int p = q.top().second;
        auto it = upper_bound(node, node+n, p);
        while (it != node+n) {
            if (it->p == 0) {
                it->p = p;
                break;
            }
        }
        if (it != node+n) {
            q.pop();
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (node[i].p == 0) {
            if (q.top().second == node[i].a) {
                // cout << q.top().second;
                cout << "NO" << endl;
                return;
            }
            node[i].p = q.top().second;
            q.pop();
        }
    }

    // cout << "YES" << endl;
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
    // #ifdef DEBUG
    freopen("data.txt","r",stdin);
    // #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}