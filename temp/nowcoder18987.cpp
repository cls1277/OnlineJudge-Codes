// By cls1277
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i, a, b) for (LL i = (a); i <= (b); i++)
#define Ro(i, b, a) for (LL i = (b); i >= (a); i--)
#define Eo(i, x, _) for (LL i = head[x]; i; i = _[i].next)
#define Ms(a, b) memset((a), (b), sizeof(a))
#define lowbit(_) _ &(-_)
#define mk(_, __) make_pair(_, __)
#define pii pair<int, int>
#define ls x << 1
#define rs x << 1 | 1
#define endl '\n'
inline LL read()
{
    LL x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL mod = 998244353;
struct Mat
{
    LL data[3][3];
    Mat()
    {
        Ms(data, 0);
    }
    void eye()
    {
        data[0][0] = data[1][1] = 1;
    }
    void A()
    {
        data[0][1] = data[0][0] = data[1][0] = 1;
        data[1][1] = 0;
    }
    Mat operator*(const Mat &b)
    {
        Mat res;
        Fo(i, 0, 1)
            Fo(j, 0, 1)
                Fo(k, 0, 1)
                    res.data[i][j] = (res.data[i][j] + data[i][k] * b.data[k][j] % mod) % mod;
        return res;
    }
    Mat pow(int b)
    {
        Mat res, a = *this;
        res.eye();
        while (b)
        {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    void print()
    {
        Fo(i, 0, 1)
        {
            Fo(j, 0, 1)
                    cout
                << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("data.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    Mat x, y;
    x.A();
    y.data[0][0] = 1;
    // x.print();
    // x.pow(4).print();
    // cout << (x.pow(n) * y).data[0][0];
    Fo(i, 0, 10)
            cout
        << i << ":" << (x.pow(i) * y).data[0][0] << endl;
    return 0;
}