#include <bits/stdc++.h>

using namespace std;

const int INF = 998244353;
const int inv2 = (INF + 1) / 2;
const int maxn = 18;

typedef unsigned long long u64;

inline int qpow(int x, int y){
	int ret = 1;
	for(; y; y >>= 1, x = 1ll * x * x % INF){
		if(y & 1) ret = 1ll * ret * x % INF;
	}
	return ret;
}

int n, m, ans;
int w[maxn][maxn], inv[maxn + 2];
int sume[1 << maxn], cnte[1 << maxn], G[maxn + 2][1 << maxn], pop[1 << maxn];

inline void FMT(int *vec){
	for(int step = 1; step < m; step <<= 1){
		for(int i = 0; i < m; i += step << 1){
			int *p1 = vec + i, *p2 = vec + i + step;
			for(int j = 0; j < step; ++j, ++p1, ++p2) (*p2 += *p1), *p2 -= (*p2 >= INF ? INF : 0);
		}
	}
}

inline void IFMT(int *vec){
	for(int step = 1; step < m; step <<= 1){
		for(int i = 0; i < m; i += step << 1){
			int *p1 = vec + i, *p2 = vec + i + step;
			for(int j = 0; j < step; ++j, ++p1, ++p2) (*p2 -= *p1), *p2 += (*p2 < 0 ? INF : 0);
		}
	}
}

inline void recalc(){
	memset(G, 0, sizeof(G));
	for(int S = 1; S < m; ++S) G[pop[S]][S] = cnte[S];
	for(int i = 0; i <= n; ++i) FMT(G[i]);
	static int tmp[maxn + 2], a[maxn + 2];
	for(int S = 1; S < m; ++S){
		for(int i = 0; i <= n; ++i) a[i] = G[i][S];
		for(int i = 0; i < n; ++i){
			int *p1 = tmp, *p2 = a + i;
			u64 res = 0;
			for(int j = 0; j < i; ++j, ++p1, --p2) res += 1ull * (*p1) * (*p2);
			tmp[i] = (1ll * a[i + 1] * (i + 1) + INF - res % INF) % INF;
		}
		for(int i = 1; i <= n; ++i) G[i][S] = 1ll * tmp[i - 1] * inv[i] % INF;
	}
	for(int i = 0; i <= n; ++i) IFMT(G[i]);
	return;
}

int main(){
	scanf("%d", &n); m = (1 << n);
	vector<pair<int, int> > vec;
	for(int i = 0; i <= n; ++i) inv[i] = qpow(i, INF - 2);
	for(int S = 0; S < m; ++S) cnte[S] = 1, pop[S] = __builtin_popcount(S);
	
	int cnte2 = 1;
	
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){
		scanf("%d", &w[i][j]);
		if(i < j && w[i][j]){
			vec.push_back(make_pair(i, j));
			cnte2 = 2ll * cnte2 % INF;
		}
	}
	sort(vec.begin(), vec.end(), [&](const pair<int, int> &ths, const pair<int, int> &oth){ return make_pair(w[ths.first][ths.second], ths) < make_pair(w[oth.first][oth.second], oth); });
	
	for(int i = 0; i < vec.size(); ++i){
		int u = vec[i].first, v = vec[i].second;
		cnte2 = 1ll * cnte2 * inv2 % INF;
		recalc();
		int res = 0;
		for(int S = 0; S < m; ++S) if((S >> u & 1) && (S >> v & 1))
			res = (res + 1ll * G[pop[S]][S] * cnte[((1 << n) - 1) ^ S]) % INF;
		res = (cnte[(1 << n) - 1] + INF - res) % INF;
		ans = (ans + 1ll * res * cnte2 % INF * w[u][v]) % INF;
		for(int S = 0; S < m; ++S) if((S >> u & 1) && (S >> v & 1))
			cnte[S] = 2ll * cnte[S] % INF;
	}
	
	printf("%d\n", ans);
	return 0;
}
