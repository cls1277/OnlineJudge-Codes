#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int inf1 = 2147483647;
const ll INF = 1e18;
#define CLOSE ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int maxn = 1e5 + 5;
struct edge {
    int v, next;
} e[maxn * 2];
int tot = 0, head[maxn];
void addedge(int u, int v) {
    e[++tot].v = v;
    e[tot].next = head[u];
    head[u] = tot;
}

vector<int> fa;
int sz[maxn], dp2[maxn], dp5[maxn], ans2[maxn], ans5[maxn];

void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int fa) {
    int temp = u;
    int temp2 = 0, temp5 = 0;
    while (temp) {
        if (temp % 2 == 0) {
            temp /= 2;
            temp2++;
        } else
            break;
    }
    // temp=u;
    while (temp) {
        if (temp % 5 == 0) {
            temp /= 5;
            temp5++;
        } else
            break;
    }
    dp2[u] = temp2;
    dp5[u] = temp5;
    ans2[u] = ans2[fa] + (dp2[u] -dp2[fa]) * sz[u];
    ans5[u] = ans5[fa] + (dp5[u] - dp5[fa]) * sz[u];
    
    // dp2[u] += sz[u] * temp2;
    // dp5[u] += sz[u] * temp5;
    // ans[u] = min(dp2[fa] + temp2 * sz[u], dp5[fa] + temp5 * sz[u]);
    // cout<<u<<' '<<temp2<<' '<<temp5<<endl;
    
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
    }
}

int main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    CLOSE;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    dfs1(1, 0);
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << min(ans2[x], ans5[x]) << endl;
    }
    return 0;
}
