#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
// #define int ll
// #define db ld

using tii = tuple<int, int>; using ti3 = tuple<int, int, int>; using ti4 = tuple<int, int, int, int>;
#define mt(...) make_tuple(__VA_ARGS__)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)
#define W(x) get<3>(x)

using vi = vector<int>; using vii = vector<tii>; using vi3 = vector<ti3>; using vi4 = vector<ti4>;
using vvi = vector<vi>; using vvii = vector<vii>; using vvi3 = vector<vi3>; using vvi4 = vector<vi4>;
#define pf(...) emplace_front(__VA_ARGS__)
#define pb(...) emplace_back(__VA_ARGS__)

#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)
#define y0 kehaixing
#define y1 yigeiwoligiaogiao
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
int lowbit(int x) { return x & -x; }
template<class T, class U> void chkmx(T &x, U y) { if(y > x) x = y; }
template<class T, class U> void chkmn(T &x, U y) { if(y < x) x = y; }

// FASTIO
namespace fastio {
// #define fread_io
#ifdef fread_io
char buf[1 << 16], *st, *ed, wbuf[1 << 16], *wst = wbuf, *wed = wbuf + (1 << 16);
char gc() { return st == ed && (ed = (st = buf) + fread(buf, 1, 1 << 16, stdin), st == ed) ? -1 : *st++; }
__attribute__((destructor)) void flush() { fwrite(wbuf, 1, wst - wbuf, stdout), wst = wbuf; }
void pc(char x) { wst == wed && (flush(), 0), *wst++ = x; }
#else
char gc() { return getchar(); } void pc(char x) { putchar(x); }
#endif
#define notspace(x) (!isspace(x) && ~(x))
template<class T = int> T read() {
  T x = 0; char c = gc(); bool ne = false;
  while(!isdigit(c)) ne |= c == '-', c = gc();
  while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
  return ne ? -x : x;
}
int reads(char *s) {
  int n = 0; char c = gc();
  while(!notspace(c)) c = gc();
  while(notspace(c)) s[n++] = c, c = gc();
  return s[n] = 0, n;
}
template<class T> void prt(T x) {
  x < 0 && (pc('-'), x = -x);
  x > 9 && (prt(x / 10), 0);
  pc(x % 10 ^ 48);
}
void prts(const char *s, int n = INT_MAX) { while(n-- && *s) pc(*s++); }
} using fastio::gc; using fastio::pc;
using fastio::read; using fastio::reads; using fastio::prt; using fastio::prts;

// MATH
constexpr int P = 998244353;
constexpr ll lnf = 0x3f3f3f3f3f3f3f3f;
#ifdef int
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#else
constexpr int inf = 0x3f3f3f3f;
#endif

int gcd(int x, int y) { return __gcd(x, y); }
int exgcd(int a, int b, int &x, int &y) {
  if(!b) return x = 1, y = 0, a;
  int d = exgcd(b, a % b, y, x);
  return y -= a / b * x, d;
}
int qpow(int x, int y = P - 2, int p = P) {
  int res = 1;
  while(y) {
    if(y & 1) res = (ll)res * x % p;
    x = (ll)x * x % p;
    y >>= 1;
  } return res;
}
int inv(int a, int p = P) {
  int x, y, d = exgcd(a, p, x, y);
  if(d != 1) return -1;
  return x < 0 ? x + p : x;
}

namespace modint {
  void addto(int &x, int y) { x += y, x >= P && (x -= P), x < 0 && (x += P); }
  int add(int x, int y) { return x < 0 && (x += P), x += y, x >= P ? x - P : x < 0 ? x + P : x; }
  int add0(int x) { return x < 0 ? x + P : x; }
}
using namespace modint;

template<int N, int p = P> struct fc_t {
  int iv[N], fc[N], ifc[N];
  fc_t() {
    iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[p % i] * (p - p / i) % p;
    fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % p, ifc[i] = (ll)ifc[i - 1] * iv[i] % p;
  }
  int operator()(int n, int m) {
    if(m < 0 || m > n) return 0;
    return (ll)fc[n] * ifc[m] % p * ifc[n - m] % p;
  }
};
#define fc_init(...) fc_t<__VA_ARGS__> comb; int *iv = comb.iv, *fc = comb.fc, *ifc = comb.ifc
template<int N, int p = P> struct comb_t {
  int comb[N][N];
  comb_t() {
    comb[0][0] = 1;
    REP(i, 1, N - 1) REP(j, 0, i) comb[i][j] = ((j ? comb[i - 1][j - 1] : 0) + comb[i - 1][j]) % p;
  }
};
#define comb_init(...) comb_t<__VA_ARGS__> _comb; auto comb = _comb.comb
} using namespace temp;

constexpr int N = 60;

int n = 49;
vi u, v;

