//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
#define PI acos(-1)

const LL maxn = 1e7+5;
#define cp complex<double>

LL r[maxn];
cp a[maxn], b[maxn];

void fft(cp a[], LL n, LL inv) {
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        cp wi(cos(PI/mid), inv*sin(PI/mid));
        for(LL i=0; i<n; i+=mid<<1) {
            cp wn(1,0);
            for(LL j=0; j<mid; j++,wn=wn*wi) {
                cp x=a[i+j], y=wn*a[i+j+mid];
                a[i+j]=x+y, a[i+j+mid]=x-y;
            }
        }
    }
}

LL invert(LL x) {
    LL bit = 1;
    while((1<<bit)<x) bit++;
    return (1<<bit);
}

int main() {
    freopen("data.txt","r",stdin);
    LL n, m, t;
    cin>>n>>m; t=invert(n+m);
    // for(int i=0; i<=n; i++) cin>>a[i].x;
    // for(int i=0; i<=m; i++) cin>>b[i].x;
    for(int i=0; i<=n; i++) {
        double x; cin>>x;
        a[i].real(x);
    }
    for(int i=0; i<=m; i++) {
        double x; cin>>x;
        b[i].real(x);
    }
    fft(a, t, 1);
    fft(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i];
    fft(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<(int)(a[i].real()/t+0.5)<<" ";
    // for(int i=0; i<=n+m; i++) cout<<(int)(a[i].x/t+0.5)<<" ";
    return 0;
}