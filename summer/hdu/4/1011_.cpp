#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

int p[60];

inline void insert(long long x) {
  for (int i = 55; i + 1; i--) {
    if (!(x >> i))  // x的第i位是0
      continue;
    if (!p[i]) {
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
}

// const int maxn = 1e5+5;
// int a[maxn];
// int s[maxn];

void solve() {
    int n = read();
    // s[0] = a[0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     s[i] = s[i-1] ^ (a[i] = read());
    // }
    // int ans = s[n];
    // for (int i = 1; i < n; i++) {
    //     if (s[i] == (s[i]^s[n])) {
    //         ans = max(ans, s[i]);
    //     }
    // }
    memset(p, 0, sizeof p);
    for (int i = 0; i < n; i++) {
        insert(read());
    }
    int ans = 0;
    	for(int i = 59; i >= 0; i--)
		if((ans ^ p[i]) > ans)
			ans ^= p[i];
    cout << ans << endl;
}

signed main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);    
	int T = read();
    while (T--) {
        solve();
    }
    return 0;
}