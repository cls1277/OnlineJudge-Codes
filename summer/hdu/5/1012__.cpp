#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int ddl[maxn];

namespace st {

struct Node {
    int left, right;
    int minidx, minval, ddl;
} rt[maxn << 2];


inline int tl(int x) { return x * 2; }
inline int tr(int x) { return x * 2 + 1; }

void push(int x)
{
    rt[x].minval = min(rt[tl(x)].minval, rt[tr(x)].minval);
    if (rt[x].minval == rt[tl(x)].minval) {
        rt[x].minidx = rt[tl(x)].minidx;
    } else {
        rt[x].minidx = rt[tr(x)].minidx;
    }
}

// 建树
void build(int x, int L, int R)
{
    rt[x].left = L;
    rt[x].right = R;
    if (L == R) {
        rt[x].minidx = L;
        rt[x].minval = 0;
        return;
    }
    int mid = L + R >> 1;
    build(tl(x), L, mid);
    build(tr(x), mid + 1, R);
    push(x);
}

// 查询区间最小值下标
int query()
{
    return rt[1].minidx;
}

// 修改某个数的值
void add(int x, int idx)
{
    if (rt[x].left == rt[x].right) {
        rt[x].minval++;
        return;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    if (idx <= mid)
        add(tl(x), idx);
    else
        add(tr(x), idx);
    push(x);
}

void sub(int x, int idx)
{
    if (rt[x].left == rt[x].right) {
        rt[x].minval--;
        return;
    }
    int mid = rt[x].left + rt[x].right >> 1;
    if (idx <= mid)
        sub(tl(x), idx);
    else
        sub(tr(x), idx);
    push(x);
}

}

struct Node {
    int kind; // 1 是需要去排队，0是需要出队
    int time; // 事件发生的时间
    int arg; // 参数，如果是kind是1，代表持续时间，否则，代表出队下标
    Node(int k, int t, int a): kind(k), time(t), arg(a) {}
    // 对最大堆，小的在后面
    friend bool operator< (const Node& n1, const Node& n2) {
        if (n1.time == n2.time) {
            return n1.kind > n2.kind;
        }
        return n1.time > n2.time;
    }
};

void solve()
{
    priority_queue<Node> q;
    int n, m;
    cin >> n >> m;
    st::build(1, 1, m);
    memset(ddl, 0, sizeof ddl);
    for (int i = 0; i < n; i++) {
        int t, a;
        cin >> t >> a;
        q.emplace(1, t, a);
    }
    int ans = 0;
    while (!q.empty()) {
        if (q.top().kind == 1) { // 排队
            int idx = st::query();
            ddl[idx] = max(q.top().time + q.top().arg, ddl[idx]+q.top().arg);
            st::add(1, idx);
            q.pop();
            q.emplace(0, ddl[idx], idx);
            
        } else { // 出队
            ans = q.top().time;
            int idx = q.top().arg;
            st::sub(1, idx);
            q.pop();
        }
    }
    cout << ans << endl;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}