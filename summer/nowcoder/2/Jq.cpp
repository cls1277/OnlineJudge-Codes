//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

namespace GTI
{
    char gc(void)
       {
        const int S = 1 << 16;
        static char buf[S], *s = buf, *t = buf;
        if (s == t) t = buf + fread(s = buf, 1, S, stdin);
        if (s == t) return EOF;
        return *s++;
    }
    int gti(void)
       {
        int a = 0, b = 1, c = gc();
        for (; !isdigit(c); c = gc()) b ^= (c == '-');
        for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
        return b ? a : -a;
    }
}
using GTI::gti;

const LL maxn = 1e5+5;
LL n, a[maxn], d[maxn];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=gti();
    while(t--) {
        n = gti();
        double sum = 0;
        Fo(i,1,n) {
            a[i] = gti();
            sum += a[i];
        }
        double k=(n-1)*1.0/2, c=sum*1.0/n;
        double b = 0, d = 0;
        Fo(i,1,n) {
            b += (c-a[i])*(k-(i-1));
            d += (k-(i-1))*(k-(i-1));
        }
        double x = b/d;
        double y = c-k*x;
        double ans = 0;
        Fo(i,1,n) {
            ans += (a[i]-(y+(i-1)*x))*(a[i]-(y+(i-1)*x));
        }
        printf("%.15lf\n",ans);
    }
    return 0;
}