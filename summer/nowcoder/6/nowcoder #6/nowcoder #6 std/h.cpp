#include <bits/stdc++.h>
using namespace std;

namespace IO {
	char buf[1 << 25], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2) ? EOF : *p1++)
	inline int read() {
		int x = 0, sgn = 0;
		char s = getchar();
		while(!isdigit(s)) sgn |= s == '-', s = getchar();
		while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
		return sgn ? -x : x;
	}
}

const int B = 1 << 17;
const int N = 3e6 + 5;
const int mod = 1e9 + 7;
int n, m, s, p[N], answer;

struct power {
	int p_small[B + 1], p_large[B + 1];
	void init(int x) {
		p_small[0] = p_large[0] = 1;
		for(int i = 1; i <= B; i++) p_small[i] = 1ll * p_small[i - 1] * x % mod;
		for(int i = 1; i <= B; i++) p_large[i] = 1ll * p_large[i - 1] * p_small[B] % mod;
	}
	int query(int b) {return 1ll * p_small[b & (B - 1)] * p_large[b >> 17] % mod;}
} _2, _inv2;
int query(int b) {return b < 0 ? _inv2.query(-b) : _2.query(b);}

int D(int c) {return 1ll * query(n - m - 1 - c) * (3ll * c * query(c) % mod + mod - 13ll * query(c) % mod + 1ll * c * c % mod + 6ll * c % mod + 13) % mod;}
int E(int c) {return (1ll * (mod - c) * (c + 4) + 6ll * (query(c) - 1)) % mod * query(-c) % mod;}

int fl1, fl2, fl3, fr1, fr2, fr3;
int a1(int x) {return (1ll * query(x) * (2ll * x * x % mod + mod - 4ll * x % mod + 6) + mod - 6) % mod;}
int a2(int x) {return (1ll * query(x) * (4ll * x + mod - 4) + 4) % mod;}
int a3(int x) {return (2ll * query(x) + mod - 2) % mod;}
int b1(int y) {return (1 + mod - query(-y)) % mod;}
int b2(int y) {return (2 + mod - 1ll * query(-y) * y % mod + mod - query(-y + 1)) % mod;}
int b3(int y) {return (6 + mod - 1ll * query(-y) * (6 + 4ll * y + 1ll * y * y % mod) % mod) % mod;}
void modify(int l, int r, int coef) {
	fl1 = (fl1 + 1ll * coef * a1(l)) % mod, fl2 = (fl2 + 1ll * coef * a2(l)) % mod, fl3 = (fl3 + 1ll * coef * a3(l)) % mod;
	fr1 = (fr1 + 1ll * coef * a1(r)) % mod, fr2 = (fr2 + 1ll * coef * a2(r)) % mod, fr3 = (fr3 + 1ll * coef * a3(r)) % mod;
}
int main() {
	_2.init(2), _inv2.init(mod + 1 >> 1);
	cin >> n >> m >> s, p[m + 1] = n;
    assert(1<=n&&n<=1e9);
    assert(0<=s&&s<=m<<m<=2e6);
	for(int i = 1; i <= m; i++) p[i] = IO :: read();
	for(int i = 1; i <= m; i++) {
		modify(p[i - 1], p[i] - 1, query(-i));
		if(i > s) modify(p[i - s - 1], p[i - s] - 1, mod - query(s - i));
		int coef = 0;
		coef = (coef + 1ll * (fr1 + mod - fl1) * (b1(p[i + 1] - 1) + mod - b1(p[i]))) % mod;
		coef = (coef - 1ll * (fr2 + mod - fl2) * (b2(p[i + 1] - 1) + mod - b2(p[i]))) % mod;
		coef = (coef + 1ll * (fr3 + mod - fl3) * (b3(p[i + 1] - 1) + mod - b3(p[i]))) % mod;
		answer = (answer + 1ll * coef * query(i)) % mod;
	}
	answer = 1ll * answer * query(n - m - 1) % mod;
	for(int i = 1; i <= m + 1; i++) answer = (answer + D(p[i] - p[i - 1] - 1)) % mod;
	for(int i = 1; i <= s + 1; i++) answer = (answer + 1ll * query(n - 2 - m + i) * (E(p[i] - 1) + mod - E(p[i - 1]))) % mod;
	for(int i = 0; i <= m + 1; i++) p[i] = n - p[i];
	reverse(p, p + m + 2);
	for(int i = 1; i <= s + 1; i++) answer = (answer + 1ll * query(n - 2 - m + i) * (E(p[i] - 1) + mod - E(p[i - 1]))) % mod;
	if(m == s) answer = (answer + 1ll * n * n) % mod;
	cout << answer << endl;
	return 0;
}

