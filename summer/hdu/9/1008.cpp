#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int maxn = 1e7 + 7;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool vis[maxn];
int pri[maxn / 9];

// 线性筛
void init() {
  pri[0] = 0;
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) {
      pri[++pri[0]] = i;
    }
    for (int j = 1; j <= pri[0]; ++j) {
      if (1ll * i * pri[j] >= maxn)
        break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        // i % pri[j] == 0
        // 换言之，i 之前被 pri[j] 筛过了
        // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定也是
        // pri[j] 的倍数 它们都被筛过了，就不需要再筛了，所以这里直接 break
        // 掉就好了
        break;
      }
    }
  }
}

int fa[10]; // 质因数
int b[50000];

int solve(int num, int n) {
  fa[0] = 0;
  for (int i = 1; pri[i] * pri[i] <= num; i++) {
    if (num % pri[i] == 0) {
      while (num % pri[i] == 0) {
        num /= pri[i];
      }
      fa[++fa[0]] = pri[i];
    }
  }
  if (num > 1)
    fa[++fa[0]] = num;
  int g = 0, sum = n, t;
  b[++g] = 1;
  for (int i = 1; i <= fa[0]; i++) {
    t = g;
    for (int j = 1; j <= g; j++) {
      b[++t] = b[j] * fa[i] * -1;
      sum += n / b[t];
    }
    g = t;
  }
  return sum;
}

signed main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
  init();
  cin.tie(nullptr)->sync_with_stdio(false);
//   cout << solve(8, 3) << endl;
  int n, q;
  cin >> n >> q;
  for (int t = 0; t < q; t++) {
    int u, v;
    cin >> u >> v;
    int g = gcd(u, v);
    if (g == 1) {
      cout << "1 1" << endl;
    } else if (g == 2) {
      // +1 u->v
      // cout << "2 2" << endl;
      cout << "2 " << solve(u * v / g, n) + 1 << endl;
    } else {
      cout << "2 " << solve(u * v / g, n) << endl;
    }
  }
  return 0;
}
