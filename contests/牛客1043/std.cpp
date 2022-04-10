#include <bits/stdc++.h>

using namespace std;
const int N = 110, inf = 0x3f3f3f3f;
int dp[N][N][2];
char op[N];
int a[N];

int cal(int a, int b, char c)
{
    if (c == 'x') return a * b;
    else return a + b;
}

int main()
{
    freopen("data.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> op[i] >> a[i];
        op[i + n] = op[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 1; j <= n * 2; j++) {
            dp[i][j][1] = -inf;
            dp[i][j][0] = inf;
        }
    for (int len = 0; len < n; len++) {
        for (int l = 0; l + len < 2 * n; l++) {
            int r = l + len;
            if (l == r) dp[l][r][0] = dp[l][r][1] = a[l];
            else {
                for (int k = l; k < r; k++) {
                    for (int a = 0; a <= 1; a++)
                        for (int b = 0; b <= 1; b++) {
                            dp[l][r][1] = max(dp[l][r][1], cal(dp[l][k][a], dp[k + 1][r][b], op[k + 1]));
                            dp[l][r][0] = min(dp[l][r][0], cal(dp[l][k][a], dp[k + 1][r][b], op[k + 1]));
                        }
                }
            }
        }
    }
    
    int mx = -inf;
    for (int l = 0; l < n; l++) {
        mx = max(mx, dp[l][l + n - 1][1]);
    }
    cout << mx << endl;
    for (int l = 0; l < n; l++) {
        if (dp[l][l + n - 1][1] == mx)
            cout << l + 1 << " ";
    }
    cout << endl;
    return 0;
}