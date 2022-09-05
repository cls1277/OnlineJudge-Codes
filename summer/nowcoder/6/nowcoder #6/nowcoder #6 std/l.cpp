#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Mbe;
constexpr int MAXS = 1e6 + 5;
constexpr int MAXT = 5e5 + 5;
constexpr int MAXK = 1e6 + 5;
constexpr int MAXQ = 1e6 + 5;
constexpr int MAXH = MAXS + MAXT;
constexpr int NODE = MAXT * 23;
char s[MAXS], t[MAXT], h[MAXH];
int S, T, H, K, Q;
int anc[23][MAXT], nxt[MAXT], R1[MAXT], R2[MAXT];
int p[MAXS], pref[MAXS];
int qcnt, l[MAXK], r[MAXK];
pair<ll, int> q[MAXQ << 1];
ll ans[MAXQ];
struct Linklist {
  int cnt, hd[MAXT], nxt[MAXT], to[MAXT];
  void add(int u, int v) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;}
} e;
struct PersistentSegtree1 {
  int node, ls[NODE], rs[NODE], val[NODE];
  void modify(int pre, int &x, int l, int r, int p, int v) {
    val[x = ++node] = max(v, val[pre]);
    ls[x] = ls[pre], rs[x] = rs[pre];
    if(l == r) return;
    int m = l + r >> 1;
    if(p <= m) modify(ls[pre], ls[x], l, m, p, v);
    else modify(rs[pre], rs[x], m + 1, r, p, v);
  }
  int query(int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr || !x) return val[x];
    int m = l + r >> 1, ans = 0;
    if(ql <= m) ans = query(l, m, ql, qr, ls[x]);
    if(m < qr) ans = max(ans, query(m + 1, r, ql, qr, rs[x]));
    return ans;
  }
} tr1;
struct PersistentSegtree2 {
  int node, ls[NODE << 1], rs[NODE << 1], val[NODE << 1];
  void modify(int pre, int &x, int l, int r, int ql, int qr, int v) {
    val[x = ++node] = val[pre];
    ls[x] = ls[pre], rs[x] = rs[pre];
    if(ql <= l && r <= qr) return val[x]++, void();
    int m = l + r >> 1;
    if(ql <= m) modify(ls[pre], ls[x], l, m, ql, qr, v);
    if(m < qr) modify(rs[pre], rs[x], m + 1, r, ql, qr, v);
  }
  int query(int l, int r, int p, int x, int y) {
    int ans = val[x] - val[y];
    if(l == r) return ans;
    int m = l + r >> 1;
    if(p <= m) return ans + query(l, m, p, ls[x], ls[y]);
    return ans + query(m + 1, r, p, rs[x], rs[y]);
  }
} tr2;
struct SA {
  int lg[MAXH], ht[MAXH], mi[22][MAXH];
  int sa[MAXH], rk[MAXH], ork[MAXH], buc[MAXH], id[MAXH];
  bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
  void build() {
    for(int i = 1; i <= S; i++) h[++H] = s[i];
    h[++H] = '!';
    for(int i = 1; i <= T; i++) h[++H] = t[i];
    int m = 1 << 7, p = 0;
    for(int i = 1; i <= H; i++) buc[rk[i] = h[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = H; i; i--) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; w <<= 1, m = p, p = 0) {
      for(int i = H - w + 1; i <= H; i++) id[++p] = i;
      for(int i = 1; i <= H; i++) if(sa[i] > w) id[++p] = sa[i] - w;
      memset(buc, 0, sizeof(buc));
      memcpy(ork, rk, sizeof(rk));
      p = 0;
      for(int i = 1; i <= H; i++) buc[rk[i]]++;
      for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
      for(int i = H; i; i--) sa[buc[rk[id[i]]]--] = id[i];
      for(int i = 1; i <= H; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
      if(p == H) break;
    }
    for(int i = 1, k = 0; i <= H; i++) {
      if(k) k--;
      while(h[i + k] == h[sa[rk[i] - 1] + k]) k++;
      mi[0][rk[i]] = ht[rk[i]] = k;
    }
    for(int i = 2; i <= H; i++) lg[i] = lg[i >> 1] + 1;
    for(int i = 1; i <= lg[H]; i++)
      for(int j = 1; j + (1 << i) - 1 <= H; j++)
        mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  }
  int lcp(int i, int j) {
    if(i > j) swap(i, j);
    int d = lg[j - i++];
    return min(mi[d][i], mi[d][j - (1 << d) + 1]);
  }
  pair<int, int> query(int p, int lim) {
    int l = 1, r = p, ansl = -1;
    while(l < r) {
      int m = l + r >> 1;
      if(lcp(m, p) >= lim) r = m;
      else l = m + 1;
    }
    ansl = l, l = p, r = H;
    while(l < r) {
      int m = l + r + 2 >> 1;
      if(lcp(p, m) >= lim) l = m;
      else r = m - 1;
    }
    return make_pair(ansl, l);
  }
} sa;
void input() {
  cin >> s + 1 >> t + 1 >> K >> Q;
  S = strlen(s + 1), T = strlen(t + 1);
  for(int i = 1; i <= K; i++) cin >> l[i] >> r[i];
  for(int i = 1; i <= Q; i++) {
    ll l, r;
    cin >> l >> r;
    if(r - l + 1 < T) continue;
    q[++qcnt] = {r, i}, q[++qcnt] = {l + T - 2, -i};
  }
  sort(q + 1, q + qcnt + 1);
}
void getnext() {
  for(int i = 2, j = 0; i <= T; i++) {
    while(j && t[j + 1] != t[i]) j = nxt[j];
    nxt[i] = j += t[j + 1] == t[i];
  }
  for(int i = 1, j = 0; i <= S; i++) {
    while(j && t[j + 1] != s[i]) j = nxt[j];
    j += t[j + 1] == s[i];
    if(j == T) pref[i] = 1, j = nxt[j];
    p[i] = j, pref[i] += pref[i - 1];
  }
}
void dfs(int id) {
  if(id == T) return;
  int rk = sa.rk[(S + 1) + (id + 1)];
  tr1.modify(R1[nxt[id]], R1[id], 1, H, rk, id);
  pair<int, int> range = sa.query(rk, T - id);
  tr2.modify(R2[nxt[id]], R2[id], 1, H, range.first, range.second, 1);
  for(int i = e.hd[id]; i; i = e.nxt[i]) dfs(e.to[i]);
}
void buildtree() {
  for(int i = 1; i <= T; i++) e.add(anc[0][i] = nxt[i], i);
  for(int i = 1; i < 23; i++)
    for(int j = 1; j <= T; j++)
      anc[i][j] = anc[i - 1][anc[i - 1][j]];
  dfs(0);
}
int query(int M, int l, int P) {
  if(M + P < T) return 0;
  int ans = 0;
  if(P >= T) ans = pref[l + P - 1] - pref[l + T - 2];
  int A = M;
  for(int i = 22; ~i; i--) if(anc[i][A] + P >= T) A = anc[i][A];;
  return ans + tr2.query(1, H, sa.rk[l], R2[M], R2[anc[0][A]]);
}
void process() {
  ll alr = 0, tot = 0;
  int M = 0;
  for(int i = 1, pt = 1; i <= K; i++) {
    int L = r[i] - l[i] + 1;
    while(pt <= qcnt && q[pt].first <= tot + L) {
      int qid = abs(q[pt].second);
      int coef = q[pt].second / qid;
      int ext = q[pt].first - tot;
      ll occ = alr + query(M, l[i], ext);
      ans[qid] += coef * occ;
      pt++;
    }
    alr += query(M, l[i], L);
    tot += L;
    pair<int, int> range = sa.query(sa.rk[l[i]], L);
    int _M = tr1.query(1, H, range.first, range.second, R1[M]);
    if(_M) M = _M + L;
    else {
      M = p[r[i]];
      for(int i = 22; ~i; i--) if(anc[i][M] > L) M = anc[i][M];
      if(M > L) M = anc[0][M];
    }
    if(M == T) M = nxt[M];
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf MB\n", (&Mbe - &Med) / 1048576.0);
  ios::sync_with_stdio(0);
  input();
  sa.build();
  getnext();
  buildtree();
  process();
  for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
  return cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n", 0;
}
/*
2022/7/20
Author: Alex_Wei
start coding at 14:04
finish debugging at 15:35
*/
