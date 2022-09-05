/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 505
#define maxV 1005
int n, a[maxn][maxn], mat[maxV], f[maxn][maxn];

namespace KM {
  int h[maxV], pre[maxV], slack[maxV];
  bool vis[maxV];

  void go(int u) {
    vis[u] = true;
    int d = inf, v = 0;
    for (int i = n + 1; i <= n + n; i++) {
      if (!vis[i]) {
        if (chmin(slack[i], h[u] + h[i] - a[u][i - n]))
          pre[i] = u;
        if (chmin(d, slack[i]))
          v = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i])
        h[i] -= d;
    }
    for (int i = n + 1; i <= n + n; i++) {
      if (vis[i])
        h[i] += d;
      else
        slack[i] -= d;
    }
    if (!mat[v]) {
      for (int i = v; i; ) {
        mat[i] = pre[i];
        swap(mat[pre[i]], i);
      }
      return;
    }
    vis[v] = true;
    go(mat[v]);
  }

  int work() {
    fill(h + 1, h + n + 1, 1000000);
    for (int i = 1; i <= n; i++) {
      memset(vis, 0, sizeof(vis));
      memset(slack, 0x3f, sizeof(slack));
      go(i);
    }
    int ans = 0;
    for (int i = 1; i <= n + n; i++)
      ans += h[i];
    return ans;
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  // freopen("11.in", "r", stdin);
  // freopen("tmp.out", "w", stdout);
  scanf("%d", &n);assert(1<=n&&n<=501);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);assert(-1000000<=a[i][j]&&a[i][j]<=1000000);
      a[i][j] = 1000005 - a[i][j];
    }
  }
  int flg = 1000005 * n - KM::work();
  if (flg < 0) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    mat[i] -= n;
    for (int j = 1; j <= n; j++) {
      a[i][j] = 1000005 - a[i][j];
    }
  }
  
  vector<tuple<int, int, int>> ans;
  for (int i = 1; i < n; i++) {
    int x = a[i][mat[i]];
    if (x)
      ans.push_back(mt(n, mat[i], x));
    for (int j = 1; j <= n; j++) {
      a[n][j] += x;
      a[j][mat[i]] -= x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      f[i][j] = i == j ? 0 : a[i][mat[j]];
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        chmin(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[1][i])
      ans.push_back(mt(i, mat[i], f[1][i]));
  }

  printf("%d\n", int(ans.size()));
  for (auto i : ans) {
    printf("%d %d %d\n", get<0>(i), get<1>(i), get<2>(i));
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
