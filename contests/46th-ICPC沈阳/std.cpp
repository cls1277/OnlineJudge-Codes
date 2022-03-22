#include <bits/stdc++.h>
using namespace std;
int n, m, pa[111111], val[111111];
int x, y, z, rx, ry, num[111111][33], sum[111111];
long long ans;
bool flg;
int root(int x)
{
    if (pa[x] == x) return x;
    int rt = root(pa[x]);
    val[x] ^= val[pa[x]];
    pa[x] = rt;
    return rt;
}
void Union(int x, int y, int z)
{
    rx = root(x); ry = root(y);
    if (rx == ry)
    {
        if ((val[x] ^ val[y]) != z) flg = 1;
        return;
    }
    pa[rx] = ry;
    val[rx] = z ^ val[x] ^ val[y];
}
int main()
{
        freopen("data.txt","r",stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) pa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        Union(x, y, z);
    }
    if (flg)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        rx = root(i);
        sum[rx] ++;
        for (int j = 0; j < 30; j++)
        {
            if (val[i] & (1 << j)) num[rx][j] ++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (sum[i])
        {
            for (int j = 0 ; j < 30; j++)
            {
                ans += (1ll * min(num[i][j], sum[i] - num[i][j]) * (1ll << j));
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}