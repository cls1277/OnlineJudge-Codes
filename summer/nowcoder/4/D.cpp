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
const int mod = 998244353;

inline int binpow(int a, int q) {
    a %= mod;
    q %= mod;
    int res = 1;
    while (q) {
        if (q&1) {
            res = (res * a) % mod;
        }
        q >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}

struct Section {
    int m;
    bitset<404> bs[404][404];
    // int A[404];
    // int B[404];
    // int C[404];
    // int AB[404][404];
    // int BC[404][404];
    // int AC[404][404];
    Section() {
        m = 0;
        // memset(A, 0, sizeof A);
        // memset(B, 0, sizeof B);
        // memset(C, 0, sizeof C);
        // memset(AB, 0, sizeof AB);
        // memset(BC, 0, sizeof BC);
        // memset(AC, 0, sizeof AC);
    }
    void input() {
        m = read();
        for (int i = 0; i < m; i++) {
            int a = read();
            int b = read();
            int c = read();
            bs[a][b][c] = 1;
            // A[a]++;
            // B[b]++;
            // C[c]++;
            // AB[a][b]++;
            // BC[b][c]++;
            // AC[a][c]++;
        }
        // 计算一维前缀和
        // for (int i = 1; i <= 400; i++) {
        //     A[i] += A[i-1];
        //     B[i] += B[i-1];
        //     C[i] += C[i-1];
        // }
        // for (int i = 400; i >= 1; i--) {
        //     A[i] += A[i+1];
        //     B[i] += B[i+1];
        //     C[i] += C[i+1];
        // }
        // 计算二维前缀和
        // for (int i = 1; i <= 400; i++) {
        //     for (int j = 1; j <= 400; j++) {
        //         AB[i][j] += AB[i-1][j] + AB[i][j-1] - AB[i-1][j-1];
        //         BC[i][j] += BC[i-1][j] + BC[i][j-1] - BC[i-1][j-1];
        //         AC[i][j] += AC[i-1][j] + AC[i][j-1] - AC[i-1][j-1];
        //     }
        // }
        // for (int i = 400; i >= 1; i--) {
        //     for (int j = 400; j >= 1; j--) {
        //         AB[i][j] += AB[i+1][j] + AB[i][j+1] - AB[i+1][j+1];
        //         BC[i][j] += BC[i+1][j] + BC[i][j+1] - BC[i+1][j+1];
        //         AC[i][j] += AC[i+1][j] + AC[i][j+1] - AC[i+1][j+1];
        //     }
        // }
        // 计算三维前缀和
        for (int i = 1; i <= 400; i++) {
            for (int j = 1; j <= 400; j++) {
                for (int k = 1; k <= 400; k++) {
                    bs[i][j][k] = (bs[i][j][k] | bs[i-1][j][k] | bs[i][j-1][k] | bs[i][j][k-1]);
                }
//                cout<<"0";
            }
//            cout<<"1";
        }
//        cout<<"2";
    }
    int test(int a, int b, int c) {
        // printf("%lld %lld %lld %lld %lld %lld\n", A[a], B[b], C[c], AB[a][b], BC[b][c], AC[a][c]);
        // return m - (A[a] + B[b] + C[c] - AB[a][b] - BC[b][c] - AC[a][c]) ? 1 : 0;
        // return m - (A[a+1] + B[b+1] + C[c+1] - AB[a+1][b+1] - BC[b+1][c+1] - AC[a+1][c+1]) ? 1 : 0;
        return bs[a][b][c] ? 1 : 0;
    }
} s[15];
int n;

int solve(int IQ, int EQ, int AQ) {
    // printf("%lld %lld %lld\n", IQ, EQ, AQ);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i].test(IQ, EQ, AQ);
    }
    return ans;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin.tie(nullptr)->sync_with_stdio(false);    
	n = read();
    int q = read();
    for (int i = 0; i < n; i++) {
        s[i].input();
    }
    int seed = read();
    mt19937 rng(seed);
    uniform_int_distribution<int> u(1, 400);
    int lastans = 0;
    int ans = 0;
    int fa = binpow(seed, q);
    int seed_ = binpow(seed, mod-2);
    for (int i = 1; i <= q; i++) {
        int IQ = (u(rng)^lastans)%400+1;
        int EQ = (u(rng)^lastans)%400+1;
        int AQ = (u(rng)^lastans)%400+1;
        lastans = solve(IQ, EQ, AQ);
        fa = (fa * seed_) % mod;
        ans = (ans + lastans * fa) % mod;
        // printf("%lld\n", solve(1,1,1));
    }
    printf("%lld\n", ans);
    return 0;
}
