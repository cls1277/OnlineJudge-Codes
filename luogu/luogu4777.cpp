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
LL n, m[maxn], a[maxn];

inline LL qmul(LL a, LL b, LL p) {
    LL ans = 0;
    while(b>0) {
        if(b&1) ans = (ans+a)%p;
        a = a*2%p;
        b>>=1;
    }
    return ans;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b, a%b, x, y);
    LL k = x; x = y;
    y = k-a/b*y;
    return d;
}

LL exCRT() {
    LL M=m[1], ans=a[1];
    Fo(i,2,n) {
        LL x, y;
        LL gcd = exgcd(M, m[i], x, y);
        LL c = ((a[i]-ans)%m[i]+m[i])%m[i];
        if(c%gcd) return -1;
        LL d = m[i]/gcd;
        x = qmul(x, c/gcd, d);
        ans += x*M;
        M *= d;
        ans = (ans%M+M)%M;
    }
    return (ans%M+M)%M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>m[i]>>a[i];
    cout<<exCRT();
    return 0;
}
