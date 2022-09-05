#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);    
    int n;
    scanf("%lld", &n);
    int row = 4*n+5;
    int col = 13*n+19;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <=col; j++) {
            if (i == 1 || i == row || j == 1 || j == col) {
                putchar('*');
            } else if (i >= n + 2 && i <= 3*n+4 && j >= n + 3 && j <= 3*n+5) {
                // putchar('n');
                if (j == n+3 || j == 3*n+5 || j - i == 1) {
                    putchar('@');
                } else {
                    putchar('.');
                }
            } else if (i >= n + 2 && i <= 3*n+4 && j >= 4*n+7 && j <= 6*n+9) {
                // putchar('f');
                if (i == n+2 || i == 2*n+3 || j == 4*n+7) {
                    putchar('@');
                } else {
                    putchar('.');
                }
            } else if (i >= n + 2 && i <= 3*n+4 && j >= 7*n+11 && j <= 9*n+13) {
                // putchar('l');
                if (i == 3*n+4 || j == 7*n+11) {
                    putchar('@');
                } else {
                    putchar('.');
                }
            } else if (i >= n + 2 && i <= 3*n+4 && j >= 10*n+15 && j <= 12*n+17) {
                // putchar('s');
                if (i == n+2 || i == 2*n+3 || i == 3*n+4 || i <= 2*n+3 && j == 10*n+15 || i >= 2*n+3 && j == 12*n+17) {
                    putchar('@');
                } else {
                    putchar('.');
                }
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
    return 0;
}