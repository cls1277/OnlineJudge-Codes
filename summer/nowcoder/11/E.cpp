#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e3+3;
int a[maxn][maxn];

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);    
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= p-1; i++) {
        cout << a[i][i] << " ";
    }
    for (int i = 1; i <= n-p+1; i++) {
        cout << "0 ";
    }
    cout << endl;
    return 0;
}
