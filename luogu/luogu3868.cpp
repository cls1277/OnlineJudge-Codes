//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 15;
LL m[maxn], f[maxn], M, ans;

LL qmul(LL a, LL b, LL mod) {
    return ((a*b-(long long)((long double)a*b/mod)*mod+mod)%mod);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b,a%b,x,y);
    LL k=x;
    x=y;
    y=k-a/b*y;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n; cin>>n; M=1;
    Fo(i,1,n) cin>>f[i];
    Fo(i,1,n) cin>>m[i],M*=m[i];
    Fo(i,1,n) {
        LL Mi=M/m[i] , inv , z;
        exgcd(Mi,m[i],inv,z);
        ans=(ans+qmul(qmul(Mi,inv,M),f[i],M))%M;
    }
    ans=(ans+M)%M;
    cout<<ans;
    return 0;
}