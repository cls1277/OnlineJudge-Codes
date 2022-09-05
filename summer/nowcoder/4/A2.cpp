//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m;
double f[maxn][25];

struct Node {
    LL w;
    double p;
}a[maxn];

bool operator < (const Node &x, const Node &y) {
    return (x.w+y.w*x.p>=y.w+x.w*y.p);
}

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    n=read(); m=read(); // cin>>n>>m;
    Fo(i,1,n) a[i].w=read(); //cin>>a[i].w;
    Fo(i,1,n) {
        LL x; x=read(); //cin>>x;
        a[i].p = x*1.0/10000;
    }
    sort(a+1, a+n+1);
    Ro(i,n,1) {
        Fo(j,1,m) {
            f[i][j] = max(f[i+1][j], f[i+1][j-1]*a[i].p+a[i].w);
        }
    }
    printf("%.16lf",f[1][m]);
    return 0;
}