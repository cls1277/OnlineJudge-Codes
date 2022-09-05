#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long

double m[4][5];
double a[4][5] = {
    1, 1, 0.8, 0.5, 0,
    2, 2, 1.6, 1.0, 0,
    3, 3, 2.4, 1.5, 0,
    5, 5, 2.5, 2, 0
};
double brow[5] = {1, 0.5, 0.4, 0.3, 0};

signed main()
{
    // cin.tie(nullptr)->sync_with_stdio(false); 
    double A = 0, A0 = 0, B = 0, B0 = 0;   
    for (int i = 0; i < 4; i++) {
        double cnt = 0;
        for (int j = 0; j < 5; j++) {
            // cin >> m[i][j];
            scanf("%lf", &m[i][j]);
            A0 += a[i][j] * m[i][j];
            cnt += m[i][j];
        }
        A += cnt * a[i][0];
    }
    double cnt = 0;
    for (int j = 0; j < 5; j++) {
        B0 += m[3][j] * brow[j];
        cnt += m[3][j];
    }
    B = cnt * brow[0];
    printf("%.12lf\n", A0/A*100+B0/B);
    return 0;
}