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

const int maxn = 1e5+5;
int cnt[20];


__int128_t gcd(__int128_t a, __int128_t b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void print(__int128_t x) {
    if (x > 9) print(x/10);
    putchar('0'+x%10);
}


inline void add(int n) {
    for (int i = 0; n; i++,n>>=1) {
        if (n&1) {
            cnt[i]++;
        }
    }
}

inline int get() {
    int res = 0;
    for (int i = 15; i >= 0; i--) {
        res <<= 1;
        if (cnt[i]) {
            res |= 1;
            cnt[i]--;
        }
    }
    return res;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin.tie(nullptr)->sync_with_stdio(false);    
    memset(cnt, 0, sizeof cnt);
    int n = read();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t = read();
        add(t);
        sum += t;
    }
    __int128_t fz = 0;
    __int128_t fm = n*n*n;
    for (int i = 0; i < n; i++) {
        __int128_t t = n*get()-sum;
        // printf("%lld ", t);
        fz += t*t;
    }
    // printf("\n");
    if (fz == 0) {
        fm = 1;
    } else {
        __int128_t g = gcd(fz, fm);
        fz /= g;
        fm /= g;
    }
    // printf("%lld/%lld\n", (int)fz, (int)fm);
    print(fz);
    putchar('/');
    print(fm);
    return 0;
}