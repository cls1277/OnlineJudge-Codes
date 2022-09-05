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
LL n, q;
struct Node {
    LL x, y, w;
}a[maxn];
LL b[maxn];

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL f[4][maxn]; //0:x+y 1:x-y 2:-x+y 3:-x-y

bool operator < (const Node&x, const Node&y) {
    return x.w<y.w;
}

bool judge(LL x, LL y, LL w) {
    LL idx = lower_bound(b+1, b+n+1, w)-b;
    LL d = max({x+y+f[3][idx], x-y+f[2][idx], -x+y+f[1][idx], -x-y+f[0][idx]});
    return (d>=w);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    LL t; scanf("%lld",&t); //t=read(); //cin>>t;
    while(t--) {
        scanf("%lld%lld",&n,&q);
        // n=read(); q=read(); //cin>>n>>q;
        Fo(i,1,n) {
            // a[i].x = read();
            // a[i].y = read();
            // a[i].w = read();
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
        }
        //cin>>a[i].x>>a[i].y>>a[i].w;
        sort(a+1, a+n+1);
        Fo(i,1,n) {
            b[i] = a[i].w;
            f[0][i] = f[1][i] = f[2][i] = f[3][i] = 0;
        }
        f[0][n] = a[n].x+a[n].y;
        f[1][n] = a[n].x-a[n].y;
        f[2][n] = -a[n].x+a[n].y;
        f[3][n] = -a[n].x-a[n].y;
        Ro(i,n-1,1) {
            f[0][i] = max(f[0][i+1], a[i].x+a[i].y);
            f[1][i] = max(f[1][i+1], a[i].x-a[i].y);
            f[2][i] = max(f[2][i+1], -a[i].x+a[i].y);
            f[3][i] = max(f[3][i+1], -a[i].x-a[i].y);            
        }
        while(q--) {
            LL _x, _y; scanf("%lld%lld", &_x, &_y); // _x=read(); _y=read(); //cin>>_x>>_y;
            LL l=0, r=a[n].w;
            while(l<r) {
                LL mid=(l+r+1)>>1;
                if(judge(_x, _y, mid)) l = mid;
                else r = mid-1;
            }
            // cout<<l<<endl;
            printf("%lld\n",l);
        }
    }
    return 0;
}