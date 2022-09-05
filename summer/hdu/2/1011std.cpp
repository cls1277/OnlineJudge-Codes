#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define int long long
const int N = 2e6 + 10, INF = 1e18;
int n, m, q, w[N];
struct Node
{
    int l, r;
    int ans1, ans2; // ++-- +-+-
    int a, b; // + -
    int c, d, e, f; // ++ +- -+ -- 
    int g, h, i, j; // +-- ++- +-+ -+-
    void init(int _l, int _r)
    {
        l = _l, r = _r;
        ans1 = ans2 = a = b = c = d = e = f = g = h = i = j = -INF;
    }
}tr[N << 2];

void pushup(Node &u, const Node& l, const Node& r)
{
    // 每个元素先继承左右儿子的最大值
    u.ans1 = max(l.ans1, r.ans1); 
    u.ans2 = max(l.ans2, r.ans2);
    u.a = max(l.a, r.a);
    u.b = max(l.b, r.b);
    u.c = max(l.c, r.c);
    u.d = max(l.d, r.d);
    u.e = max(l.e, r.e);
    u.f = max(l.f, r.f);
    u.g = max(l.g, r.g);
    u.h = max(l.h, r.h);
    u.i = max(l.i, r.i);
    u.j = max(l.j, r.j);
    
    // 先更新 ++-- +-+- 每个三种情况
    u.ans1 = max(u.ans1, l.a + r.g);
    u.ans1 = max(u.ans1, l.c + r.f);
    u.ans1 = max(u.ans1, l.h + r.b);
    u.ans2 = max(u.ans2, l.a + r.j);
    u.ans2 = max(u.ans2, l.d + r.d);
    u.ans2 = max(u.ans2, l.i + r.b);
    
    //一个个枚举，代码奇葩但是其实思路很简答。
    u.c = max(u.c, l.a + r.a);
    u.d = max(u.d, l.a + r.b);
    u.e = max(u.e, l.b + r.a);
    u.f = max(u.f, l.b + r.b);
    u.g = max(u.g, l.a + r.f);
    u.g = max(u.g, l.d + r.b);
    u.h = max(u.h, l.a + r.d);
    u.h = max(u.h, l.c + r.b);
    u.i = max(u.i, l.a + r.e);
    u.i = max(u.i, l.d + r.a);
    u.j = max(u.j, l.b + r.d);
    u.j = max(u.j, l.e + r.b);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    tr[u].init(l, r);
    if(l == r) tr[u].a = w[l] , tr[u].b = -w[l];
    else
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if(l <= tr[u].l && r >= tr[u].r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        if(l > mid) return query(u << 1 | 1, l, r);
        Node res;
        res.init(0, 0);
        pushup(res, query(u << 1, l, r), query(u << 1 | 1, l, r));
        return res;
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ ) cin >> w[i] , w[i] = w[i] * w[i];
    build(1, 1, n);
    
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        Node t = query(1, a, b);
        cout << max(t.ans1, t.ans2) << endl;
    }
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    cin >> T;
    while(T -- ) solve();
    return 0;
}