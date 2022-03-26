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

const LL maxn = 1e7+5;
LL r[maxn];//记得放到外面
LL a[maxn], b[maxn];//记得放到外面
const LL mod = 998244353;
#define g 3

inline LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

void ntt(LL a[], LL n, LL inv) {
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        LL gi=qpow(g, (mod-1)/(mid<<1), mod);
        if(inv==-1) gi=qpow(gi, mod-2, mod);
        for(LL i=0; i<n; i+=mid<<1) {
            LL gn = 1;
            for(LL j=0; j<mid; j++,gn=gn*gi%mod) {
                LL x=a[i+j], y=gn*a[i+j+mid]%mod;
                a[i+j]=(x+y)%mod; a[i+j+mid]=(x-y+mod)%mod;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n, m, t; 
    cin>>n>>m; t=invert(n+m);
    for(int i=0; i<=n; i++) cin>>a[i];
    for(int i=0; i<=m; i++) cin>>b[i];
    ntt(a, t, 1);
    ntt(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i]%mod;
    ntt(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<a[i]*qpow(t, mod-2, mod)%mod<<" ";
    return 0;
}