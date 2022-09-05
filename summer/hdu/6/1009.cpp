#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline void getabc(int xA, int yA, int xB, int yB, int xa, int ya, int xb, int yb, int& a, int& b, int& c)
{
    int K = (xB - xA) * (xB - xA) + (yB - yA) * (yB - yA);
    int k = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    a = k * (xB - xA) - K * (xb - xa);
    b = k * (yB - yA) - K * (yb - ya);
    c = k * (xA * (xB - xA) + yA * (yB - yA)) - K * (xa * (xb - xa) + ya * (yb - ya));
    // printf("a=%lld\tb=%lld\tc=%lld\tK=%lld\tk=%lld\n", a, b, c, K, k);
}

void solve()
{
    int xA, yA, xB, yB, xC, yC, xD, yD, xa, ya, xb, yb, xc, yc, xd, yd;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD, &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
    int a1, b1, c1, a2, b2, c2;
    getabc(xA, yA, xB, yB, xa, ya, xb, yb, a1, b1, c1);
    getabc(xA, yA, xD, yD, xa, ya, xd, yd, a2, b2, c2);
    double x = 1.0 * (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    double y = 1.0 * (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    printf("%.16lf %.16lf\n", x, y);
}

signed main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    scanf("%lld", &T);
    while (T--) {
        solve();
    }
    return 0;
}
