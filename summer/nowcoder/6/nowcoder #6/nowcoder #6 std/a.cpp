#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 1 << 18;
int n, a[N], b[N];
pair<int, int> p[N];
bool Med;
int main() {
  fprintf(stderr, "%.4lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], p[i] = make_pair(1 << 31 - __builtin_clz(a[i]), i);
  sort(p + 1, p + n + 1);
  int f = 0;
  for(int i = 1; i <= n; i++) {
    while(b[f]) f++;
    for(int P = f; P < N; P += p[i].first) b[P] = p[i].second;
  }
  cout << N << "\n";
  for(int i = 0; i < N; i++) cout << max(1, b[i]) << "\n";
  cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
  return 0;
}
/*
2022/8/1
start coding at
finish debugging at
*/