namespace prufer {
int fa[N],prf[N];
int deg[N],hav[N];
void fa_init(){
  int n = 24;
  REP(i, 1, n) deg[i] = hav[i] = fa[i] = 0;
	for(int i=1;i<=n-2;i++)deg[prf[i]]++;
	for(int i=1;i<=n;i++)if(!deg[i])hav[i]++;
	int now=1,least=0,d;
	for(int i=1;i<=n-2;i++){
		if(least)d=least,least=0;
		else{while(!hav[now])now++;d=now;hav[now]--;}
		fa[d]=prf[i];
		if(!--deg[fa[d]])if(fa[d]<now)least=fa[d];else hav[fa[d]]++;
	}
	for(int i=1;i<n;i++)if(!fa[i])fa[i]=n;
}
}

vi nei[N];
int dfn[N], nowdfn, mxdfn[N], mng[N];
void dfs(int x = 24) {
  mng[dfn[x] = mxdfn[x] = ++nowdfn] = x;
  for(int y : nei[x]) {
    dfs(y);
    mxdfn[x] = mxdfn[y];
  }
}

int xpw[N], ypw[N], zpw[N];

struct tree {
  short fa[N];
  short ca[25][25];
  void init(int *_fa) {
    int n = 24;
    REP(i, 1, n) fa[i] = prufer::fa[i];
    // REP(i, 1, n) cout << fa[i] << " \n"[i == n];
    nowdfn = 0;
    REP(i, 1, n) nei[i].clear();
    REP(i, 1, n - 1) nei[fa[i]].pb(i);
    dfs(n);
    // REP(i, 1, n) cout << dfn[i] << " \n"[i == n];
    REP(x, 1, n) {
      REP(i, dfn[x], mxdfn[x]) ca[x][mng[i]] = ca[mng[i]][x] = x;
      for(int y : nei[x]) for(int z : nei[x]) if(y < z) {
        REP(i, dfn[y], mxdfn[y]) REP(j, dfn[z], mxdfn[z]) ca[mng[i]][mng[j]] = ca[mng[j]][mng[i]] = x;
      }
    }
  }
  int get(vi &v) {
    int ans = 0;
    REP(i, 1, 24) REP(j, i + 1, 24) {
      addto(ans, (ll)xpw[v[i - 1]] * ypw[v[j - 1]] % P * zpw[v[ca[i][j] - 1]] % P);
    }
    return ans;
  }
} t[100010];

// mt19937 rng(19171107);
// mt19937 rng(114514);
mt19937 rng(998244353);
int rnd(int l, int r) { return uniform_int_distribution<>(l, r)(rng); }

void init() {
  for(int i = 2; i <= n; i += 2) u.pb(i);
  for(int i = 3; i <= n; i += 2) v.pb(i);
  // REP(i, 2, 25) u.pb(i);
  // REP(i, 26, 49) v.pb(i);
  REP(i, 1, 100000) {
    REP(j, 1, 22) prufer::prf[j] = rnd(1, 24);
    prufer::fa_init();
    t[i].init(prufer::fa);
  }
}

void mian() {
  int aim = read(), X = read(), Y = read(), Z = read();
    assert(2<=X&&X<=998244351);
    assert(2<=Y&&Y<=998244351);
    assert(2<=Z&&Z<=998244351);
  xpw[0] = ypw[0] = zpw[0] = 1;
  REP(i, 1, n) {
    xpw[i] = (ll)xpw[i - 1] * X % P;
    ypw[i] = (ll)ypw[i - 1] * Y % P;
    zpw[i] = (ll)zpw[i - 1] * Z % P;
  }
  int ext = 0;
  for(int x : u) for(int y : v) if(x < y) addto(ext, (ll)xpw[x] * ypw[y] % P * Z % P);
  for(int x : v) for(int y : u) if(x < y) addto(ext, (ll)xpw[x] * ypw[y] % P * Z % P);
  for(int x : u) addto(ext, (ll)X * ypw[x] % P * Z % P);
  for(int x : v) addto(ext, (ll)X * ypw[x] % P * Z % P);
  unordered_map<int, int> mp;
  REP(i, 1, 100000) {
    mp[t[i].get(u)] = i;
    int val = t[i].get(v);
    int shd = add(aim, -add(val, ext));
    if(mp.find(shd) != mp.end()) {
      int j = mp[shd];
      puts("49");
      prt(1), pc(' '), prt(u.back()), pc('\n');
      prt(1), pc(' '), prt(v.back()), pc('\n');
      REP(x, 1, 23) prt(u[x - 1]), pc(' '), prt(u[t[j].fa[x] - 1]), pc('\n');
      REP(x, 1, 23) prt(v[x - 1]), pc(' '), prt(v[t[i].fa[x] - 1]), pc('\n');
      break;
    }
  }
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  // freopen("1.ans", "w", stdout);
  // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
  init();
  int t = 1;
  t = read();assert(t<=20);
  while(t--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}

